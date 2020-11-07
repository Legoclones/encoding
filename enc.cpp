#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include "EncodingObj.h"

/*
    - Add functions
    - Check for memory leaks with Valgrind
*/
/*
    usage: ./enc [e/d] [option] + ENTER
    >[insert text here] + ENTER
*/
int main(int argc, char* argv[]) {
    bool encode;
    string option;
    string text = "";

    //get text
    while (text=="") {
        cout << "text> ";
        getline(cin, text);
    }
    EncodingObj encObj(text);


    if (argc<3) {
        cout << "Insufficient arguments. Please see README.md for proper usage" << endl;
        return 1;
    }

    //encode or decode parameter
    if (strcasecmp(argv[1], "e")==0) {
        encode = true;
    }
    else if (strcasecmp(argv[1], "d")==0) {
        encode = false;
    }
    else {
        cout << "Invalid arguments. Please see README.md for proper usage" << endl;
        return 1;
    }

    cout << endl;

    //option parameter
    if (strcasecmp(argv[2], "b")==0&&encode) {
        cout << encObj.binaryEncode() << endl;
    }
    else if (strcasecmp(argv[2], "br")==0&&encode) {
        queue<string> results = encObj.binaryEncodeRot();
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
    else if (strcasecmp(argv[2], "bf")==0) {
        cout << encObj.binaryFlip() << endl;
    }
    else if (strcasecmp(argv[2], "b")==0&&!encode) {
        cout << encObj.binaryDecode() << endl;
    }
    else if (strcasecmp(argv[2], "br")==0&&!encode) {
        queue<string> results = encObj.binaryDecodeRot();
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
    else if (strcasecmp(argv[2], "c")==0&&encode) {
        cout << encObj.caesarEncode() << endl;
    }
    else if (strcasecmp(argv[2], "c")==0&&!encode) {
        cout << encObj.caesarDecode() << endl;
    }
    else {
        cout << "Invalid option. Please see README.md for proper usage" << endl;
        return 1;
    }
    
    return 0;
}