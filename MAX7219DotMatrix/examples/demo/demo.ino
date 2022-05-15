//--------------------------------------------------
// Display Alphanumeric Shapes on MAX7219 Dot Matrix
// using MAX7219DotMatrix.h Library
// by: Anas Kuzechie (May 10, 2022)
//--------------------------------------------------
#include <MAX7219DotMatrix.h>
//----------------------------
#define DIN     2
#define CS      3
#define CLK     4
MAX7219DotMatrix disp(DIN, CS, CLK);
//------------------------------------------------------------
byte smiley[] = {0b01100110,0b10011001,0b01011010,0b00011000,
                 0b00011000,0b01000010,0b01000010,0b00111100};
//------------------------------------------------------------
void setup()
{
    disp.Init(1); //set brightness level 1 (1-->15)
    disp.Clear(); delay(1000);
}
//------------------------------------------------------------
void loop()
{
    disp.Letter('C'); delay(400); //display text
    disp.Letter('O'); delay(400);
    disp.Letter('U'); delay(400);
    disp.Letter('N'); delay(400);
    disp.Letter('T'); delay(400);
    //-----------------------------------------------
    disp.Clear(); delay(1000);
    //-----------------------------------------------
    for(byte i=0; i<=9; i++)    //display 0 to 9
    {
      disp.Number(i); delay(400);
    }
    //-----------------------------------------------
    disp.Clear(); delay(1000);
    for(byte i=0; i<=7; i++)    //sketch smiley face
    {
      disp.Byte(i+1, smiley[i]); delay(200);
    }
    delay(2000);
    disp.Clear(); delay(1000);
}