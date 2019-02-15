#include <cmath>
#include <string>
#include <iostream>
 
using namespace std;

#include "functions.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>

using namespace std;

int main() {
    cout << "Test begins\n";
    
    

    ostringstream oss;

    //HW2 Tests
    
    //testall
    cout<<"testall\n";
    serialize(34374, oss);
    assert(oss.str()=="\x69\x20\x86\x46"s);
    oss.str("");
    serialize(short(-84), oss);
    assert(oss.str()=="\x73\x1f\xac"s);
    oss.str("");
    serialize('g', oss);
    assert(oss.str()=="\x63\x67"s);
    oss.str("");
    serialize("all type of test data"s, oss);
    assert(oss.str()=="\x53\x10\x15\x61\x6c\x6c\x20\x74\x79\x70\x65\x20\x6f\x66\x20\x74\x65\x73\x74\x20\x64\x61\x74\x61"s);
    oss.str("");
    serialize(7666555444, oss);
    assert(oss.str()=="\x6c\x41\xc8\xf6\x5a\x34"s);
    oss.str("");
    serialize('`', oss);
    assert(oss.str()=="\x63\x60"s);
    oss.str("");
    serialize(" THANK	you	"s, oss);
    assert(oss.str()=="\x53\x10\x0b\x20\x54\x48\x41\x4e\x4b\x09\x79\x6f\x75\x09"s);
    oss.str("");
    
    //testchar
    cout<<"testchar\n";
    serialize('!', oss);
    assert(oss.str()=="\x63\x21"s);
    oss.str("");
    serialize('@', oss);
    assert(oss.str()=="\x63\x40"s);
    oss.str("");
    serialize('%', oss);
    assert(oss.str()=="\x63\x25"s);
    oss.str("");
    serialize('^', oss);
    assert(oss.str()=="\x63\x5e"s);
    oss.str("");
    serialize('-', oss);
    assert(oss.str()=="\x63\x2d"s);
    oss.str("");
    serialize(':', oss);
    assert(oss.str()=="\x63\x3a"s);
    oss.str("");
    serialize('|', oss);
    assert(oss.str()=="\x63\x7c"s);
    oss.str("");
    serialize('	', oss);
    assert(oss.str()=="\x63\x09"s);
    oss.str("");
    serialize('/', oss);
    assert(oss.str()=="\x63\x2f"s);
    oss.str("");
    serialize('5', oss);
    assert(oss.str()=="\x63\x35"s);
    oss.str("");
    serialize('f', oss);
    assert(oss.str()=="\x63\x66"s);
    oss.str("");
    serialize('"', oss);
    assert(oss.str()=="\x63\x22"s);
    oss.str("");
    serialize(',', oss);
    assert(oss.str()=="\x63\x2c"s);
    oss.str("");
    serialize('+', oss);
    assert(oss.str()=="\x63\x2b"s);
    oss.str("");
    
        //testint
    cout<<"testint\n";
    serialize(35000, oss);
    assert(oss.str()=="\x69\x20\x88\xb8"s);
    oss.str("");
    serialize(2147483647, oss);
    assert(oss.str()=="\x69\x40\x7f\xff\xff\xff"s);
    oss.str("");
    serialize(int(-2147483648), oss);
    assert(oss.str()=="\x69\x4f\x80\x00\x00\x00"s);
    oss.str("");
    serialize(32768, oss);
    assert(oss.str()=="\x69\x20\x80\x00"s);
    oss.str("");
    serialize(-32769, oss);
    assert(oss.str()=="\x69\x2f\x7f\xff"s);
    oss.str("");
    
    //testlong
    cout<<"testlong\n";
    serialize(3111222333, oss);
    assert(oss.str()=="\x6c\x40\xb9\x71\x7c\x3d"s);
    oss.str("");
    serialize(-4555666777, oss);
    assert(oss.str()=="\x6c\x4e\xf0\x76\x0a\xa7"s);
    oss.str("");
    serialize(9223372036854775807, oss);
    assert(oss.str()=="\x6c\x80\x7f\xff\xff\xff\xff\xff\xff\xff"s);
    oss.str("");
    serialize(-9223372036854775807-1, oss);
    assert(oss.str()=="\x6c\x8f\x80\x00\x00\x00\x00\x00\x00\x00"s);
    oss.str("");
    serialize(2147483648, oss);
    assert(oss.str()=="\x6c\x40\x80\x00\x00\x00"s);
    oss.str("");
    serialize(-2147483649, oss);
    assert(oss.str()=="\x6c\x4f\x7f\xff\xff\xff"s);
    oss.str("");
    
    //testshort
    cout<<"testshort\n";
    serialize(short(32767), oss);
    assert(oss.str()=="\x73\x20\x7f\xff"s);
    oss.str("");
    serialize(short(6), oss);
    assert(oss.str()=="\x73\x06"s);
    oss.str("");
    serialize(short(-10), oss);
    assert(oss.str()=="\x73\x1f\xf6"s);
    oss.str("");
    serialize(short(0), oss);
    assert(oss.str()=="\x73\x00"s);
    oss.str("");
    serialize(short(-32768), oss);
    assert(oss.str()=="\x73\x2f\x80\x00"s);
    oss.str("");
    
    //teststring
    cout<<"teststring\n";
    serialize("This is HW2 test case."s, oss);
    assert(oss.str()=="\x53\x10\x16\x54\x68\x69\x73\x20\x69\x73\x20\x48\x57\x32\x20\x74\x65\x73\x74\x20\x63\x61\x73\x65\x2e"s);
    oss.str("");
    serialize("Today is 12/02/2018 @csu & that's it."s, oss);
    assert(oss.str()=="\x53\x10\x25\x54\x6f\x64\x61\x79\x20\x69\x73\x20\x31\x32\x2f\x30\x32\x2f\x32\x30\x31\x38\x20\x40\x63\x73\x75\x20\x26\x20\x74\x68\x61\x74\x27\x73\x20\x69\x74\x2e"s);
    oss.str("");
    serialize("#HW2	#CS253{}"s, oss);
    assert(oss.str()=="\x53\x10\x0d\x23\x48\x57\x32\x09\x23\x43\x53\x32\x35\x33\x7b\x7d"s);
     try {
            
        string S;
        short s;
        
        int i;
        long l;
        char c;
		bool b;
        istringstream iss("");
        
        
        
        //unserialize HW2 Tests
        
        //testall
         cout<<"unserialize testall\n";
         iss.str("\x69\x20\x86\x46"s);
         unserialize(iss, i); assert(i == 34374);
         iss.str("\x73\x1f\xac"s);
         unserialize(iss, s); assert(s == -84);
         iss.str("\x63\x67"s);
         unserialize(iss, c); assert(c == 'g');
         iss.str("\x53\x10\x15\x61\x6c\x6c\x20\x74\x79\x70\x65\x20\x6f\x66\x20\x74\x65\x73\x74\x20\x64\x61\x74\x61"s);
         unserialize(iss, S); assert(S == "all type of test data"s);
         iss.str("\x6c\x41\xc8\xf6\x5a\x34"s);
         unserialize(iss, l); assert(l == 7666555444);
         iss.str("\x63\x60"s);
         unserialize(iss, c); assert(c == '`');
         iss.str("\x53\x10\x0b\x20\x54\x48\x41\x4e\x4b\x09\x79\x6f\x75\x09"s);
         unserialize(iss, S); assert(S == " THANK	you	"s);
         
        //testchar
        cout<<"unserialize testchar\n";
        iss.str("\x63\x21"s);
        unserialize(iss, c); assert(c == '!');
        iss.str("\x63\x40"s);
        unserialize(iss, c); assert(c == '@');
        iss.str("\x63\x25"s);
        unserialize(iss, c); assert(c == '%');
        iss.str("\x63\x5e"s);
        unserialize(iss, c); assert(c == '^');
        iss.str("\x63\x2d"s);
        unserialize(iss, c); assert(c == '-');
        iss.str("\x63\x3a"s);
        unserialize(iss, c); assert(c == ':');
        iss.str("\x63\x7c"s);
        unserialize(iss, c); assert(c == '|');
        iss.str("\x63\x09"s);
        unserialize(iss, c); assert(c == '	');
        iss.str("\x63\x2f"s);
        unserialize(iss, c); assert(c == '/');
        iss.str("\x63\x35"s);
        unserialize(iss, c); assert(c == '5');
        iss.str("\x63\x66"s);
        unserialize(iss, c); assert(c == 'f');
        iss.str("\x63\x22"s);
        unserialize(iss, c); assert(c == '"');
        iss.str("\x63\x2c"s);
        unserialize(iss, c); assert(c == ',');
        iss.str("\x63\x2b"s);
        unserialize(iss, c); assert(c == '+');
        
        //testint
        cout<<"unserialize testint\n";
        iss.str("\x69\x20\x88\xb8"s);
        unserialize(iss, i); assert(i == 35000);
        iss.str("\x69\x40\x7f\xff\xff\xff"s);
        unserialize(iss, i); assert(i == 2147483647);
        iss.str("\x69\x4f\x80\x00\x00\x00"s);
        unserialize(iss, i); assert(i == -2147483648);
        iss.str("\x69\x20\x80\x00"s);
        unserialize(iss, i); assert(i == 32768);
        iss.str("\x69\x2f\x7f\xff"s);
        unserialize(iss, i); assert(i == -32769);
       
        
        //testlong
        cout<<"unserialize testlong\n";
        iss.str("\x6c\x40\xb9\x71\x7c\x3d"s);
        unserialize(iss, l); assert(l == 3111222333);
        iss.str("\x6c\x4e\xf0\x76\x0a\xa7"s);
        unserialize(iss, l); assert(l == -4555666777);
        iss.str("\x6c\x80\x7f\xff\xff\xff\xff\xff\xff\xff"s);
         unserialize(iss, l); assert(l == 9223372036854775807);
         iss.str("\x6c\x8f\x80\x00\x00\x00\x00\x00\x00\x00"s);
         unserialize(iss, l); assert(l == -9223372036854775807-1);
         iss.str("\x6c\x40\x80\x00\x00\x00"s);
        unserialize(iss, l); assert(l == 2147483648);
        iss.str("\x6c\x4f\x7f\xff\xff\xff"s);
        unserialize(iss, l); assert(l == -2147483649);
        
        //testshort
        cout<<"unserialize testshort\n";
        iss.str("\x73\x20\x7f\xff"s);
        unserialize(iss, s); assert(s == 32767);
        iss.str("\x73\x06"s);
        unserialize(iss, s); assert(s == 6);
        iss.str("\x73\x1f\xf6"s);
        unserialize(iss, s); assert(s == -10);
        iss.str("\x73\x00"s);
        unserialize(iss, s); assert(s == 0);
        iss.str("\x73\x2f\x80\x00"s);
        unserialize(iss, s); assert(s == -32768);
        
        //teststring
        cout<<"unserialize teststring\n";
        iss.str("\x53\x10\x16\x54\x68\x69\x73\x20\x69\x73\x20\x48\x57\x32\x20\x74\x65\x73\x74\x20\x63\x61\x73\x65\x2e"s);
        unserialize(iss, S); assert(S == "This is HW2 test case."s);
        iss.str("\x53\x10\x25\x54\x6f\x64\x61\x79\x20\x69\x73\x20\x31\x32\x2f\x30\x32\x2f\x32\x30\x31\x38\x20\x40\x63\x73\x75\x20\x26\x20\x74\x68\x61\x74\x27\x73\x20\x69\x74\x2e"s);
        unserialize(iss, S); assert(S == "Today is 12/02/2018 @csu & that's it."s);
        iss.str("\x53\x10\x0d\x23\x48\x57\x32\x09\x23\x43\x53\x32\x35\x33\x7b\x7d"s);
        unserialize(iss, S); assert(S == "#HW2	#CS253{}"s);
		
		
		//hw3 tests
		cout<<"HW3 tests begin\n";
		
		//testbool
		cout<<"unserialize testbool\n";
		iss.str("ft");
		unserialize(iss, b); assert(!b);
		unserialize(iss, b); assert(b);
		
		//testchar
		cout<<"unserialize char_bytes\n";
		iss.str("\x63\x37\x63\x72\x63\x40"s);
		unserialize(iss, c); assert(c=='7');
		unserialize(iss, c); assert(c=='r');
		unserialize(iss, c); assert(c=='@');
		
		//testint
		cout<<"unserialize int_bytes\n";
		iss.str("\x69\x20\x9a\x6e\x69\x40\x16\x69\x13\x01\x69\x3f\xf7\xd6\x93"s);
		unserialize(iss, i); assert(i==39534);
		unserialize(iss, i); assert(i==375984897);
		unserialize(iss, i); assert(i==-534893);
		
		//testlong
		cout<<"unserialize long_bytes\n";
		iss.str("\x6c\x42\x4a\x13\xfe\xf1\x6c\x50\x43\xb7\xfb\x44\x00\x6c\x58\x7f\x5e\xf7\x64\xe3"s);
		unserialize(iss, l); assert(l==9832759025);
		unserialize(iss, l); assert(l==290849506304);
		unserialize(iss, l); assert(l==-8249038904093);

		//testshort
		cout<<"unserialize short bytes\n";
		iss.str("\x73\x06\x73\x10\xd1\x73\x0b\x73\x00"s);
		unserialize(iss, s); assert(s==6);
		unserialize(iss, s); assert(s==209);
		unserialize(iss, s); assert(s==-5);
        unserialize(iss, s); assert(s==0);
		//testmixed
		cout<<"unserialize mixed_bytes\n";
		iss.str("\x73\x06\x73\x10\xd1\x73\x0b\x53\x10\x5f\x59\x6f\x75\x20\x6d\x61\x79\x20\x61\x73\x73\x75\x6d\x65\x20\x74\x68\x61\x74\x20\x61\x20\x73\x74\x72\x69\x6e\x67\x20\x63\x6f\x6e\x73\x74\x61\x6e\x74\x20\x77\x69\x6c\x6c\x20\x6e\x6f\x74\x20\x63\x6f\x6e\x74\x61\x69\x6e\x20\x61\x20\x64\x6f\x75\x62\x6c\x65\x20\x71\x75\x6f\x74\x65\x2c\x20\x62\x61\x63\x6b\x73\x6c\x61\x73\x68\x2c\x20\x6f\x72\x20\x61\x20\x6e\x65\x77\x6c\x69\x6e\x65\x2e\x53\x10\x2c\x44\x6f\x65\x73\x20\x79\x6f\x75\x72\x20\x70\x72\x6f\x67\x72\x61\x6d\x20\x68\x61\x6e\x64\x6c\x65\x20\x65\x6d\x70\x74\x79\x20\x73\x74\x72\x69\x6e\x67\x73\x20\x77\x65\x6c\x6c\x3f\x53\x00"s);
		unserialize(iss, s); assert(s==6);
		unserialize(iss, s); assert(s==209);
		unserialize(iss, s); assert(s==-5);
		unserialize(iss, S); assert(S=="You may assume that a string constant will not contain a double quote, backslash, or a newline."s);
		unserialize(iss, S); assert(S=="Does your program handle empty strings well?"s);
		unserialize(iss, S); assert(S==""s);
        
        iss.str("\x53\x10\x2c\x44\x6f\x65\x73\x20");
        unserialize(iss, S);



    }
    catch (string msg) {
        cerr << "Unserialize error: " << msg << '\n';
    }
    
     
    cout<<"test ends\n";
}
