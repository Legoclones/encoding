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
        any string of characters
    @return
        a string of non-delimited binary values for each character of TEXT
*/
string EncodingObj::asciiToBinary(string str) {
    string returnVal = "";
    for (int i = 0; i < str.length(); i++) {
        int charCode = int(str[i]);
        returnVal+=decimalToBinary(charCode, true);
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
string EncodingObj::decimalToBinary(int num, bool eight) {
    stack<string> binaryStack;
    while (num!=0) {
        binaryStack.push(to_string(num%2));
        num/=2;
    }

    string returnVal = "";
    int loop = binaryStack.size();

    if (eight) {
        for (int i = 0; i < 8-loop; i++) {
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
        returnVal = decimalToBinary(num, false);
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
    return "Coming soon";
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
    queue<stack<char>> myQueue;
    stringstream ss(str);

    string token;
    while (ss >> token) {
        string hex = token.c_str();

        stack<char> tmp;
        for (int i = 0; i < hex.length(); i++) {
            tmp.push(hex[i]);
        }
        myQueue.push(tmp);
    }
    
    for (int i = 0; !myQueue.empty(); ++i) {
        int charCode = 0;
        for (int j = 0; !myQueue.front().empty(); j++) {
            int val = hexadecimalToDecimal(myQueue.front().top());
            if (val==-1) {
                return "Invalid string";
            }
            charCode += pow(16, j)*val;
            myQueue.front().pop();
        }
        if (charCode>126||charCode<32) {
            charCode = 46;
        }

        char character = charCode;
        returnVal += character;
        myQueue.pop();
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
        string hex = "";
        int charCode = str[i];

        while (charCode>15) {
            int remainderDecimal = charCode%16;
            hex.insert(0,decimalToHexadecimal(remainderDecimal));
            charCode /= 16;
        }
        int remainderDecimal = charCode%16;
        hex.insert(0,decimalToHexadecimal(remainderDecimal));
        returnVal += hex + " ";
    }

    return returnVal;
}

/*
    @param
        an decimal integer between 0 and 15
    @return
        the corresponding hex value as a string
*/
string EncodingObj::decimalToHexadecimal(int digit) {
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
int EncodingObj::hexadecimalToDecimal(char character) {
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
    return "Coming soon...";
}

/*
    @param
        none
    @return
        the hexadecimal equivalent of a decimal value
*/
int EncodingObj::hexadecimalToDecimal() {
    return -1;
}


/*
    SECTION 6 - BASE64
*/


/*
    SECTION 7 - DECODE ALL
*/

