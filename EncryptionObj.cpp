#include "EncryptionObj.h"

EncryptionObj::EncryptionObj(string textArg) {
    text = textArg;
}

/*
    @param none
    @return
        the class variable TEXT as a string
*/
string EncryptionObj::getText() {
    return text;
}

/*
    @param 1 
        any character
    @return
        an 8-digit binary string based on ASCII values
*/
string EncryptionObj::base10ToBinary(char myChar) {
    int charCode = int(myChar);

    stack<string> binaryStack;
    while (charCode!=0) {
        binaryStack.push(to_string(charCode%2));
        charCode/=2;
    }

    string returnVal = "";
    int loop = binaryStack.size();

    for (int i = 0; i < 8-loop; i++) {
        returnVal+="0";
    }

    for (int i = 0; i < loop; i++) {
        returnVal+=binaryStack.top();
        binaryStack.pop();
    }
    return returnVal;
}

/*
    @param none
    @return
        a string of non-delimited binary values for each character of TEXT
*/
string EncryptionObj::binaryEncrypt() {
    string returnVal = "";
    for (int i = 0; i < text.length(); i++) {
        returnVal+=base10ToBinary(text[i]);
    }
    return returnVal;
}

/*
    @param none
    @return
        ?
*/
string EncryptionObj::binaryDecrypt() {
    return "Not completed yet";
}

/*
    @param none
    @return
        ?
*/
string EncryptionObj::caesarEncrypt() {
    return "Not completed yet";
}

/*
    @param none
    @return
        ?
*/
string EncryptionObj::caesarDecrypt() {
    return "Not completed yet";
}

/*
    @param none
    @return
        ?
*/
string EncryptionObj::vigenereEncrypt() {
    return "Not completed yet";
}

/*
    @param none
    @return
        ?
*/
string EncryptionObj::vigenereDecrypt() {
    return "Not completed yet";
}