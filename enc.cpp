#include <iostream>
#include <string>
#include <queue>
#include "EncryptionObj.h"

using namespace std;

/*
    usage: enc [e/d] [option] + ENTER
    >[insert text here] + ENTER
*/
int main(int argc, char* argv[]) {
    EncryptionObj encObj("adsliufhiasd");
    EncryptionObj encObj2("01100001011001000111001101101100");

    string results = encObj2.binaryDecrypt();

    cout << results << endl;

    queue<string> results2 = encObj2.binaryDecryptRot();

    while (!results2.empty()) {
        cout << results2.front() << endl;
        results2.pop();
    }
    
    return 0;
}