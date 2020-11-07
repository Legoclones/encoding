#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class EncodingObj {
    private:
        string text;
        string base10ToBinary(char myChar);
        string binaryDecode(string str);
        string binaryEncode(string str);
        string caesarShift(string str, int n);
        string textFlip(string str);
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

        //hex

        //base64

        //text flip

        //decodeall - this tries out everything, maybe even include a dictionary at some point
};