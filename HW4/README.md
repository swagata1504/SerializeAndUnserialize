Functions                
void serialize(bool, ostream &)
void serialize(short, ostream &)
void serialize(int, ostream &)
void serialize(long, ostream &)
void serialize(char, ostream &)
void serialize(const string &, ostream &) 
Serialize the datum to a tagged binary value; write it to the ostream.
void unserialize(istream &, bool &)
void unserialize(istream &, short &)
void unserialize(istream &, int &)
void unserialize(istream &, long &)
void unserialize(istream &, char &)
void unserialize(istream &, string &) 
Unserialize a tagged binary value from the istream to the variable.
unserialize throws (in the sense of throw/try/catch) a descriptive std::string if the requested type isn’t the next thing in the input stream. No conversions—short doesn’t match int, and int doesn’t match short.                 

Don’t confuse the base classes ostream and istream with ofstream and ifstream or ostringstream and istringstream.                 

Binary Serialized Format                
In HW3, the tagged short 300 was represented as these eight bytes of hexadecimal digits and spaces:                 

    73 11 2c
Now, the same value will be represented by three bytes. The first byte has the value 0x73, the second byte has the value 0x11, and the third byte has the value 0x2c. No extra spaces, no extra newlines:                 

    output_stream << char(0x73) << char(0x11) << char(0x2c);
These bytes don’t always correspond to printable ASCII values, so you can’t just dump them out to the screen. You have to view them as hex, if you want to understand them. To analyze a file containing such binary values, use the command xxd.                 

Debugging                
If you encounter “STACK FRAME LINK OVERFLOW”, then try this:

    export STACK_FRAME_LINK_OVERRIDE=ffff-ad921d60486366258809553a3db49a4a
Library                
Your Makefile must, by default, produce the library hw4.a, like this:                 

    ar rcs hw4.a obj1.o obj2.o
Do not include main() in your library.                 

Testing                
You will have to write a main() function to test your code. Put it in a separate file, and do not make it part of hw4.a. You will also have to create a header file (the name is up to you) that declares the functions, and #include it in your test program that contains main().                 

We will test your program like this:                 

    tar -x <hw4.tar
    make
    g++ -Wall -o testprog our-test-program.cc hw4.a
    ./testprog
We will supply a main program to do the testing that we want. You should do something similar.                 
