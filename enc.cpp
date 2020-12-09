#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include "EncodingObj.h"

/*
    TODOS:
    - Update README with new options

    - Add base64 functions
    - Add ascii to decimal and decimal to ascii
    - Add XOR
    - Add bytes
    - Put all on one line so you can pipe commands
    - Thoroughly test (incl memory leaks with Valgrind)
*/
/*
    usage: ./enc [option] + ENTER
    >[insert text here] + ENTER
*/
int main(int argc, char* argv[]) {
    string option;
    string text = "";

    //get text
    while (text=="") {
        cout << "text> ";
        getline(cin, text);
    }
    EncodingObj encObj(text);


    if (argc<2) {
        cout << "Insufficient arguments. Please see README.md for proper usage" << endl;
        return 1;
    }

    cout << endl;

    //option parameter
    if (strcasecmp(argv[1], "a2b")==0) {
        cout << encObj.asciiToBinary() << endl;
    }
    else if (strcasecmp(argv[1], "b2a")==0) {
        cout << encObj.binaryToAscii() << endl;
    }
    else if (strcasecmp(argv[1], "bf")==0) {
        cout << encObj.binaryFlip() << endl;
    }
    else if (strcasecmp(argv[1], "a2ba")==0) {
        queue<string> results = encObj.asciiToBinaryAll();
        for (int i = 0; !results.empty(); i++) {
            cout << i << " digit";
            if (i!=1) {
                cout << "s";
            }
            cout << " rotated: ";
            if (i==1) {
                cout << " ";
            }
            cout << results.front() << endl;
            results.pop();
        }
    }  
    else if (strcasecmp(argv[1], "b2aa")==0) {
        queue<string> results = encObj.binaryToAsciiAll();
        for (int i = 0; !results.empty(); i++) {
            cout << i << " digit";
            if (i!=1) {
                cout << "s";
            }
            cout << " rotated: ";
            if (i==1) {
                cout << " ";
            }
            cout << results.front() << endl;
            results.pop();
        }
    }
    else if (strcasecmp(argv[1], "ce")==0) {
        queue<string> results = encObj.caesarEncode();
        for (int i = 0; !results.empty(); i++) {
            cout << i << " character";
            if (i!=1) {
                cout << "s";
            }
            cout << " shifted: ";
            if (i==1) {
                cout << " ";
            }
            cout << results.front() << endl;
            results.pop();
        }
    }
    else if (strcasecmp(argv[1], "cd")==0) {
        queue<string> results = encObj.caesarDecode();
        for (int i = 0; !results.empty(); i++) {
            cout << i << " character";
            if (i!=1) {
                cout << "s";
            }
            cout << " shifted: ";
            if (i==1) {
                cout << " ";
            }
            cout << results.front() << endl;
            results.pop();
        }
    }
    else if (strcasecmp(argv[1], "tf")==0) {
        cout << encObj.textFlip() << endl;
    }
    else if (strcasecmp(argv[1], "a2h")==0) {
        cout << encObj.asciiToHexadecimal() << endl;
    }
    else if (strcasecmp(argv[1], "h2a")==0) {
        cout << encObj.hexadecimalToAscii() << endl;
    }
    else if (strcasecmp(argv[1], "d2b")==0) {
        cout << encObj.decimalToBinary() << endl;
    }
    else if (strcasecmp(argv[1], "b2d")==0) {
        cout << encObj.binaryToDecimal() << endl;
    }
    else if (strcasecmp(argv[1], "d2h")==0) {
        cout << encObj.decimalToHexadecimal() << endl;
    }
    else if (strcasecmp(argv[1], "h2d")==0) {
        cout << encObj.hexadecimalToDecimal() << endl;
    }
    /*else if (strcasecmp(argv[1], "a2b64")==0) {
        cout << encObj.asciiToBase64() << endl;
    }
    else if (strcasecmp(argv[1], "b642a")==0) {
        cout << encObj.base64ToAscii() << endl;
    }*/
    else {
        cout << "Invalid option. Please see README.md for proper usage" << endl;
        return 1;
    }
    
    return 0;
}