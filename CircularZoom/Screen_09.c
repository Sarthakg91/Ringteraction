#include <stdio.h>
#include <stdlib.h>
#include <p32xxxx.h>                // Processor defs
#define _SUPPRESS_PLIB_WARNING 1
#include <plib.h>
#include "main.h"

// Select one of these defines to set the pixel color order
#define SSD1331_COLORORDER_RGB
// #define SSD1331_COLORORDER_BGR

// Timing Delays
#define SSD1331_DELAYS_HWFILL	(3)
#define SSD1331_DELAYS_HWLINE   (1)

// SSD1331 Commands
#define SSD1331_CMD_DRAWLINE 		0x21
#define SSD1331_CMD_DRAWRECT 		0x22
#define SSD1331_CMD_FILL 			0x26
#define SSD1331_CMD_SETCOLUMN 		0x15
#define SSD1331_CMD_SETROW    		0x75
#define SSD1331_CMD_CONTRASTA 		0x81
#define SSD1331_CMD_CONTRASTB 		0x82
#define SSD1331_CMD_CONTRASTC		0x83
#define SSD1331_CMD_MASTERCURRENT 	0x87
#define SSD1331_CMD_SETREMAP 		0xA0
#define SSD1331_CMD_STARTLINE 		0xA1
#define SSD1331_CMD_DISPLAYOFFSET 	0xA2
#define SSD1331_CMD_NORMALDISPLAY 	0xA4
#define SSD1331_CMD_DISPLAYALLON  	0xA5
#define SSD1331_CMD_DISPLAYALLOFF 	0xA6
#define SSD1331_CMD_INVERTDISPLAY 	0xA7
#define SSD1331_CMD_SETMULTIPLEX  	0xA8
#define SSD1331_CMD_SETMASTER 		0xAD
#define SSD1331_CMD_DISPLAYOFF 		0xAE
#define SSD1331_CMD_DISPLAYON     	0xAF
#define SSD1331_CMD_POWERMODE 		0xB0
#define SSD1331_CMD_PRECHARGE 		0xB1
#define SSD1331_CMD_CLOCKDIV 		0xB3
#define SSD1331_CMD_PRECHARGEA 		0x8A
#define SSD1331_CMD_PRECHARGEB 		0x8B
#define SSD1331_CMD_PRECHARGEC 		0x8C
#define SSD1331_CMD_PRECHARGELEVEL 	0xBB
#define SSD1331_CMD_VCOMH 		0xBE


#define cs_high     _RD1 = 1;
#define cs_low      _RD1 = 0;
#define cs_TRIS     TRISDbits.TRISD1 = 0;

#define rs_high     _RD3 = 1;
#define rs_low      _RD3 = 0;
#define rs_TRIS     TRISDbits.TRISD3 = 0;

//#define dc_high     _RD3 = 1;
//#define dc_low      _RD3 = 0;
//#define dc_TRIS     TRISDbits.TRISD3 = 0;

#define rst_high    _RD6 = 1;
#define rst_low     _RD6 = 0;
#define rst_TRIS    TRISDbits.TRISD6 = 0;

static const unsigned int WIDTH = 96;
static const unsigned int HEIGHT = 64;


//==============================================================================
void writeCommand(unsigned int c)
{
    //digitalWrite(_rs, LOW);
    rs_low;
    nop10;

    //digitalWrite(_cs, LOW);
    cs_low;
    nop10;

    //Serial.print("C ");
    //spiwrite(c);
    SPI1_Write_8(c);
    nop10;

    //digitalWrite(_cs, HIGH);
    cs_high;
    nop10;
}

//==============================================================================
void writeData(unsigned int c) {
    //digitalWrite(_rs, HIGH);
    rs_high;
    nop10;
    
    //digitalWrite(_cs, LOW);
    cs_low;
    nop10;
    
    //Serial.print("D ");
    //spiwrite(c);
    SPI1_Write_8(c);
    nop10;
    
    //digitalWrite(_cs, HIGH);
    cs_high;
    nop10;
}

