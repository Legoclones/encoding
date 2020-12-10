#include "EncodingObj.h"

/*
    SECTION 1 - INITIALIZERS/DESTRUCTORS
*/

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
    SECTION 2 - BINARY
*/

/*
    @param 
        unencoded, non-delimited, 8-digit binary string of 0s and 1s
    @return
        a decoded string of characters
*/
string EncodingObj::binaryToAscii(string str) {    
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
        char character = binaryToDecimal(str.substr(8*i, 8));
        if (character>126||character<32) {
            character = 46;
        }
        tmp+=character;
    }
    returnVal+=tmp;
    
    return returnVal;
}

/*
    @param 
        any string of binary values
    @return
        the decimal equivalent as an integer
*/
int EncodingObj::binaryToDecimal(string str) {
    int charCode = 0;
    int val = pow(2, str.length()-1);
    for (int j = 0; j < str.length(); j++) {
        charCode+=(val*(str[j]-'0'));
        val/=2;
    }
    return charCode;
}

/*
    @param 
        any string of characters
    @return
        a string of non-delimited binary values for each character of TEXT
*/
string EncodingObj::asciiToBinary(string str) {
    string returnVal = "";
    for (int i = 0; i < str.length(); i++) {
        int charCode = int(str[i]);
        returnVal+=decimalToBinary(charCode, 8);
    }
    return returnVal;
}

