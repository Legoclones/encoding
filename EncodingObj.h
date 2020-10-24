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
    public:
        EncodingObj(string textArg);
        virtual ~EncodingObj() {}
        string getText();

        string binaryEncode();
        queue<string> binaryEncodeRot();
        string binaryFlip();
        string binaryDecode();
        queue<string> binaryDecodeRot();

        string caesarEncode();
        string caesarDecode();

        string vigenereEncode();
        string vigenereDecode();
};