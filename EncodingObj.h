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
        string text;
        string base10ToBinary(char myChar);
        string binaryDecode(string str);
        string binaryEncode(string str);
        string caesarShift(string str, int n);
        string textFlip(string str);
        string hexEncode(string str);
        string hexDecode(string str);
        int base16toBase10(char character);
        string base10toBase16(int digit);
    public:
        EncodingObj(string textArg);
        ~EncodingObj() {}
        string getText();

        string binaryEncode();
        queue<string> binaryEncodeRot();
        string binaryFlip();
        string binaryDecode();
        queue<string> binaryDecodeRot();

        queue<string> caesarEncode();
        queue<string> caesarDecode();

        string textFlip();

        string hexEncode();
        string hexDecode();

        //base64

        //decodeall - this tries out everything, maybe even include a dictionary at some point
};