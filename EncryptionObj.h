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
        string binaryEncrypt(string str);
    public:
        EncryptionObj(string textArg);
        virtual ~EncryptionObj() {}
        string getText();

        string binaryEncrypt();
        queue<string> binaryEncryptRot();
        string binaryFlip();
        string binaryDecrypt();
        queue<string> binaryDecryptRot();

        string caesarEncrypt();
        string caesarDecrypt();

        string vigenereEncrypt();
        string vigenereDecrypt();
};