//------------------------------------------
// Different Patterns on MAX7219 Dot Matrix
// using MAX7219DotMatrix.h Library
// by: Anas Kuzechie (May 10, 2022)
//------------------------------------------
#include <MAX7219DotMatrix.h>
//----------------------------
#define DIN     2
#define CS      3
#define CLK     4
MAX7219DotMatrix disp(DIN, CS, CLK);
//-------------------------------------------------
void setup()
{
  disp.Init(1);
  disp.Clear(); delay(1000);
}
//-------------------------------------------------
void loop()
{     
  fill_display();
  delay(500); disp.Clear(); delay(500);
  //--------------------------------------
  scrolling_pixel();
  delay(500); disp.Clear(); delay(500);
  //--------------------------------------
  random_bytes();
  delay(500); disp.Clear(); delay(500);
}
//-------------------------------------------------
void fill_display()
{
  for(byte i=1; i<=8; i++)
  {
    byte j = 0;
    while(j <= 127)
    {
      j = j*2 + 1;
      disp.Byte(i, j); delay(50);
    }
  }
}
//-------------------------------------------------
void scrolling_pixel()
{
  for(byte i=1; i<=8; i++)
  {
    if(i%2 == 1)
    {
      byte j = 0;
      while(j <= 127)
      {
        if(j == 0) j = 1;
        else j = j*2;
        disp.Byte(i, j); delay(75);
      }
    }
    //-------------------------------
    if(i%2 == 0)
    {
      byte j = 0b10000000;
      while(j > 1)
      {
        if(j == 0b10000000)
        {
          disp.Byte(i, j);
          j = j >> 1;
        }
        else
        {
          j = j >> 1;
          disp.Byte(i, j);
        }
        delay(75);
      }
    }
    disp.Byte(i, 0);
  }
}
//-------------------------------------------------
void random_bytes()
{
  for(byte i=1; i<=50; i++)
  {
    disp.Byte(random(1,8), random(1, 255));
    delay(100);
  }
}