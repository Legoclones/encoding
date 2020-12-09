# Encoding/Decoding Program README
This program is written in C++ to encode and decode text using various methods. It's written to be used in the Linux terminal and g++ compiler.

To compile the program with the makefile, run this in the terminal:

`make`

To run the program, enter this into the terminal (after compiling):

`./enc [option]`

followed by entering the text once the greater than sign (`>`) appears. 

Example:

```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc a2h
text> this_is_my_inserted_text
...
```

To remove the binary file after being compiled and run, use this command:

`make clean`

All options:
* [ASCII to Binary](#ascii-to-binary) - `a2b`
* [ASCII to Binary (all)](#ascii-to-binary-all) - `a2ba`
* [ASCII to Decimal](#ascii-to-decimal) - `a2d`
* [ASCII to Hexadecimal](#ascii-to-hexadecimal) - `a2h`
* [Base64 Encode](#base64-encode) - `b64e`
* [Base64 Decode](#base64-decode) - `b64d`
* [Binary Flip](#binary-flip) - `bf`
* [Binary to ASCII](#binary-to-ascii) - `b2a`
* [Binary to ASCII (all)](#binary-to-ascii-all) - `b2aa`
* [Binary to Decimal](#binary-to-decimal) - `b2d`
* [Caesar Shift Encode](#caesar-shift-encode) - `ce`
* [Caesar Shift Decode](#caesar-shift-decode) - `cd`
* [Decimal to ASCII](#decimal-to-ascii) - `d2a`
* [Decimal to Binary](#decimal-to-binary) -  `d2b`
* [Decimal to Hexadecimal](#decimal-to-hexadecimal) - `d2h`
* [Hexadecimal to ASCII](#hexadecimal-to-ascii) - `h2a`
* [Hexadecimal to Decimal](#hexadecimal-to-decimal) - `h2d`
* [Text Flip](#text-flip) -  `tf`

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

0 digits rotated: 0101011101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111
1 digit rotated:  1010111011010000110000101110100001001110111001100100000011110010110111101110101011100100010000001101110011000010110110101100101001111110
2 digits rotated: 0101110110100001100001011101000010011101110011001000000111100101101111011101010111001000100000011011100110000101101101011001010011111101
3 digits rotated: 1011101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111010
4 digits rotated: 0111011010000110000101110100001001110111001100100000011110010110111101110101011100100010000001101110011000010110110101100101001111110101
5 digits rotated: 1110110100001100001011101000010011101110011001000000111100101101111011101010111001000100000011011100110000101101101011001010011111101010
6 digits rotated: 1101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111010101
7 digits rotated: 1011010000110000101110100001001110111001100100000011110010110111101110101011100100010000001101110011000010110110101100101001111110101011
```
Binary rotations performs the binary encoding operation on the text, then prints it out 8 times, transferring one binary character from the front of the text to the back. The line on top is the binary encoding of the text WITHOUT moving any characters. 


Binary rotation decoding example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc d br
text> 1011101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111010

0 digits rotated: .C..;...{...s.k).
1 digit rotated:  v..Bw2...W"....S.
2 digits rotated: .....d.-..D..-...
3 digits rotated: ..]....[.\...[YO.
4 digits rotated: .0....<....70....
5 digits rotated: hat's your name?W
6 digits rotated: ...N.@....@....~.
7 digits rotated: ................]
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

## Caesar Shift (Option c)
Caesar shift encoding example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc e c
text> Hi! What's your name?

0 characters shifted: Hi! What's your name?
1 character shifted:  Ij! Xibu't zpvs obnf?
2 characters shifted: Jk! Yjcv'u aqwt pcog?
3 characters shifted: Kl! Zkdw'v brxu qdph?
4 characters shifted: Lm! Alex'w csyv reqi?
5 characters shifted: Mn! Bmfy'x dtzw sfrj?
6 characters shifted: No! Cngz'y euax tgsk?
7 characters shifted: Op! Doha'z fvby uhtl?
8 characters shifted: Pq! Epib'a gwcz vium?
9 characters shifted: Qr! Fqjc'b hxda wjvn?
10 characters shifted: Rs! Grkd'c iyeb xkwo?
11 characters shifted: St! Hsle'd jzfc ylxp?
12 characters shifted: Tu! Itmf'e kagd zmyq?
13 characters shifted: Uv! Jung'f lbhe anzr?
14 characters shifted: Vw! Kvoh'g mcif boas?
15 characters shifted: Wx! Lwpi'h ndjg cpbt?
16 characters shifted: Xy! Mxqj'i oekh dqcu?
17 characters shifted: Yz! Nyrk'j pfli erdv?
18 characters shifted: Za! Ozsl'k qgmj fsew?
19 characters shifted: Ab! Patm'l rhnk gtfx?
20 characters shifted: Bc! Qbun'm siol hugy?
21 characters shifted: Cd! Rcvo'n tjpm ivhz?
22 characters shifted: De! Sdwp'o ukqn jwia?
23 characters shifted: Ef! Texq'p vlro kxjb?
24 characters shifted: Fg! Ufyr'q wmsp lykc?
25 characters shifted: Gh! Vgzs'r xntq mzld?
```
Caesar shift encoding shifts each character over n characters to the right.  


Caesar shift decoding example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc d c
text> Hi! What's your name?

0 characters shifted: Hi! What's your name?
1 character shifted:  Gh! Vgzs'r xntq mzld?
2 characters shifted: Fg! Ufyr'q wmsp lykc?
3 characters shifted: Ef! Texq'p vlro kxjb?
4 characters shifted: De! Sdwp'o ukqn jwia?
5 characters shifted: Cd! Rcvo'n tjpm ivhz?
6 characters shifted: Bc! Qbun'm siol hugy?
7 characters shifted: Ab! Patm'l rhnk gtfx?
8 characters shifted: Za! Ozsl'k qgmj fsew?
9 characters shifted: Yz! Nyrk'j pfli erdv?
10 characters shifted: Xy! Mxqj'i oekh dqcu?
11 characters shifted: Wx! Lwpi'h ndjg cpbt?
12 characters shifted: Vw! Kvoh'g mcif boas?
13 characters shifted: Uv! Jung'f lbhe anzr?
14 characters shifted: Tu! Itmf'e kagd zmyq?
15 characters shifted: St! Hsle'd jzfc ylxp?
16 characters shifted: Rs! Grkd'c iyeb xkwo?
17 characters shifted: Qr! Fqjc'b hxda wjvn?
18 characters shifted: Pq! Epib'a gwcz vium?
19 characters shifted: Op! Doha'z fvby uhtl?
20 characters shifted: No! Cngz'y euax tgsk?
21 characters shifted: Mn! Bmfy'x dtzw sfrj?
22 characters shifted: Lm! Alex'w csyv reqi?
23 characters shifted: Kl! Zkdw'v brxu qdph?
24 characters shifted: Jk! Yjcv'u aqwt pcog?
25 characters shifted: Ij! Xibu't zpvs obnf?
```
Caesar shift decoding shifts each character over n characters to the left.

## Text Flip (Option tf)
Text flip example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc e tf
text> hey!

!yeh
```
The string is printed out backwards. Note - it doesn't matter whether you put `e` or `d`, both will perform the same operation. 

## Hexadecimal (Option h)
Hexadecimal encoding example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc e h
text> Hi, what's your name?

48 69 2c 20 77 68 61 74 27 73 20 79 6f 75 72 20 6e 61 6d 65 3f
```
Hex encoding takes each character and returns a space-delimited string of the hexadecimal equivalent of the ASCII code for that character.


Hexadecimal decoding example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc d h
text> 48 69 2c 20 77 68 61 74 27 73 20 79 6f 75 72 20 6e 61 6d 65 3f

Hi, what's your name?
```
Hex decoding takes each hexadecimal value and returns its corresponding ASCII character.