/*
    @param 1 
        a decimal number
    @param 2
        a boolean that determines whether the desired return value should have 8 digits or not (padded 0's)
    @return
        a binary number
*/
string EncodingObj::decimalToBinary(int num, int leadZero) {
    stack<string> binaryStack;
    while (num!=0) {
        binaryStack.push(to_string(num%2));
        num/=2;
    }

    string returnVal = "";
    int loop = binaryStack.size();

    if (leadZero>0) {
        for (int i = 0; i < leadZero-loop; i++) {
            returnVal+="0";
        }
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
string EncodingObj::asciiToBinary() {
    return asciiToBinary(text);
}

/*
    @param 
        none
    @return
        a queue of strings of non-delimited binary values for each character of TEXT, 
        where the first digit was put to the back of the original text, or rotated
*/
queue<string> EncodingObj::asciiToBinaryAll() {
    queue<string> returnVal;
    string tmp = asciiToBinary(text);

    for (int i = 0; i < 8; i++) {
        returnVal.push(tmp);
        tmp = tmp.substr(1)+tmp.substr(0,1);
    }

    return returnVal;
}

/*
    @param none
    @return
        the binary equivalent of a decimal number
*/
string EncodingObj::decimalToBinary() {
    string returnVal;
    try {
        int num = stoi(text);
        returnVal = decimalToBinary(num, 0);
    }
    catch (...) {
        returnVal = "Invalid input";
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
string EncodingObj::binaryToAscii() {    
    return binaryToAscii(text);
}

/*
    @param
        none
    @return
        a queue of decoded strings of characters, where the first digit was put 
        to the back of the original text, or rotated
*/
queue<string> EncodingObj::binaryToAsciiAll() {
    queue<string> returnVal;
    string tmp = text;

    for (int i = 0; i < 8; i++) {
        returnVal.push(binaryToAscii(tmp));
        tmp = tmp.substr(1)+tmp.substr(0,1);
    }

    return returnVal;
}

/*
    @param
        none
    @return
        the decimal equivalent of a binary number
*/
string EncodingObj::binaryToDecimal() {
    for (int i = 0; i < text.length(); i++) {
        if (text[i]!='0'&&text[i]!='1') {
            return "Invalid characters";
        }
    }
    return to_string(binaryToDecimal(text));
}


/*
    SECTION 3 - CAESAR SHIFT
*/

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
        if ((charCode>64 && charCode<91) || (charCode>96 && charCode<123)) {
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
        a queue of strings shifted a certain number of characters to the right
*/
queue<string> EncodingObj::caesarEncode() {
    queue<string> returnVal;

    for (int i = 0; i < 26; i++) {
        returnVal.push(caesarShift(text, i));
    }

    return returnVal;
}

/*
    @param none
    @return
        a queue of strings shifted a certain number of characters to the right
*/
queue<string> EncodingObj::caesarDecode() {
    queue<string> returnVal;
    
    for (int i = 0; i < 26; i++) {
        returnVal.push(caesarShift(text, -i));
    }

    return returnVal;
}


/*
    SECTION 4 - TEXT FLIP
*/

/*
    @param
        a string to be flipped
    @return
        a flipped string
*/
string EncodingObj::textFlip(string str) {
    string returnVal;
    stack<char> myStack;
    
    for (int i = 0; i < str.length(); i++) {
        myStack.push(str[i]);
    }
    while (!myStack.empty()) {
        returnVal+=myStack.top();
        myStack.pop();
    }

    return returnVal;
}

/*
    @param none
    @return
        a flipped string
*/
string EncodingObj::textFlip() {
    return textFlip(text);
}


/*
    SECTION 5 - HEXADECIMAL
*/

/*
    @param
        a space-delimited string of hex values
    @return
        the string decoded into ASCII form
*/
string EncodingObj::hexadecimalToAscii(string str) {
    string returnVal;
    stringstream ss(str);

    string token;
    while (ss >> token) {
        int charCode = hexadecimalToDecimal(token.c_str());
        char character = charCode;
        returnVal += character;
    }

    return returnVal;
}

/*
    @param
        an ASCII string
    @return
        the parameter string returned in hex values
*/
string EncodingObj::asciiToHexadecimal(string str) {
    string returnVal;

    for (int i = 0; i < str.length(); i++) {
        int charCode = str[i];
        returnVal += decimalToHexadecimal(charCode) + " ";
    }

    return returnVal;
}

/*
    @param
        any integer
    @return
        the hexadecimal equivalent
*/
string EncodingObj::decimalToHexadecimal(int num) {
    stack<string> myStack;
    while (num!=0) {
        myStack.push(decCharToHexChar(num%16));
        num/=16;
    }

    string returnVal = "";
    int loop = myStack.size();

    for (int i = 0; i < loop; i++) {
        returnVal+=myStack.top();
        myStack.pop();
    }
    return returnVal;
}

/*
    @param
        a string of hexadecimal values
    @return
        the decimal equivalent
*/
int EncodingObj::hexadecimalToDecimal(string str) {
    int returnVal = 0;
    int val = pow(16, str.length()-1);
    for (int j = 0; j < str.length(); j++) {
        returnVal+=(val*hexCharToDecChar(str[j]));
        val/=16;
    }
    return returnVal;
}

/*
    @param
        an decimal integer between 0 and 15
    @return
        the corresponding hex value as a string
*/
string EncodingObj::decCharToHexChar(int digit) {
    string returnVal;
    if (digit>=0&&digit<10) {
        returnVal = to_string(digit);
        return returnVal;
    }
    else if (digit==10) {
        return "a";
    }
    else if (digit==11) {
        return "b";
    }
    else if (digit==12) {
        return "c";
    }
    else if (digit==13) {
        return "d";
    }
    else if (digit==14) {
        return "e";
    }
    else if (digit==15) {
        return "f";
    }
    else {
        return ".";
    }
}

/*
    @param
        a hexadecimal character
    @return
        its corresponding decimal integer
*/
int EncodingObj::hexCharToDecChar(char character) {
    string digits = "0123456789";
    if (digits.find(character)!=string::npos) {
        return character - '0';
    }
    else if (character=='a'||character=='A') {
        return 10;
    }
    else if (character=='b'||character=='B') {
        return 11;
    }
    else if (character=='c'||character=='C') {
        return 12;
    }
    else if (character=='d'||character=='D') {
        return 13;
    }
    else if (character=='e'||character=='E') {
        return 14;
    }
    else if (character=='f'||character=='F') {
        return 15;
    }
    else {
        return -1;
    }
}

/*
    @param
        none
    @return
        the string decoded into ASCII form
*/
string EncodingObj::hexadecimalToAscii() {
    return hexadecimalToAscii(text);
}

/*
    @param
        none
    @return
        data member 'text' returned in hex values
*/
string EncodingObj::asciiToHexadecimal() {
    return asciiToHexadecimal(text);
}

/*
    @param
        none
    @return
        the decimal equivalent of a hexadecimal value
*/
string EncodingObj::decimalToHexadecimal() {
    int value;
    try {
        value = stoi(text);
    }
    catch (...) {
        return "Invalid characters";
    }
    return decimalToHexadecimal(value);
}

/*
    @param
        none
    @return
        the hexadecimal equivalent of a decimal value
*/
int EncodingObj::hexadecimalToDecimal() {
    for (int i = 0; i < text.length(); i++) {
        if (hexCharToDecChar(text[i])==-1) {
            return -1;
        }
    }
    return hexadecimalToDecimal(text);
}


/*
    SECTION 6 - ASCII/DECIMAL
*/

/*
    @param
        none
    @return
        ASCII characters based on their decimal equivalent
*/
string EncodingObj::decimalToAscii() {
    string returnVal = "";
    stringstream ss(text);

    string token;
    while (ss >> token) {
        int charCode;
        try {
            charCode = stoi(token);
        }
        catch (...) {
            return "Invalid input";
        }
        if (charCode<32||charCode>126) {
            charCode = 46;
        }
        char character = charCode;
        returnVal += character;
    }

    return returnVal;
}

/*
    @param
        none
    @return
        a space-delimited string of the decimal equivalents of each ASCII character
*/
string EncodingObj::asciiToDecimal() {
    string returnVal = "";

    for (int i = 0; i < text.length(); i++) {
        int charCode = text[i];
        returnVal += to_string(charCode) + " ";
    }
    return returnVal;
}


/*
    SECTION 7 - BASE64
*/

/*
    @param
        a plaintext string
    @return
        the base64 equivalent of the plaintext string
*/
string EncodingObj::base64Encode(string str) {
    string returnVal = "";
    string base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    string binary  = asciiToBinary(str);
    int loop = 6-(binary.length()%6);
    for (int i = 0; i < loop; i++) {
        binary+="0";
    }

    for (int i = 0; i < binary.length()/6; i++) {
        int dec = binaryToDecimal(binary.substr(6*i, 6));
        returnVal += base64[dec];
    }

    loop = 4-(returnVal.length()%4);
    for (int i = 0; i < loop; i++) {
        returnVal+="=";
    }

    return returnVal;
}

/*
    @param
        a base64-encoded string
    @return
        the inputted code's plaintext equivalent
*/
string EncodingObj::base64Decode(string str) {
    string returnVal = "";
    string base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    string binary = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '=') {
            int code = base64.find(str[i]);
            if (code==-1) {
                return "Invalid characters";
            }
            binary+=decimalToBinary(code, 6);
        }
    }
    return binaryToAscii(binary);
}

/*
    @param
        none
    @return
        the base64 equivalent of plaintext
*/
string EncodingObj::base64Encode() {
    return base64Encode(text);
}

/*
    @param
        none
    @return
        a string of base64-encoded information turned back into plaintext
*/
string EncodingObj::base64Decode() {
    return base64Decode(text);
}


/*
    SECTION 8 - BYTES
*/

/*
    @param
        a string in byte form
    @return
        a string of values translated from byte form (spaces removed)
*/
string EncodingObj::fromBytes(string str) {
    string returnVal = "";
    stringstream ss(text);

    string token;
    while (ss >> token) {
        returnVal += token;
    }

    return returnVal;
}

/*
    @param
        none
    @return
        a string of hexadecimal values translated into byte form
*/
string EncodingObj::hexadecimalToBytes() {
    string returnVal = "";

    if (text.length()%2==1) {
        text = "0" + text;
    }

    for (int i = 0; i < text.length()/2; i++) {
        returnVal += text.substr(i*2, 2) + " ";
    }
    return returnVal;
}

/*
    @param
        none
    @return
        a string of hexadecimal values translated from byte form
*/
string EncodingObj::hexadecimalFromBytes() {
    return fromBytes(text);
}

/*
    @param
        none
    @return
        a string of binary values translated into byte form
*/
string EncodingObj::binaryToBytes() {
    string returnVal = "";

    int remainder = text.length()%8;
    if (remainder!=0) {
        for (int i = 0; i < 8-remainder; i++) {
            text = "0" + text;
        }
    }

    for (int i = 0; i < text.length()/8; i++) {
        returnVal += text.substr(i*8, 8) + " ";
    }
    return returnVal;
}

/*
    @param
        none
    @return
        a string of binary values translated from byte form
*/
string EncodingObj::binaryFromBytes() {
    return fromBytes(text);
}


/*
    SECTION 9 - XOR
*/
