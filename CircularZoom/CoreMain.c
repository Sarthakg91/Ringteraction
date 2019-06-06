/* 
 * File:   newmain.c
 * Author: MRush
 * Modified: Sarthak
 */

#include <stdio.h>
#include <stdlib.h>
#include <p32xxxx.h>                // Processor defs
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include <math.h>
//#include "HMain.h"

#include "Microchip\Include\GenericTypeDefs.h"
#include "mTouchConfig.h"
#include "HardwareProfile.h"
#include "peripheral\pps.h"
#include "mTouchCapLib\mTouchCapAPI.h"
#include "mTouchCapLib\mTouchCapLED.h"
#include "mTouchCapLib\mTouchCapAPP_DirectKeys.h"
//#include "SwitchCode.h"
#include "mTouchCapLib\mTouchCapStatus.h"
#include "Microchip\Include\TimeDelay.h"

#include "main.h"


// PIC32MX470F512H Configuration Bit Settings
// 'C' source line config statements
#pragma config FSRSSEL = PRIORITY_7     // Shadow Register Set Priority Select (SRS Priority 7)
#pragma config PMDL1WAY = ON            // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow only one reconfiguration)
#pragma config FUSBIDIO = OFF            // USB USID Selection (Controlled by the USB Module)
#pragma config FVBUSONIO = OFF           // USB VBUS ON Selection (Controlled by USB Module)

// DEVCFG2
#pragma config FPLLIDIV = DIV_2        // PLL Input Divider (12x Divider)
#pragma config FPLLMUL = MUL_20         // PLL Multiplier (24x Multiplier)
#pragma config UPLLIDIV = DIV_12        // USB PLL Input Divider (12x Divider)
#pragma config UPLLEN = OFF             // USB PLL Enable (Disabled and Bypassed)
#pragma config FPLLODIV = DIV_1       // System PLL Output Clock Divider (PLL Divide by 256)

// DEVCFG1
#pragma config FNOSC = PRIPLL //FRCPLL //FRCDIV           // Oscillator Selection Bits (Fast RC Osc w/Div-by-N (FRCDIV))
#pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enabled)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = HS            // Primary Oscillator Configuration (Primary osc disabled)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FPBDIV = DIV_1           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/8)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disable, FSCM Disabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable (Watchdog Timer is in Non-Window Mode)
#pragma config FWDTEN = OFF              // Watchdog Timer Enable (WDT Enabled)
#pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window Size is 25%)

// DEVCFG0
#pragma config DEBUG = OFF              // Background Debugger Enable (Debugger is Disabled)
#pragma config JTAGEN = OFF              // JTAG Enable (JTAG Port Enabled)
#pragma config ICESEL = ICS_PGx2        // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

//#define SYS_FREQ 		(80000000L)

unsigned int g_count;
UINT16 mapValue(UINT16,UINT16);// mapping the slider values into a linear scale
UINT16 prevMappedValue;
UINT16 printFlag=0;
UINT16 zoomStartFlag=0,zoomOutStartFlag=0;
void SendDataBuffer(const CHAR *buffer, UINT32 size);
extern volatile UINT8 EmTouchDataReady;//global indicating the reading of all channels finished

//#=================================================================================================
void mTouch_Main( void );

//#=================================================================================================
//#=================================================================================================
int main( void ) {
    int	pbClk;
    //pbClk = SYSTEMConfig(SYS_FREQ>>4, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    //pbClk = SYSTEMConfig(SYS_FREQ>>4, SYS_CFG_WAIT_STATES | SYS_CFG_PCACHE);
    //(DEBUG_JTAGPORT_OFF);
    SYSTEMConfigPerformance(SYS_FREQ);
    mJTAGPortEnable(DEBUG_JTAGPORT_OFF);
unsigned int i, Rx1;
Rx1 = 0; //0xFFFF;

    ANSELB = INIT_TRISB_VALUE;
    ANSELC = Rx1;
    ANSELD = Rx1;
    ANSELE = Rx1;
    ANSELF = Rx1;
    ANSELG = Rx1;
    //ANSELH = Rx1;

    PB_TRIS;
    LED_TRIS;
    JST1_1_TRIS_OUT;
    JST1_2_TRIS_OUT;

    //JST3_1_TRIS_OUT;
    //JST3_2_TRIS_OUT;

    JST4_1_TRIS_OUT;
    JST4_2_TRIS_OUT;

    //comm1
    U1RXRbits.U1RXR = 4; //SET RX to RPF1 :: 0100 = RPF1
    RPF0Rbits.RPF0R = 3; //SET RPF0 to TX :: 0100 = RPF1
    UARTSetDataRate(UART1, SYS_FREQ, 115200);
    U1MODE = UART_EN;
    U1STA = (UART_RX_ENABLE | UART_TX_ENABLE);

    INTEnableSystemMultiVectoredInt();



    unsigned int cc;
    SPI1_Init();
    Screen_Init();
    Screen_Fill(0);

    cc = 0xFFFF; //Color565(0, 0, 255);
    Screen_Draw_Line( 0,  0, 95,  0, cc);
    Screen_Draw_Line( 0,  0,  0, 63, cc);
    Screen_Draw_Line(95,  0, 95, 63, cc);
    Screen_Draw_Line( 0, 63, 95, 63, cc);

    cc = Color565(255, 0, 0);
    Screen_Print_Str(5,3, "NUS", cc);
    cc = Color565(0, 255, 0);
    Screen_Print_Str(5,13, "HCI", cc);
    cc = Color565(0, 0, 255);
    Screen_Print_Str(5,23, "TEST", cc);

    //mOLED_Draw_Circle(50, 35, 5, 0xffff);

    mTouch_Main();

    return (EXIT_SUCCESS);
}
//#=================================================================================================



