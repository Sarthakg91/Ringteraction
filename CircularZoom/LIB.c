#include <stdio.h>
#include <stdlib.h>
#include <p32xxxx.h>                // Processor defs
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>


//#=================================================================================================
//# Delayus
//#-------------------------------------------------------------------------------------------------
void Delayus(unsigned int t)
{
    unsigned int CalT;
    WriteCoreTimer(0);
    CalT = t * 40;

    while ( (unsigned int)(ReadCoreTimer()) < CalT ) {};
} //Delayus
//#=================================================================================================
//# Delayms
//#-------------------------------------------------------------------------------------------------
void Delayms(unsigned int t)
{
    unsigned int T = 0;
    while ( (T++) < t )
    {
        Delayus(999);
    }
} //Delayms
//#=================================================================================================

#define SYS_FREQ 		(80000000L)
//#define SYS_FREQ 		(100000000L)
#define GetSystemClock()        (80000000L)
#define	GetPeripheralClock()	(GetSystemClock()/(1 << OSCCONbits.PBDIV))
//#define	GetInstructionClock()	(GetSystemClock())



//#=================================================================================================
// COMM1_Tx : 9D0025B8
//#=================================================================================================
//#-------------------------------------------------------------------------------------------------
void COMM1_Tx(unsigned int d)
{
    while( U1STAbits.UTXBF);
    putcUART1(d);
}
//#=================================================================================================
// COMM1_Tx_Str : 9D002614
//#-------------------------------------------------------------------------------------------------
void COMM1_Tx_Str(unsigned char *str)
{
    while ((*str) != '\0')
    {
        COMM1_Tx(*str );
        *(str++);
    }
}

//-----------------------------------------------==================================================
// XCode2Dat
//-----------------------------------------------==================================================
const char dig[16] =
//const __attribute__((section("XCode2Dat"))) char dig[] =
        "0123456789"
        "ABCDEF";
//-----------------------------------------------==================================================
/* The Itoa code is in the puiblic domain */
void Math_Itoa(int value, char* str, int radix)
{
//    static char dig[] =
//        "0123456789"
//        "ABCEDF";
    int n = 0, neg = 0;
    unsigned int v;
    char* p, *q;
    char c;
    if (radix == 10 && value < 0) {
        value = -value;
        neg = 1;
    }
    v = value;
    do {
        str[n++] = dig[v%radix];
        v /= radix;
    } while (v);
    if (neg)
        str[n++] = '-';
    str[n] = '\0';

    //for (p = str, q = p + n/2; p != q; ++p, --q)
    //    c = *p, *p = *q, *q = c;
	//now we need to reverse res
	for(v = 0; v < n/2; ++v)
	{
	   c = str[v]; str[v] = str[n-v-1]; str[n-v-1] = c;
	}
}
//-----------------------------------------------==================================================
void DebugPrint_Dec(int x)
{
    unsigned char OS_Str_1[32];

    Math_Itoa(x,OS_Str_1,10);
    COMM1_Tx_Str(OS_Str_1);
}
//-----------------------------------------------==================================================
void DebugPrint_Hex(int x)
{
    unsigned char OS_Str_1[32];

    Math_Itoa(x,OS_Str_1,16);
    COMM1_Tx_Str(OS_Str_1);
}
void DebugPrint_CR( void )
{
    COMM1_Tx(13);
}
void DebugPrint_Space( void )
{
    COMM1_Tx(' ');
}
void DebugPrint_Char( char c )
{
    COMM1_Tx(c);
}
//-----------------------------------------------==================================================
//#-------------------------------------------------------------------------------------------------
void COMM2_Tx(unsigned int d)
{
    while( U2STAbits.UTXBF);
    putcUART2(d);
}
void COMM2_Tx_Str(unsigned char *str)
{
    while ((*str) != '\0')
    {
        COMM2_Tx(*str );
        *(str++);
    }
}
void COMM2Print_Dec(int x)
{
    unsigned char OS_Str_1[32];

    Math_Itoa(x,OS_Str_1,10);
    COMM2_Tx_Str(OS_Str_1);
}
void COMM2Print_Hex(int x)
{
    unsigned char OS_Str_1[32];

    Math_Itoa(x,OS_Str_1,16);
    COMM2_Tx_Str(OS_Str_1);
}
void COMM2Print_CR( void )
{
    COMM2_Tx(13);
}
void COMM2Print_Space( void )
{
    COMM2_Tx(' ');
}
//-----------------------------------------------==================================================
//-----------------------------------------------==================================================
//#=================================================================================================





//#=================================================================================================
// SPI
//#=================================================================================================
int SPI1_Write_8( int i)
{
    SPI1BUF = i;                  // write to buffer for TX
    while( !SPI1STATbits.SPIRBF); // wait for transfer complete

    //INTClearFlag(INT_SPI1);
    SPI1STATCLR = 0x40;  // clear Overflow bit

    return SPI1BUF;               // read the received value
}//SPI1_Write_8
//#-------------------------------------------------------------------------------------------------
int SPI1_Init( void )
{
    _TRISB3 = 1; //SDI
    _TRISB1 = 0;  //SDO
    _TRISD2 = 0;  //SCK
//    SDI1Rbits.SDI1R = 0b011; //0b011; //SET SDI to RPB11 > PIN 24
//    RPB6Rbits.RPB6R = 0B011; //SET RPB6R to SDO > PIN 26

    SDI1Rbits.SDI1R = 0B1000; //0b011; //SET SDI to RPB3 > 1000 = RPB3
    RPB1Rbits.RPB1R = 0B1000; //SET RPB1R to SDO > 1000 = SDO1

    int rData = SPI1BUF;

    SPI1STATCLR = 0x40;
    //SpiChnOpen(1, SPI_CON_MODE8 |SPI_OPEN_MSTEN|SPI_OPEN_MODE8, 1024);
    SPI1CON = 0x8120 ;
    SPI1BRG = 20; //0 - FAST : 256 - SLOW
    SPI1STATCLR = 0x40;

    SPI1CONbits.SMP = 0; //0;
    SPI1CONbits.CKE = 1; //1;

    //SPI1CONbits.SMP = 0; //0;
    //SPI1CONbits.CKE = 0; //1;

    return SPI1BUF;               // read the received value
}//SPI1_Init
//#-------------------------------------------------------------------------------------------------