//==============================================================================
void Screen_Init( void )
{
    cs_TRIS;
    rs_TRIS;
    //dc_TRIS;
    rst_TRIS;

    TRISDbits.TRISD7 = 0;
    _RD7 = 1;


    // Toggle RST low to reset; CS low so it'll listen to us
    cs_low;
    
    rst_high;
    Delayms(500);
    rst_low;
    Delayms(500);
    rst_high;
    Delayms(500);
    cs_high;


    // Initialization Sequence
    writeCommand(SSD1331_CMD_DISPLAYOFF);  	// 0xAE
    writeCommand(SSD1331_CMD_SETREMAP); 	// 0xA0
#if defined SSD1331_COLORORDER_RGB
    writeCommand(0x72);				// RGB Color
#else
    writeCommand(0x76);				// BGR Color
#endif
    writeCommand(SSD1331_CMD_STARTLINE); 	// 0xA1
    writeCommand(0x0);
    writeCommand(SSD1331_CMD_DISPLAYOFFSET); 	// 0xA2
    writeCommand(0x0);
    writeCommand(SSD1331_CMD_NORMALDISPLAY);  	// 0xA4
    writeCommand(SSD1331_CMD_SETMULTIPLEX); 	// 0xA8
    writeCommand(0x3F);  			// 0x3F 1/64 duty
    writeCommand(SSD1331_CMD_SETMASTER);  	// 0xAD
    writeCommand(0x8E);
    writeCommand(SSD1331_CMD_POWERMODE);  	// 0xB0
    writeCommand(0x0B);
    writeCommand(SSD1331_CMD_PRECHARGE);  	// 0xB1
    writeCommand(0x31);
    writeCommand(SSD1331_CMD_CLOCKDIV);  	// 0xB3
    writeCommand(0xF0);  // 7:4 = Oscillator Frequency, 3:0 = CLK Div Ratio (A[3:0]+1 = 1..16)
    writeCommand(SSD1331_CMD_PRECHARGEA);  	// 0x8A
    writeCommand(0x64);
    writeCommand(SSD1331_CMD_PRECHARGEB);  	// 0x8B
    writeCommand(0x78);
    writeCommand(SSD1331_CMD_PRECHARGEA);  	// 0x8C
    writeCommand(0x64);
    writeCommand(SSD1331_CMD_PRECHARGELEVEL);  	// 0xBB
    writeCommand(0x3A);
    writeCommand(SSD1331_CMD_VCOMH);  		// 0xBE
    writeCommand(0x3E);
    writeCommand(SSD1331_CMD_MASTERCURRENT);  	// 0x87
    writeCommand(0x06);
    writeCommand(SSD1331_CMD_CONTRASTA);  	// 0x81
    writeCommand(0x91);
    writeCommand(SSD1331_CMD_CONTRASTB);  	// 0x82
    writeCommand(0x50);
    writeCommand(SSD1331_CMD_CONTRASTC);  	// 0x83
    writeCommand(0x7D);
    writeCommand(SSD1331_CMD_DISPLAYON);	//--turn on oled panel
    Delayms(10);

}
//==============================================================================
void Screen_goTo(int x, int y) {
  if ((x >= WIDTH) || (y >= HEIGHT)) return;

  // set x and y coordinate
  writeCommand(SSD1331_CMD_SETCOLUMN);
  writeCommand(x);
  writeCommand(WIDTH-1);

  writeCommand(SSD1331_CMD_SETROW);
  writeCommand(y);
  writeCommand(HEIGHT-1);
}
//==============================================================================
void Screen_DrawPixel(int x, int y, unsigned int color)
{
    if ((x < 0) || (x >= WIDTH) || (y < 0) || (y >= HEIGHT)) return;
    Screen_goTo(x, y);

    rs_high;
    nop10;

    cs_low;
    nop10;

    SPI1_Write_8(color >> 8);
    nop10;

    SPI1_Write_8(color);
    nop10;

    cs_high;
    nop10;
}
//==============================================================================
void Screen_Fill(unsigned int color)
{
unsigned int i;

    Screen_goTo(0, 0);
    rs_high;
    nop10;

    cs_low;
    nop10;
    for (i=0; i<(WIDTH*HEIGHT); i++)
    {
        SPI1_Write_8(color >> 8);
        nop10;

        SPI1_Write_8(color);
        nop10;
    }

    cs_high;
    nop10;
}
//==============================================================================
//==============================================================================



