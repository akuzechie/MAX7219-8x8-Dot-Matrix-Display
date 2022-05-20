//-------------------------------------------------------------
// MAX7219DotMatrix.h - Header File
// Library for Displaying Numbers on MAX7219 Dot Matrix Display
// by: Anas Kuzechie (May 15, 2022)
//-------------------------------------------------------------
//header guards
#ifndef MAX7219DotMatrix_h
#define MAX7219DotMatrix_h
//--------------------------------------------------------
//class definition
class MAX7219DotMatrix
{
    public:
        //constructor
        MAX7219DotMatrix(int DIN, int CS, int CLK);
        //methods
        void Init(byte brightness);
        void Clear();
        void Number(byte n);
        void Letter(char l);
        void Byte(byte row, byte value);
    private:
        int _DIN;
        int _CS;
        int _CLK;
        void MAX7219_write(uint8_t cmd_byte, uint8_t data_byte);
        void SPI_send(uint8_t data);
};
//--------------------------------------------------------
#endif
