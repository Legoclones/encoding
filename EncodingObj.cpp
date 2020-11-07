#include "EncodingObj.h"

EncodingObj::EncodingObj(string textArg) {
    text = textArg;
}

/*
    @param
        none
    @return
        the class variable TEXT as a string
*/
string EncodingObj::getText() {
    return text;
}

/*
    @param 1 
        any character
    @return
        an 8-digit binary string based on ASCII values
*/
string EncodingObj::base10ToBinary(char myChar) {
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
    @param 
        none
    @return
        a string of non-delimited binary values for each character of TEXT
*/
string EncodingObj::binaryEncode() {
    return binaryEncode(text);
}

/*
    @param 
        any string of characters
    @return
        a string of non-delimited binary values for each character of TEXT
*/
string EncodingObj::binaryEncode(string str) {
    string returnVal = "";
    for (int i = 0; i < str.length(); i++) {
        returnVal+=base10ToBinary(str[i]);
    }
    return returnVal;
}

/*
    @param 
        none
    @return
        a queue of strings of non-delimited binary values for each character of TEXT, 
        where the first digit was put to the back of the original text, or rotated
*/
queue<string> EncodingObj::binaryEncodeRot() {
    queue<string> returnVal;
    string tmp = binaryEncode(text);

    for (int i = 0; i < 8; i++) {
        returnVal.push(tmp);
        tmp = tmp.substr(1)+tmp.substr(0,1);
    }

    return returnVal;
}

/*
    @param 
        none
    @return
        a string where each 0s become 1s and 1s become 0s
*/
string EncodingObj::binaryFlip() {
    string returnVal = "";

    for (int i = 0; i < text.length(); i++) {
        if (text[i]=='0') {
            returnVal+="1";
        }
        else if (text[i]=='1') {
            returnVal+="0";
        }
        else {
            return "Invalid characters";
        }
    }

    return returnVal;
}

/*
    @param 
        none
    @return
        a decoded string of characters taken from the non-delimited string of binary values
*/
string EncodingObj::binaryDecode() {    
    return binaryDecode(text);
}

/*
    @param 
        unencoded, non-delimited, 8-digit binary string of 0s and 1s
    @return
        a decoded string of characters
*/
string EncodingObj::binaryDecode(string str) {    
    string returnVal = "";

    if (str.length()<8) {
        return "Insufficient characters";
    }
    for (int i = 0; i < str.length(); i++) {
        if (str[i]!='0'&&str[i]!='1') {
            return "Invalid character(s)"; 
        }
    }

    string tmp = "";
    for (int i = 0; i < str.length()/8; i++) {
        string binary = str.substr(8*i, 8);
        char character;

        int charCode = 0;
        int val = 128;
        for (int j = 0; j < 8; j++) {
            charCode+=(val*(binary[j]-'0'));
            val/=2;
        }
        if (charCode>126||charCode<32) {
            charCode = 46;
        }
        character = charCode;
        tmp+=character;
    }
    returnVal+=tmp;
    
    return returnVal;
}

/*
    @param
        none
    @return
        a queue of decoded strings of characters, where the first digit was put 
        to the back of the original text, or rotated
*/
queue<string> EncodingObj::binaryDecodeRot() {
    queue<string> returnVal;
    string tmp = text;

    for (int i = 0; i < 8; i++) {
        returnVal.push(binaryDecode(tmp));
        tmp = tmp.substr(1)+tmp.substr(0,1);
    }

    return returnVal;
}

/*
    @param
        a string to be shifted and a integer for how many characters over it should be shifted
    @return
        a Caesar-shifted string
*/
string EncodingObj::caesarShift(string str, int n) {
    string returnVal = "";

    for (int i = 0; i < str.length(); i++) {
        int charCode = int(str[i]);
        if (!((charCode>64 && charCode<91) || (charCode>96 && charCode<123))) {
            int newCharCode = charCode+n;

            if (charCode>64 && charCode<91 && newCharCode>90) {
                newCharCode-=26;
            }
            else if (charCode>64 && charCode<91 && newCharCode<65) {
                newCharCode+=26;
            }
            if (charCode>96 && charCode<123 && newCharCode>122) {
                newCharCode-=26;
            }
            else if (charCode>96 && charCode<123 && newCharCode<97) {
                newCharCode+=26;
            }

            char character = newCharCode;
            returnVal+=character;
        }
        else {
            char character = charCode;
            returnVal+=character;
        }
    }
    
    return returnVal;
}

/*
    @param none
    @return
        ?
*/
queue<string> EncodingObj::caesarEncode() {
    queue<string> returnVal;
    return returnVal;
}

/*
    @param none
    @return
        ?
*/
queue<string> EncodingObj::caesarDecode() {
    queue<string> returnVal;
    return returnVal;
}