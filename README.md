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
> this_is_my_inserted_text
...
```

To remove the binary file after being compiled and run, use this command:

`make clean`

## Binary (Option b)
Binary encoding example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc e b
> What's your name?

0101011101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111
```
The long string of 0s and 1s contains 17 8-digit segments because the length of the inputted text (`What's your name?`) is 17 characters, including spaces and digits. 

For example, the first character in the text is `W`. It's corresponding decimal ASCII number is 87 (see [www.asciitable.com](http://www.asciitable.com/)). 87 in binary is 01010111, so `01010111` is added to the beginning of the output string. It performs that same operation for each character until the long, final output string is printed to the console. 


Binary decoding example:
```
user@comp_name:~/encoding$ make
user@comp_name:~/encoding$ ./enc d b
> 0101011101101000011000010111010000100111011100110010000001111001011011110111010101110010001000000110111001100001011011010110010100111111

Successful and complete conversion: What's your name?
```
The decoding process does the exact opposite of the encoding process - it takes each 8-digit string of 0s and 1s, turns it back into base 10 or decimal, and then converts that back to the corresponding character. For example, the first 8 digits in the string are `01010111`, which 87 in decimal or base 10, and that corresponds to the capital W, so `W` is added to the output string. 

All characters with decimal values under 31 are non-printable characters that will make the terminal act weird. If there are any inputted binary values that end up less than 32, the console will print out `Non-printable characters converted to ?s` and will replace each occurence of a non-printable character with `?`. If there are no non-printable characters, it will print out the message `Successful and complete conversion`.

## Binary Rotation (Option br)


## Binary Flip (Option bf)


## Caesar Shift (Option b)
