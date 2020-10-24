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


## Binary Rotation (Option br)


## Binary Flip (Option bf)


## Caesar Shift (Option b)
