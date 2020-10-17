#include <iostream>
#include <string>
#include <stack>

using namespace std;

class EncryptionObj {
    private:
        string text;
        string base10ToBinary(char myChar);
    public:
        EncryptionObj(string textArg);
        string getText();
        string binaryEncrypt();
        string binaryDecrypt();
        string caesarEncrypt();
        string caesarDecrypt();
        string vigenereEncrypt();
        string vigenereDecrypt();
};