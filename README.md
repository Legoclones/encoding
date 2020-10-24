# Encoding/Decoding Program README
This program is written in C++ to encode and decode text. It's written to be used in the Linux terminal. You specify whether you want to encode or decode the data, followed by the option. There are currently 5 different options:

* Option `b` (enc/dec) - each character in the inputted text is encoded to or decoded from their 8-digit binary ASCII code
* Option `br` (enc/dec) - the above option is run, but the code moves the first character to the end of the text 7 times
* Option `bf` - each 0 in the inputted text are turned into 1s, and viceversa
* Option `c #` (enc/dec) - each character in the inputted is rotated a certain number of characters over, as specific by the #

Specifying encode/decode and option must be done as commandline arguments. The text is entered into a second line after pressing ENTER. See below for specifics. 

To compile the program with the makefile, run this in the terminal:

`make`

To run the program, enter this into the terminal (after compiling):

`./enc [e/d] [option]`

followed by entering the text once the greater than sign (`>`) appears. 

Example:

```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc d b
text> this_is_my_inserted_text
...
```

To remove the binary file after being compiled and run, use this command:

`make clean`

## Binary (Option b)
Binary encoding example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc e b
text> What's your name?

0101011101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111
```
The long string of 0s and 1s contains 17 8-digit segments because the length of the inputted text (`What's your name?`) is 17 characters, including spaces and digits. 

For example, the first character in the text is `W`. It's corresponding decimal ASCII number is 87 (see [www.asciitable.com](http://www.asciitable.com/)). 87 in binary is 01010111, so `01010111` is added to the beginning of the output string. It performs that same operation for each character until the long, final output string is printed to the console. 


Binary decoding example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc d b
text> 0101011101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111

Successful and complete conversion:              What's your name?
```
The decoding process does the exact opposite of the encoding process - it takes each 8-digit string of 0s and 1s, turns it back into base 10 or decimal, and then converts that back to the corresponding character. For example, the first 8 digits in the string are `01010111`, which 87 in decimal or base 10, and that corresponds to the capital W, so `W` is added to the output string. 

All characters with decimal values under 31 are non-printable characters that will make the terminal act weird. If there are any inputted binary values that end up less than 32, the console will print out `Non-printable characters converted to periods` and will replace each occurence of a non-printable character with `.`. If there are no non-printable characters, it will print out the message `Successful and complete conversion`.

## Binary Rotation (Option br)
Binary rotation encoding example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc e br
text> What's your name?

0101011101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111
1010111011010000110000101110100001001110111001100100000011110010110111101110101011100100010000001101110011000010110110101100101001111110
0101110110100001100001011101000010011101110011001000000111100101101111011101010111001000100000011011100110000101101101011001010011111101
1011101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111010
0111011010000110000101110100001001110111001100100000011110010110111101110101011100100010000001101110011000010110110101100101001111110101
1110110100001100001011101000010011101110011001000000111100101101111011101010111001000100000011011100110000101101101011001010011111101010
1101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111010101
1011010000110000101110100001001110111001100100000011110010110111101110101011100100010000001101110011000010110110101100101001111110101011
```
Binary rotations performs the Binary Encoding operation on the text, then prints it out 8 times, transferring one binary character from the front of the text to the back. The line on top is the binary encoding of the text WITHOUT moving any characters. 


Binary rotation decoding example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc d br
text> 1011101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111010

Non-printable characters converted to periods:   .C..;...{...s.k).
Non-printable characters converted to periods:   v..Bw2...W"....S.
Non-printable characters converted to periods:   .....d.-..D..-...
Non-printable characters converted to periods:   ..]....[.\...[YO.
Non-printable characters converted to periods:   .0....<....70....
Successful and complete conversion:              hat's your name?W
Non-printable characters converted to periods:   ...N.@....@....~.
Non-printable characters converted to periods:   ................]
```
Binary decoding rotations performs the binary decoding operation on the text, then prints it out 8 times, transferring one binary character from the front of the text to the back. The line on top is the binary decoding of the text WITHOUT moving any 0s or 1s. 

You will note that sometimes the actual message has characters out of order, but the message should be easily recognizable. 

## Binary Flip (Option bf)
Binary flip example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc e bf
text> 1011101101000011

0100010010111100
```
Each 0 in the text is converted to a 1, and viceversa. Note - it doesn't matter whether you put `e` or `d`, both will perform the same operation. 

## Caesar Shift (Option b)
Coming soon...