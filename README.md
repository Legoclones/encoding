# Encryption/Decryption Program README
This program is written in C++ to encrypt and decrypt various codes. It's written to be used in the Linux terminal. You specify whether you want to encrypt or decrypt the data, followed by the option. There are currently 5 different options:

* Option `b` (enc/dec) - each character in the inputted text is encoded to or decrypted from their 8-digit binary ASCII code
* Option `br` (enc/dec) - the above option is run, but the code moves the first character to the end of the text 7 times
* Option `bf` - each 0 in the inputted text are turned into 1s, and viceversa
* Option `c #` (enc/dec) - each character in the inputted is rotated a certain number of characters over, as specific by the #
* Option `v [passphrase]` (enc/dec) - the inputted text is encrypted or decrypted based on the following passphrase

Specifying encrypt/decrypt and option must be done as commandline arguments. The text is entered into a second line after pressing ENTER. See below for specifics. 

To compile the program with the makefile, run this in the terminal:

`make`

To run the program, enter this into the terminal (after compiling):

`./enc [e/d] [option]`

followed by entering the text once the greater than sign (`>`) appears. 

Example:

```
user@comp_name:~/encryption$ make
user@comp_name:~/encryption$ ./enc d b
> this_is_my_inserted_text
...
```

To remove the binary file after being compiled and run, use this command:

`make clean`

## Option specifics/examples