#define I2C_CLOCK_FREQ              5000
#define EEPROM_I2C_BUS              I2C1
//#define EEPROM_ADDRESS              0x50        // 0b1010000 Serial EEPROM address

#define Fsck	10000
#define BRG_VAL 	((SYS_FREQ/2/Fsck)-2)
//==============================================================================
void i2c_Init( void )
{
//    I2C1BRG = 0X017; //100KHz
//    I2C1BRG = 0X080; //100KHz
//    I2C1CON = 0X9000; //I2C1CON.ON = 1
	// Enable the I2C module with clock stretching enabled
//	OpenI2C1(I2C_ON | I2C_7BIT_ADD , BRG_VAL);
//mI2C1SClearIntFlag();

    //I2CSetFrequency(EEPROM_I2C_BUS, GetPeripheralClock(), I2C_CLOCK_FREQ);
    OpenI2C1( I2C_EN, BRG_VAL );

    //    OpenI2C1( I2C_EN, 0X80 );

}
//==============================================================================
BOOL i2c_Start(UINT8 restart )
{
    /*
    I2C_STATUS  status;
    int xxx;
putsUART1("[ss:");
    // Send the Start (or Restart) signal
    if(restart == 1)
    {
        //I2CRepeatStart(EEPROM_I2C_BUS);
        I2C1CONbits.RSEN = 1;
    }
    else
    {
        //xxx = I2C1STATbits.S;
        // Wait for the bus to be idle, then start the transfer
        while( !I2CBusIsIdle(EEPROM_I2C_BUS) );
        I2C1CONbits.SEN = 1;
putsUART1("1");
        if(I2CStart(EEPROM_I2C_BUS) != I2C_SUCCESS)
        {
            putsUART1("Error: Bus collision during transfer Start\n");
            return FALSE;
        }
putsUART1("2");
    }

    // Wait for the signal to complete
    do
    {
        status = I2CGetStatus(EEPROM_I2C_BUS);
    } while ( !(status & I2C_START) );


    */


    I2C_STATUS  status;

    // Send the Start (or Restart) signal
    if(restart)
    {
        //I2CRepeatStart(EEPROM_I2C_BUS);
           I2C1CONbits.RSEN = 1;
    }
    else
    {
        // Wait for the bus to be idle, then start the transfer
        while( !I2CBusIsIdle(EEPROM_I2C_BUS) );

        if(I2CStart(EEPROM_I2C_BUS) != I2C_SUCCESS)
        {
            DBPRINTF("Error: Bus collision during transfer Start\n");
            return FALSE;
        }
    }
putsUART1("2");

    // Wait for the signal to complete
    do
    {
        status = I2CGetStatus(EEPROM_I2C_BUS);

    } while ( !(status & I2C_START) );

putsUART1("3]");


    return TRUE;
}
//==============================================================================
void i2c_Stop( void )
{
    I2C_STATUS  status;

    // Send the Stop signal
    I2CStop(EEPROM_I2C_BUS);

    // Wait for the signal to complete
    do
    {
        status = I2CGetStatus(EEPROM_I2C_BUS);

    } while ( !(status & I2C_STOP) );
}
//==============================================================================
BOOL i2c_Tx( UINT8 data )
{
putsUART1("[tx:");
    // Wait for the transmitter to be ready
    while(!I2CTransmitterIsReady(EEPROM_I2C_BUS));
    //while ( !I2C1STATbits.TBF ) ;
putsUART1("1");

    // Transmit the byte
    if(I2CSendByte(EEPROM_I2C_BUS, data) == I2C_MASTER_BUS_COLLISION)
    {
        putsUART1("Error: I2C Master Bus Collision\n");
        return FALSE;
    }
    //I2C1TRN = data;
putsUART1("2");

    // Wait for the transmission to finish
    while(!I2CTransmissionHasCompleted(EEPROM_I2C_BUS));
    //while ( I2C1STATbits.TRSTAT );
putsUART1("3]");

    return TRUE;
}
//==============================================================================
int i2c_Rx( int Nack )
{
    I2C1CONbits.RCEN = 1;

    while( !I2C1STATbits.RBF );

    if (Nack == 1)
    {
        I2C1CONbits.ACKDT = 1;
        I2C1CONbits.ACKEN = 1;
    }else
    {
        I2C1CONbits.ACKDT = 0;
        I2C1CONbits.ACKEN = 1;
    }

    if(I2CReceiverEnable(EEPROM_I2C_BUS, TRUE) == I2C_RECEIVE_OVERFLOW)
    {
        putsUART1("Error: I2C Receive Overflow\n");
        //Success = FALSE;
    ///    return -1;
    }
    else
    {
        int x;
        while(!I2CReceivedDataIsAvailable(EEPROM_I2C_BUS));
        x = I2CGetByte(EEPROM_I2C_BUS);

        while ( I2C1CONbits.ACKEN );

        return x;
    }
}
//==============================================================================
//==============================================================================


