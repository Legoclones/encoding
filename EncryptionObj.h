#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class EncryptionObj {
    private:
        string text;
        string base10ToBinary(char myChar);
        string binaryDecrypt(string str);
    public:
        EncryptionObj(string textArg);
        virtual ~EncryptionObj() {}
        string getText();

        string binaryEncrypt();
        //binaryEncryptRot();
        //binaryEncryptFlip();
        string binaryDecrypt();
        queue<string> binaryDecryptRot();
        //binaryDecryptFlip();

        string caesarEncrypt();
        string caesarDecrypt();

        string vigenereEncrypt();
        string vigenereDecrypt();
};