#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include "EncryptionObj.h"

/*
    usage: ./enc [e/d] [option] + ENTER
    >[insert text here] + ENTER
*/
int main(int argc, char* argv[]) {
    bool encrypt;
    string option;
    string text = "";

    //get text
    while (text=="") {
        cout << "text> ";
        getline(cin, text);
    }
    EncryptionObj encObj(text);


    if (argc<3) {
        cout << "Insufficient arguments. Please see README.md for proper usage" << endl;
        return 1;
    }

    //encrypt or decrypt parameter
    if (strcasecmp(argv[1], "e")==0) {
        encrypt = true;
    }
    else if (strcasecmp(argv[1], "d")==0) {
        encrypt = false;
    }
    else {
        cout << "Invalid arguments. Please see README.md for proper usage" << endl;
        return 1;
    }

    cout << endl;

    //option parameter
    if (strcasecmp(argv[2], "b")==0&&encrypt) {
        cout << encObj.binaryEncrypt() << endl;
    }
    else if (strcasecmp(argv[2], "br")==0&&encrypt) {
        queue<string> results = encObj.binaryEncryptRot();
        while (!results.empty()) {
            cout << results.front() << endl;
            results.pop();
        }
    }
    else if (strcasecmp(argv[2], "bf")==0) {
        cout << encObj.binaryFlip() << endl;
    }
    else if (strcasecmp(argv[2], "b")==0&&!encrypt) {
        cout << encObj.binaryDecrypt() << endl;
    }
    else if (strcasecmp(argv[2], "br")==0&&!encrypt) {
        queue<string> results = encObj.binaryDecryptRot();
        while (!results.empty()) {
            cout << results.front() << endl;
            results.pop();
        }
    }
    else if (strcasecmp(argv[2], "c")==0&&encrypt) {
        cout << encObj.caesarEncrypt() << endl;
    }
    else if (strcasecmp(argv[2], "c")==0&&!encrypt) {
        cout << encObj.caesarDecrypt() << endl;
    }
    else if (strcasecmp(argv[2], "v")==0&&encrypt) {
        cout << encObj.vigenereEncrypt() << endl;
    }
    else if (strcasecmp(argv[2], "v")==0&&!encrypt) {
        cout << encObj.vigenereDecrypt() << endl;
    }
    else {
        cout << "Invalid option. Please see README.md for proper usage" << endl;
        return 1;
    }
    
    return 0;
}