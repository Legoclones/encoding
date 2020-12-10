#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <math.h>
#include <sstream>
#include <string.h>

using namespace std;

class EncodingObj {
    private:
        //Section 1 - Initializers/Destructors
        string text;

        //Section 2 - Binary
        string binaryToAscii(string str);
        int binaryToDecimal(string str);
        string asciiToBinary(string str);
        string decimalToBinary(int num, int leadZero);

        //Section 3 - Caesar Shift
        string caesarShift(string str, int n);

        //Section 4 - Text Flip
        string textFlip(string str);

        //Section 5 - Hexadecimal
        string asciiToHexadecimal(string str);
        string hexadecimalToAscii(string str);
        string decimalToHexadecimal(int num);
        int hexadecimalToDecimal(string str);
        string decCharToHexChar(int digit);
        int hexCharToDecChar(char character);

        //Section 6 - ASCII/Decimal

        //Section 7 - Base64
        string base64Encode(string str);
        string base64Decode(string str);

        //Section 8 - Bytes

        //Section 9 - XOR
        
    public:
        //Section 1 - Initializers/Destructors
        EncodingObj(string textArg);
        ~EncodingObj() {}
        string getText();

        //Section 2 - Binary
        string asciiToBinary();
        queue<string> asciiToBinaryAll();
        string decimalToBinary();
        string binaryToAscii();
        queue<string> binaryToAsciiAll();
        string binaryToDecimal();
        string binaryFlip();

        //Section 3 - Caesar Shift
        queue<string> caesarEncode();
        queue<string> caesarDecode();

        //Section 4 - Text Flip
        string textFlip();

        //Section 5 - Hexadecimal
        string asciiToHexadecimal();
        string hexadecimalToAscii();
        string decimalToHexadecimal();
        int hexadecimalToDecimal();

        //Section 6 - ASCII/Decimal
        string decimalToAscii();
        string asciiToDecimal();

        //Section 7 - Base64
        string base64Decode();
        string base64Encode();

        //Section 8 - Bytes

        //Section 9 - XOR
};