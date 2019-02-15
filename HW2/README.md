CS253 HW2: More datatypes, tagging                

Description                
Write a C++ program called hw2 that behaves as the program from from HW1, except that it:

reads from multiple files given as command-line arguments
reads chars and strings, in addition to integers
produces tagged output
does not echo the original value, just the serialized version.
Tagged Output                
Now, instead of simply producing vnums, the program will produce tagged output. Each vnum will be preceded by an identifying character:

s: short (fits in a signed 16-bit integer)
i: int (fits in a signed 32-bit integer)
l: long (fits in a signed 64-bit integer)
c: char (a single eight-bit character)
S: string (a string of characters)
The program must figure out which category (short/int/long) a number should go into.                 

For example, the number three, since it fits into a short, would be tagged with an s, thus: 73 03                 

The number one billion, which fits into an int, would be tagged with an i, thus: 69 40 3b 9a ca 00                 

The serialized output for a character is simply a c followed by the character. For example, 'x' would be serialized as: 63 78                 

A string is serialized as follows:

a capital S
an untagged vnum that represents the length of the string in bytes
the bytes of the string
For example, "Jack" would be serialized as: 53 04 4a 61 63 6b 
Don’t be fooled by 04. That is not a simple byte containing the value 4. That is a vnum that happens to be a single byte, because 4 (the length of “Jack”) fits into the bottom four bits of a vnum. A longer string might have a multibyte vnum representing its length.                 
