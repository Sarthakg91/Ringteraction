/* 
 * File:   Main.h
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

//==============================================================================
#define LED_TRIS       TRISDbits.TRISD4 = 0;
#define LED_HIGH       LATDbits.LATD4 = 1;
#define LED_LOW        LATDbits.LATD4 = 0;
//==============================================================================
#define JST1_1_TRIS_OUT     TRISBbits.TRISB2 = 0;
#define JST1_1_TRIS_IN      TRISBbits.TRISB2 = 1;
#define JST1_1_HIGH         LATBbits.LATB2 = 1;
#define JST1_1_LOW          LATBbits.LATB2 = 0;
#define JST1_1              PORTBbits.RB2
//-------------------------------------------------------------------
#define JST1_2_TRIS_OUT     TRISGbits.TRISG6 = 0;
#define JST1_2_TRIS_IN      TRISGbits.TRISG6 = 1;
#define JST1_2_HIGH         LATGbits.LATG6 = 1;
#define JST1_2_LOW          LATGbits.LATG6 = 0;
#define JST1_2              PORTGbits.RG6
//==============================================================================
// JST2_1 : MCLR
#define JST2_2_TRIS_OUT     TRISBbits.TRISB6 = 0;
#define JST2_2_TRIS_IN      TRISBbits.TRISB6 = 1;
#define JST2_2_HIGH         LATBbits.LATB6 = 1;
#define JST2_2_LOW          LATBbits.LATB6 = 0;
#define JST2_2              PORTBbits.RB6
//-------------------------------------------------------------------
#define JST2_3_TRIS_OUT     TRISBbits.TRISB7 = 0;
#define JST2_3_TRIS_IN      TRISBbits.TRISB7 = 1;
#define JST2_3_HIGH         LATBbits.LATB7 = 1;
#define JST2_3_LOW          LATBbits.LATB7 = 0;
#define JST2_3              PORTBbits.RB7
//==============================================================================
#define JST3_1_TRIS_OUT     TRISDbits.TRISD10 = 0;
#define JST3_1_TRIS_IN      TRISDbits.TRISD10 = 1;
#define JST3_1_HIGH         LATDbits.LATD10 = 1;
#define JST3_1_LOW          LATDbits.LATD10 = 0;
#define JST3_1              PORTDbits.RD10
//-------------------------------------------------------------------
#define JST3_2_TRIS_OUT     TRISDbits.TRISD9 = 0;
#define JST3_2_TRIS_IN      TRISDbits.TRISD9 = 1;
#define JST3_2_HIGH         LATDbits.LATD9 = 1;
#define JST3_2_LOW          LATDbits.LATD9 = 0;
#define JST3_2              PORTDbits.RD9
//==============================================================================
#define JST4_1_TRIS_OUT     TRISBbits.TRISB11 = 0;
#define JST4_1_TRIS_IN      TRISBbits.TRISB11 = 1;
#define JST4_1_HIGH         LATBbits.LATB11 = 1;
#define JST4_1_LOW          LATBbits.LATB11 = 0;
#define JST4_1              PORTBbits.RB11
//-------------------------------------------------------------------
#define JST4_2_TRIS_OUT     TRISBbits.TRISB12 = 0;
#define JST4_2_TRIS_IN      TRISBbits.TRISB12 = 1;
#define JST4_2_HIGH         LATBbits.LATB12 = 1;
#define JST4_2_LOW          LATBbits.LATB12 = 0;
#define JST4_2              PORTBbits.RB12
//==============================================================================
//JST5_1 : UART1 TX    
//JST5_2 : UART1 RX
#define JST5_3_TRIS_OUT     TRISBbits.TRISB13 = 0;
#define JST5_3_TRIS_IN      TRISBbits.TRISB13 = 1;
#define JST5_3_HIGH         LATBbits.LATB13 = 1;
#define JST5_3_LOW          LATBbits.LATB13 = 0;
#define JST5_3              PORTBbits.RB13
//==============================================================================
#define PB_TRIS       TRISDbits.TRISD5 = 1;
#define PB            PORTDbits.RD5
//#define LED_LOW        LATDbits.LATD4 = 0;
//==============================================================================




//==============================================================================
//==============================================================================
#define nop         asm(" nop ");
#define nop2        nop; nop;
#define nop3        nop2; nop;
#define nop4        nop3; nop;
#define nop5        nop4; nop;
#define nop6        nop5; nop;
#define nop7        nop6; nop;
#define nop8        nop7; nop;
#define nop9        nop8; nop;
#define nop10       nop9; nop;
//==============================================================================


unsigned char OS_Str_1[64];

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

