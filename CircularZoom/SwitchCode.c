/*****************************************************************************
* FileName:         SwitchCode.c
*
* Includes:
*   enum ST8S CheckSwitch1(void)
*   enum ST8S CheckSwitch2(void)
*   enum ST8S CheckSwitch3(void)
*   void UpdateSwitch( INT16 iSwitch, enum ST8S SwitchSt8, char *SwitchLabel )
*
* Dependencies:     ??
* Processor:        PIC32
* Compiler:         C32
* Linker:           MPLAB LINK32
* Company:          Microchip Technology Incorporated
*
* Software License Agreement
*
* Copyright © 2011 Microchip Technology Inc.
* Microchip licenses this software to you solely for use with Microchip
* products, according to the terms of the accompanying click-wrap software
* license. Microchip and its licensors retain all right, title and interest in
* and to the software.  All rights reserved. This software and any accompanying
* information is for suggestion only. It shall not be deemed to modify
* Microchip’s standard warranty for its products.  It is your responsibility to
* ensure that this software meets your requirements.
*
* SOFTWARE IS PROVIDED “AS IS” WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR
* IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
* NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL
* MICROCHIP OR ITS LICENSORS BE LIABLE FOR ANY DIRECT OR INDIRECT DAMAGES OR
* EXPENSES INCLUDING BUT NOT LIMITED TO INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
* OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
* SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, OR ANY CLAIMS BY THIRD PARTIES
* (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*
* The aggregate and cumulative liability of Microchip and its licensors for
* damages related to the use of the software will in no event exceed $1000 or
* the amount you paid Microchip for the software, whichever is greater.
*
* MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
* TERMS AND THE TERMS OF THE ACCOMPANYING CLICK-WRAP SOFTWARE LICENSE.
*
*
* Author       Date        Comment
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* MWM          21 Jul 2011  Moved from main file to this file for simplicity
*******************************************************************************/

#include "Graphics.h"
#include "SwitchCode.h"
#include DISPLAY_FONT_HEADER

#define WAIT_UNTIL_FINISH(x)    while(!x)


enum ST8S CheckSwitch1(void)
{
    static enum ST8S Switch1St8;
    static unsigned short Switch1Cnt=SWITCH_DEBOUNCE_COUNT;
    if ( Switch1Cnt > 0 ) // continue debounce time out
    {
        Switch1Cnt++;
        Switch1Cnt = (Switch1Cnt > SWITCH_DEBOUNCE_COUNT) ? 0 : Switch1Cnt;
    }
    else // check switch
    {
        if ( (PORTA & PORT_BIT_09) == PORT_BIT_09 ) // switch open
        {
            Switch1St8 = OFF;
        }
        else // switch closed
        {
            Switch1St8 = ON;
        }
    }
    return Switch1St8;
}


enum ST8S CheckSwitch2(void)
{
    static enum ST8S Switch2St8;
    static unsigned short Switch2Cnt=SWITCH_DEBOUNCE_COUNT;
    if ( Switch2Cnt > 0 ) // continue debounce time out
    {
        Switch2Cnt++;
        Switch2Cnt = (Switch2Cnt > SWITCH_DEBOUNCE_COUNT) ? 0 : Switch2Cnt;
    }
    else // check switch
    {
        if ( (PORTB & PORT_BIT_04) == PORT_BIT_04 ) // switch open
        {
            Switch2St8 = OFF;
        }
        else // switch closed
        {
            Switch2St8 = ON;
            Switch2Cnt = 1; // start debounce time out
        }
    }
    return Switch2St8;
}


enum ST8S CheckSwitch3(void)
{
    static enum ST8S Switch3St8;
    static unsigned short Switch3Cnt=SWITCH_DEBOUNCE_COUNT;
    if ( Switch3Cnt > 0 ) // continue debounce time out
    {
        Switch3Cnt++;
        Switch3Cnt = (Switch3Cnt > SWITCH_DEBOUNCE_COUNT) ? 0 : Switch3Cnt;
    }
    else // check switch
    {
        if ( (PORTA & PORT_BIT_07) == PORT_BIT_07 ) // switch open
        {
            Switch3St8 = OFF;
        }
        else
        {
            Switch3St8 = ON;
            Switch3Cnt = 1; // start debounce time out
        }
    }
    return Switch3St8;

}


void UpdateSwitch( INT16 iSwitch, enum ST8S SwitchSt8, char *SwitchLabel )
{
    static enum ST8S OLDSwitchSt8s[3] = { ON, ON, ON }; // Startup value allows use of this

    if ( SwitchSt8 != OLDSwitchSt8s[iSwitch-1] )
    {
        OLDSwitchSt8s[iSwitch-1] = SwitchSt8;
        switch ( SwitchSt8 )
        {
            case OFF:
                SetColor(LIGHTGRAY);
                break;
            case ON:
                SetColor(BRIGHTGREEN);
                break;
        }//end switch ( SwitchSt8 )
        WAIT_UNTIL_FINISH(FillCircle(10,GetMaxY()-(22*iSwitch-12),8));
    }

    if ( SwitchLabel != 0 )
    {
		UINT16 LabelHeight;
      //UINT16 LabelWidth
        SetColor(WHITE);
        SetFont((void *) &DISPLAY_FONT);
        LabelHeight =  GetTextHeight((void *) &DISPLAY_FONT);
      //LabelWidth = GetTextWidth((char *)SwitchLabel, (void *) &DISPLAY_FONT);
        OutTextXY(22,GetMaxY()-(22*iSwitch-12)-LabelHeight/2,(char *)SwitchLabel);
    }
}

