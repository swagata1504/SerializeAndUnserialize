Description                
For this assignment, you will write a C++ program called hw1 that reads integers from standard input, translates them to a serialized format, and writes the two-digit hexadecimal form of the serialized numbers to standard output, one per line.                 

Definition of a vnum                
We define a vnum, or variable-length number, as a two’s complement, variable number of bits (but always of the length 8n+4, where n≥0), prefixed by a four-bit length. The output will always be a whole number of bytes, or a multiple of eight bits.                 

You can consider the length nibble to be either:

the number of bytes-1, including the first byte
the number of additional bytes needed, after the first one.
For example, the number five, in binary, is 1012. We need to pad that to a length of 8n+4. Since it’s three bits long, we pad it on the left to four bits: 01012. This requires no additional bytes, so the four-bit length is zero, or 00002. Put those together: 0000 01012, or 0516.                 

The number three hundred, in binary, is 1 0010 11002. Padded to length 8n+4, that is 0001 0010 11002. This requires two bytes, or one additional byte, so the four-bit length is one, or 00012. Put those together: 0001 0001 0010 11002, or 112c16.                 

The number negative one, in two’s complement binary, is 11112. This requires no additional bytes, so the four-bit length is zero, or 00002. Put those together: 0000 11112, or 0f16.                 

A vnum must always be the represented using the minimum number of bytes. For example, seven must serialize as 0716, not as 30 00 00 0716.          
