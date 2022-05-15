//-------------------------------------------------------------
// MAX7219DotMatrix.cpp - Source File
// Library for Displaying Numbers on MAX7219 Dot Matrix Display
// by: Anas Kuzechie (May 15, 2022)
//-------------------------------------------------------------
#include <Arduino.h>
#include <MAX7219DotMatrix.h>
//-------------------------------------------------------------
// Constructor
//-------------------------------------------------------------
MAX7219DotMatrix::MAX7219DotMatrix(int DIN, int CS, int CLK)
{
    pinMode(DIN, OUTPUT); _DIN = DIN;
    pinMode(CS, OUTPUT); _CS = CS;
    pinMode(CLK, OUTPUT); _CLK = CLK;
}
//-------------------------------------------------------------
// Methods
//-------------------------------------------------------------
void MAX7219DotMatrix::Init(byte brightness)
{
    MAX7219_write(0x09, 0);         //decoding mode OFF
    MAX7219_write(0x0A, brightness);//light intensity (0-15)
    MAX7219_write(0x0B, 7);         //scan limit: all digits ON
    MAX7219_write(0x0C, 1);         //turn ON MAX7219
}
//-------------------------------------------------------------
void MAX7219DotMatrix::Clear()
{
    for(uint8_t i=0; i<8; i++) MAX7219_write(i+1, 0);
}
//-------------------------------------------------------------
void MAX7219DotMatrix::Number(byte n)
{
    uint8_t n0[8] = {
        0b00000000,0b00011000,0b00100100,0b00100100,
        0b00100100,0b00100100,0b00011000,0b00000000};
    uint8_t n1[8] = {
        0b00000000,0b00001000,0b00011000,0b00001000,
        0b00001000,0b00001000,0b00011100,0b00000000};
    uint8_t n2[8] = {
        0b00000000,0b00011000,0b00100100,0b00001000,
        0b00010000,0b00100000,0b00111100,0b00000000};
    uint8_t n3[8] = {
        0b00000000,0b00111000,0b00000100,0b00111000,
        0b00000100,0b00000100,0b00111000,0b00000000};
    uint8_t n4[8] = {
        0b00000000,0b00000100,0b00001100,0b00010100,
        0b00111100,0b00000100,0b00000100,0b00000000};
    uint8_t n5[8] = {
        0b00000000,0b00111100,0b00100000,0b00111000,
        0b00000100,0b00000100,0b00111000,0b00000000};
    uint8_t n6[8] = {
        0b00000000,0b00011000,0b00100100,0b00111000,
        0b00100100,0b00100100,0b00011000,0b00000000};
    uint8_t n7[8] = {
        0b00000000,0b00111100,0b00000100,0b00001000,
        0b00010000,0b00100000,0b00100000,0b00000000};
    uint8_t n8[8] = {
        0b00000000,0b00011000,0b00100100,0b00011000,
        0b00100100,0b00100100,0b00011000,0b00000000};
    uint8_t n9[8] = {
        0b00000000,0b00011000,0b00100100,0b00100100,
        0b00011100,0b00100100,0b00011000,0b00000000};
    //-----------------------------------------------
    switch(n)
    {
        case 0:
        for(uint8_t i=0; i<8; i++) MAX7219_write(i+1, n0[i]); break;
        case 1:
        for(uint8_t i=0; i<8; i++) MAX7219_write(i+1, n1[i]); break;
        case 2:
        for(uint8_t i=0; i<8; i++) MAX7219_write(i+1, n2[i]); break;
        case 3:
        for(uint8_t i=0; i<8; i++) MAX7219_write(i+1, n3[i]); break;
        case 4:
        for(uint8_t i=0; i<8; i++) MAX7219_write(i+1, n4[i]); break;
        case 5:
        for(uint8_t i=0; i<8; i++) MAX7219_write(i+1, n5[i]); break;
        case 6:
        for(uint8_t i=0; i<8; i++) MAX7219_write(i+1, n6[i]); break;
        case 7:
        for(uint8_t i=0; i<8; i++) MAX7219_write(i+1, n7[i]); break;
        case 8:
        for(uint8_t i=0; i<8; i++) MAX7219_write(i+1, n8[i]); break;
        case 9:
        for(uint8_t i=0; i<8; i++) MAX7219_write(i+1, n9[i]);
    }
}
//-------------------------------------------------------------
void MAX7219DotMatrix::Letter(char l)
{
    uint8_t i;
    uint8_t A[8] = {
        0b00000000,0b00011000,0b00100100,0b00100100,
        0b00111100,0b00100100,0b00100100,0b00000000};
    uint8_t B[8] = {
        0b00000000,0b00111000,0b00100100,0b00111000,
        0b00100100,0b00100100,0b00111000,0b00000000};
    uint8_t C[8] = {
        0b00000000,0b00011000,0b00100100,0b00100000,
        0b00100000,0b00100100,0b00011000,0b00000000};
    uint8_t D[8] = {
        0b00000000,0b00111000,0b00100100,0b00100100,
        0b00100100,0b00100100,0b00111000,0b00000000};
    uint8_t E[8] = {
        0b00000000,0b00111100,0b00100000,0b00111100,
        0b00100000,0b00100000,0b00111100,0b00000000};
    uint8_t F[8] = {
        0b00000000,0b00111100,0b00100000,0b00111100,
        0b00100000,0b00100000,0b00100000,0b00000000};
    uint8_t G[8] = {
        0b00000000,0b00011000,0b00100100,0b00100000,
        0b00101100,0b00100100,0b00011000,0b00000000};
    uint8_t H[8] = {
        0b00000000,0b00100100,0b00100100,0b00111100,
        0b00100100,0b00100100,0b00100100,0b00000000};
    uint8_t I[8] = {
        0b00000000,0b00011100,0b00001000,0b00001000,
        0b00001000,0b00001000,0b00011100,0b00000000};
    uint8_t J[8] = {
        0b00000000,0b00001110,0b00000100,0b00000100,
        0b00000100,0b00100100,0b00011000,0b00000000};
    uint8_t K[8] = {
        0b00000000,0b00100100,0b00101000,0b00110000,
        0b00110000,0b00101000,0b00100100,0b00000000};
    uint8_t L[8] = {
        0b00000000,0b00100000,0b00100000,0b00100000,
        0b00100000,0b00100000,0b00111100,0b00000000};
    uint8_t M[8] = {
        0b00000000,0b00100010,0b00110110,0b00101010,
        0b00100010,0b00100010,0b00100010,0b00000000};
    uint8_t N[8] = {
        0b00000000,0b00100010,0b00110010,0b00101010,
        0b00101010,0b00100110,0b00100010,0b00000000};
    uint8_t O[8] = {
        0b00000000,0b00011000,0b00100100,0b01000010,
        0b01000010,0b00100100,0b00011000,0b00000000};
    uint8_t P[8] = {
        0b00000000,0b00111000,0b00100100,0b00111000,
        0b00100000,0b00100000,0b00100000,0b00000000};
    uint8_t Q[8] = {
        0b00000000,0b00011000,0b00100100,0b00100100,
        0b00100100,0b00100100,0b00011100,0b00000010};
    uint8_t R[8] = {
        0b00000000,0b00111000,0b00100100,0b00111000,
        0b00100100,0b00100100,0b00100100,0b00000000};
    uint8_t S[8] = {
        0b00000000,0b00011100,0b00100000,0b00011000,
        0b00000100,0b00100100,0b00011000,0b00000000};
    uint8_t T[8] = {
        0b00000000,0b00111110,0b00001000,0b00001000,
        0b00001000,0b00001000,0b00001000,0b00000000};
    uint8_t U[8] = {
        0b00000000,0b00100100,0b00100100,0b00100100,
        0b00100100,0b00100100,0b00011000,0b00000000};
    uint8_t V[8] = {
        0b00000000,0b00100010,0b00100010,0b00100010,
        0b00010100,0b00010100,0b00001000,0b00000000};
    uint8_t W[8] = {
        0b00000000,0b00100010,0b00100010,0b00100010,
        0b00101010,0b00110110,0b00100010,0b00000000};
    uint8_t X[8] = {
        0b00000000,0b00100010,0b00010100,0b00001000,
        0b00010100,0b00100010,0b00100010,0b00000000};
    uint8_t Y[8] = {
        0b00000000,0b00100010,0b00010100,0b00001000,
        0b00001000,0b00001000,0b00001000,0b00000000};
    uint8_t Z[8] = {
        0b00000000,0b00111100,0b00000100,0b00001000,
        0b00010000,0b00100000,0b00111100,0b00000000};
    //------------------------------------------------------
    switch(l)
    {
        case 'A':
        for(i=0; i<8; i++) MAX7219_write(i+1, A[i]); break;
        case 'B':
        for(i=0; i<8; i++) MAX7219_write(i+1, B[i]); break;
        case 'C':
        for(i=0; i<8; i++) MAX7219_write(i+1, C[i]); break;
        case 'D':
        for(i=0; i<8; i++) MAX7219_write(i+1, D[i]); break;
        case 'E':
        for(i=0; i<8; i++) MAX7219_write(i+1, E[i]); break;
        case 'F':
        for(i=0; i<8; i++) MAX7219_write(i+1, F[i]); break;
        case 'G':
        for(i=0; i<8; i++) MAX7219_write(i+1, G[i]); break;
        case 'H':
        for(i=0; i<8; i++) MAX7219_write(i+1, H[i]); break;
        case 'I':
        for(i=0; i<8; i++) MAX7219_write(i+1, I[i]); break;
        case 'J':
        for(i=0; i<8; i++) MAX7219_write(i+1, J[i]); break;
        case 'K':
        for(i=0; i<8; i++) MAX7219_write(i+1, K[i]); break;
        case 'L':
        for(i=0; i<8; i++) MAX7219_write(i+1, L[i]); break;
        case 'M':
        for(i=0; i<8; i++) MAX7219_write(i+1, M[i]); break;
        case 'N':
        for(i=0; i<8; i++) MAX7219_write(i+1, N[i]); break;
        case 'O':
        for(i=0; i<8; i++) MAX7219_write(i+1, O[i]); break;
        case 'P':
        for(i=0; i<8; i++) MAX7219_write(i+1, P[i]); break;
        case 'Q':
        for(i=0; i<8; i++) MAX7219_write(i+1, Q[i]); break;
        case 'R':
        for(i=0; i<8; i++) MAX7219_write(i+1, R[i]); break;
        case 'S':
        for(i=0; i<8; i++) MAX7219_write(i+1, S[i]); break;
        case 'T':
        for(i=0; i<8; i++) MAX7219_write(i+1, T[i]); break;
        case 'U':
        for(i=0; i<8; i++) MAX7219_write(i+1, U[i]); break;
        case 'V':
        for(i=0; i<8; i++) MAX7219_write(i+1, V[i]); break;
        case 'W':
        for(i=0; i<8; i++) MAX7219_write(i+1, W[i]); break;
        case 'X':
        for(i=0; i<8; i++) MAX7219_write(i+1, X[i]); break;
        case 'Y':
        for(i=0; i<8; i++) MAX7219_write(i+1, Y[i]); break;
        case 'Z':
        for(i=0; i<8; i++) MAX7219_write(i+1, Z[i]); break;
    }
}
//-------------------------------------------------------------
void MAX7219DotMatrix::Byte(byte row, byte value)
{
    MAX7219_write(row, value);
}
//-------------------------------------------------------------
// Functions
//-------------------------------------------------------------
void MAX7219DotMatrix::MAX7219_write(uint8_t cmd_byte, uint8_t data_byte)
{
    digitalWrite(_CS, LOW);   //CS low pulse to enable MAX7219   
    //---------------------------------------------------------
    SPI_send(cmd_byte);       //send command byte to MAX7219
    SPI_send(data_byte);      //send data byte to MAX7219
    //----------------------------------------------------------
    digitalWrite(_CS, HIGH);  //CS high pulse to disable MAX7219    
}
//--------------------------------------------------------------
void MAX7219DotMatrix::SPI_send(uint8_t data)
{
    uint8_t i;
    for(i=0; i<8; i++)
    {
        digitalWrite(_CLK, LOW);                  //CLK low pulse
        //----------------------------------------------------------
        if(data & 0x80) digitalWrite(_DIN, HIGH); //o/p high if MSB = 1
        else digitalWrite(_DIN, LOW);             //o/p low if MSB = 0
        //----------------------------------------------------------
        digitalWrite(_CLK, HIGH);                 //CLK high pulse
        data = data << 1;                         //shift data left one bit
    }  
}