//==============================================================================
//==============================================================================
unsigned int Color565(unsigned char r, unsigned char g, unsigned char b) {
  unsigned int c;
  c = r >> 3;
  c <<= 6;
  c |= g >> 2;
  c <<= 5;
  c |= b >> 3;

  return c;
}

extern const unsigned char Screen_Font[];
//#=================================================================================================
//#
//#-------------------------------------------------------------------------------------------------
void Screen_Draw_Font(int x, int y, unsigned char F, unsigned int c)
{
unsigned int CC1, CC2, TT, FF, FONT;

    FF = (F - 0x20) * 8; //F * 8;
    for(CC1 = 0; CC1 < 8; CC1++)
    {
        FONT = Screen_Font[FF + CC1];
        TT = 1;
        for( CC2 = 0; CC2 < 8; CC2++ )
        {
            if ((FONT & TT) == TT)
            {
                 Screen_DrawPixel(x + CC1, y + CC2, c);
            }
            TT = TT << 1;
        }
    }

}
//#=================================================================================================
//#
//#-------------------------------------------------------------------------------------------------
void Screen_Print_Str(int x, int y, char * sz, unsigned int c)
{
    while (*sz != '\0') {
        Screen_Draw_Font(x, y, *sz, c);
        x = x + 8;
        sz += 1;
    }
}
//==============================================================================
void Screen_Print_DEC(int x, int y, int val, unsigned int c)
{
char TStr[16];
    itoa(TStr, val, 10);
    Screen_Print_Str(x, y, TStr, c);
}
//==============================================================================
void Screen_Print_Val(int x, int y, int val, int base, unsigned int c)
{
char TStr[16];
    itoa(TStr, val, base);
    Screen_Print_Str(x, y, TStr, c);
}




//#=================================================================================================
//#
//#-------------------------------------------------------------------------------------------------
#define swap(a, b) { int t = a; a = b; b = t; }
void Screen_Draw_Line(int x0, int y0, int x1, int y1, unsigned int c)
{
// Bresenham's algorithm - thx wikpedia
  int steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep) {
    swap(x0, y0);
    swap(x1, y1);
  }
  if (x0 > x1) {
    swap(x0, x1);
    swap(y0, y1);
  }

  int dx, dy;
  dx = x1 - x0;
  dy = abs(y1 - y0);

  int err = dx / 2;
  int ystep;

  if (y0 < y1) {
    ystep = 1;
  } else {
    ystep = -1;
  }

  for (; x0<=x1; x0++)
  {
    if (steep) {
      Screen_DrawPixel(y0, x0, c);
    } else {
      Screen_DrawPixel(x0, y0, c);
    }
    err -= dy;
    if (err < 0) {
      y0 += ystep;
      err += dx;
    }
  }
}
//#=================================================================================================
//#
//#-------------------------------------------------------------------------------------------------
void mOLED_Draw_Circle(int x0, int y0, int r, unsigned int c)
{
  int f = 1 - r;
  int ddF_x = 1;
  int ddF_y = -2 * r;
  int x = 0;
  int y = r;

  Screen_DrawPixel(x0  , y0+r, c);
  Screen_DrawPixel(x0  , y0-r, c);
  Screen_DrawPixel(x0+r, y0  , c);
  Screen_DrawPixel(x0-r, y0  , c);

  while (x<y) {
    if (f >= 0) {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x;

    Screen_DrawPixel(x0 + x, y0 + y, c);
    Screen_DrawPixel(x0 - x, y0 + y, c);
    Screen_DrawPixel(x0 + x, y0 - y, c);
    Screen_DrawPixel(x0 - x, y0 - y, c);
    Screen_DrawPixel(x0 + y, y0 + x, c);
    Screen_DrawPixel(x0 - y, y0 + x, c);
    Screen_DrawPixel(x0 + y, y0 - x, c);
    Screen_DrawPixel(x0 - y, y0 - x, c);
  }
}