//#=================================================================================================
void mTouch_Main( void )
{
//enum ST8S Switch1St8, Switch2St8, Switch3St8;
UINT16 CurrentButtonStatus  = 0,
       CurrentButtonAsserts = 0,
       SliderValue = 0;
UINT8 ButtonPressed;
UINT16 prevValue=20, prevButtonStatus=0;
prevMappedValue=1;


    unsigned int PV1, PV2;

   // DebugPrint_Hex(0XA15);DebugPrint_Space();
   // DebugPrint_CR();

    ANSELB = INIT_TRISB_VALUE;
        
    // Setup data structures for using Direct Keys
    mTouchCapApp_DirectKeys_Create();
    mTouchCapAPI_Init(); // Initialize mTouchCap before UART init

    //comm1
    U1RXRbits.U1RXR = 4; //SET RX to RPF1 :: 0100 = RPF1
    RPF0Rbits.RPF0R = 3; //SET RPF0 to TX :: 0100 = RPF1
    UARTSetDataRate(UART1, SYS_FREQ, 115200);
    U1MODE = UART_EN;
    U1STA = (UART_RX_ENABLE | UART_TX_ENABLE);

  //  putsUART1(">U1 : mTouch Init done\n");
    Delayms(800);

    // Start button measurements
    Set_ScanTimer_IE_Bit_State(ENABLE);  //Enable interrupt
    Set_ScanTimer_ON_Bit_State(ENABLE);  //Run timer

    //dummy values
    PV2 = 20;
    PV1 = 20;
// for circular panning.
//initiated only when you have moved from one button to another. And then is continued smooth.
//so intiate only when button status moves from 2 to 1
    while(1)
    {
        if( mTouchCapStatus_Check( &CurrentButtonStatus, &CurrentButtonAsserts, &SliderValue ) )
        {
            if((SliderValue>(prevValue+5)||SliderValue<(prevValue-5))&&zoomStartFlag==1)
        {      // zoomStartFlag is inititated when the user makes one big movement in the clockwise direction, like moving from one button to another

                UINT16 mappedValue=mapValue(SliderValue,CurrentButtonStatus);
                if(printFlag==1&&CurrentButtonStatus!=0)
                {
                            DebugPrint_Dec(mappedValue);

                            ButtonPressed=CurrentButtonStatus;
                            DebugPrint_Dec(ButtonPressed);
                            DebugPrint_Space();
                           
                }


              prevValue=SliderValue;

        }
            else  if((SliderValue>(prevValue+5)||SliderValue<(prevValue-5))&&zoomOutStartFlag==1)
        {
// zoomOutStartFlag indicates if a big movement has been done in the anticlockwise direcion, like moving from one button to another
                UINT16 mappedValue=mapValue(SliderValue,CurrentButtonStatus);
                if(printFlag==1&&CurrentButtonStatus!=0)
                {
                            DebugPrint_Dec(mappedValue);
                            ButtonPressed=CurrentButtonStatus;
                            DebugPrint_Dec(ButtonPressed);
                            DebugPrint_Char('#');
                         
                }


              prevValue=SliderValue;

        }

            if ((SliderValue < 3) & (CurrentButtonStatus == 0))
            {//nothing is being touched
                  zoomStartFlag=0;
                  prevButtonStatus=0;
                  zoomOutStartFlag=0;

                
            }else
            {
                if (CurrentButtonStatus == 8)
                {
                    if(prevButtonStatus==4)
                    { //means a movement from 4 to 8 is made, hence a zooming gesture is in progress
                        zoomStartFlag=1;
                        zoomOutStartFlag=0;
                    }
                    else if (prevButtonStatus==2)
                    { //means a movement from 2 to 8 is made, a zoom out gesture is in progress.
                      zoomStartFlag=0;
                      zoomOutStartFlag=1;
                    }
                    //mOLED_Draw_Circle(55, 12, 5, 0);
                    mOLED_Draw_Circle(70, 12, 5, 0);
                    mOLED_Draw_Circle(55, 25, 5, 0);
                    mOLED_Draw_Circle(70, 25, 5, 0);

                    mOLED_Draw_Circle(55, 12, 5, 0xFFFF);//drawing the bigger circle to indicate the button position

                    prevButtonStatus=CurrentButtonStatus;
                }else if (CurrentButtonStatus == 4)
                {

                     if(prevButtonStatus==1)
                     {  //movement from 1 to 4 indicates a zoom gesture is in progress
                         zoomStartFlag=1;
                         zoomOutStartFlag=0;
                     }
                    else if (prevButtonStatus==8)
                    {
                        zoomStartFlag=0;
                        zoomOutStartFlag=1;
                    }

                    mOLED_Draw_Circle(55, 12, 5, 0);
                    //mOLED_Draw_Circle(70, 12, 5, 0);
                    mOLED_Draw_Circle(55, 25, 5, 0);
                    mOLED_Draw_Circle(70, 25, 5, 0);

                    mOLED_Draw_Circle(70, 12, 5, 0xFFFF);
                    prevButtonStatus=CurrentButtonStatus;
                }else if (CurrentButtonStatus == 2)
                {


                     if(prevButtonStatus==4)
                     {
                           zoomStartFlag=1;
                          zoomOutStartFlag=0;
                     }
                    else if (prevButtonStatus==1)
                    { zoomStartFlag=0; 
                    zoomOutStartFlag=1;
                    }
                    prevButtonStatus=2;


                }else if (CurrentButtonStatus == 1)
                {

                        if(prevButtonStatus==2)
                        {  zoomStartFlag=1; zoomOutStartFlag=0;}
                        else if (prevButtonStatus==4)//should this be 8?
                        { zoomStartFlag=0; zoomOutStartFlag=1;}

                //if current button is 1, check if previous button status was 2 in that case zoom should be initiated
                    
//                    if(prevButtonStatus==2&&zoomStartFlag==0)
//                    {
//                        //start zoom whenever finger is lifted, stop zoom
//                        zoomStartFlag=1;
//
//                    }
                        prevButtonStatus=CurrentButtonStatus;
                    
                    
                }

                mOLED_Draw_Circle(85-PV1, 50, 3, 0);
                mOLED_Draw_Circle(85-PV2, 40, 3, 0);
                if (SliderValue > 0xA0)
                {
                    PV2 = ((SliderValue - 0XA0)>>1) + 20;
                    mOLED_Draw_Circle(85-PV2, 40, 3, 0X3FF);
                }else if (SliderValue < 0x50)
                {
                    PV1 = (SliderValue>>1) + 20;
                    mOLED_Draw_Circle(85-PV1, 50, 3, 0xFC00);
                }

            }

            EmTouchDataReady = 0;                       //Clear flag
            Set_ScanTimer_IE_Bit_State(ENABLE);     //Enable interrupt
            Set_ScanTimer_ON_Bit_State(ENABLE);     //Run timer
        }

    } //end while (1)
    
}

