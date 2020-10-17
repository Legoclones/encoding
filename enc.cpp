#include <iostream>
#include <string>
#include "EncryptionObj.h"

using namespace std;

/*
    usage: enc [e/d] [option] + ENTER
    >[insert text here] + ENTER
*/
int main(int argc, char* argv[]) {
    EncryptionObj encObj("adsliufhiasd");

    cout << encObj.binaryEncrypt() << endl;
    
    
    cout << "hello world" << endl;
    return 0;
}