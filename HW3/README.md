Description                
Write a C++ program called hw3 that behaves like HW2, except that it accepts command-line options:                 

-s            serialize: the default behavior, similar to HW2
-u            unserialize: convert from serialized format (like HW2’s output) to unserialized format (like HW2’s input)
-v            verbosely announce each file, just before attempting to open it, to stderr, in this manner:
       
Processing file filename-goes-here
Terminology                
"Unserialized" data refers to human-readable form, e.g., 42, 'x', "Moriarty".                 

"Serialized" data refers to tagged hexadecimal data. In the future, we may represent serialized data more efficiently.                 

Booleans                
It is now possible to serialize boolean values. They are represented as the words true & false in unserialized format. In serialized format, their tag characters are t & f, with no data following, because t & f say it all.                 