//#=================================================================================================
//#=================================================================================================
void mTouchCapApp_PortSetup(void)
{
    TRISB = INIT_TRISB_VALUE;
    PORTB = INIT_PORTB_VALUE;

   //necessary for standalone execution - disable JTAG
    DDPCONbits.JTAGEN = 0;

    CTMUCONbits.ON = 1;
    CTMUCONbits.IRNG = 0x3;
}
//#=================================================================================================


UINT16 mapValue(UINT16 value,UINT16 currentButton)
{ UINT16 mappedValue;
if(currentButton!=0)
{

    if( zoomStartFlag==1)
    {
    if((value<130)&&currentButton<4)
    {   //values 0 to 130 are mapped from 100 to 1, linearly
        //this is the the slider at the bottom, hence the mapping is reversed from the slider on the top
        mappedValue=(((130-value)*99)+130)/130;
        if(mappedValue>prevMappedValue)
        {
            printFlag=1;//once the zooming is started we will ignore the minor changes
            //for example the same finger position can give 99 or 100 ..once we reach 100 we wll not accept the 99 anymore while zooming
            //hence we check if mappedValue is greater than prevMappedValue
            //only when printFLag is 1 , we write data to the serial port
            //so buttons 1 and 2 are in one slider whose maximum value is 130

        }
        else printFlag=0;
        prevMappedValue=mappedValue;
        return prevMappedValue;

    }
    else if ((value<280&&value>150)&&currentButton>=4)
    {  
        mappedValue=(100*value+210*130-28000)/130;
          if(mappedValue>prevMappedValue)
            printFlag=1;
        else printFlag=0;
        prevMappedValue=mappedValue;
        return prevMappedValue;
    }
}
    
    else if (zoomOutStartFlag==1)
    {
        if((value<130)&&currentButton<4)
    {   //the values are mapped from 150-280 to 110-210
        mappedValue=(((130-value)*99)+130)/130;
        if(mappedValue<prevMappedValue)
        {
            printFlag=1;

        }
        else printFlag=0;
        prevMappedValue=mappedValue;
        return prevMappedValue;

    }
    else if ((value<280&&value>150)&&currentButton>=4)
    {  
        mappedValue=(((100*value)+(210*130))-28000)/130;
          if(mappedValue<prevMappedValue)
            printFlag=1;
        else printFlag=0;
        prevMappedValue=mappedValue;
        return prevMappedValue;
    }
    }
}
printFlag=0;
return prevMappedValue;
}




//#=================================================================================================
//#=================================================================================================


