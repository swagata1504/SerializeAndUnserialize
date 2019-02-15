#include "FSerial.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include <sstream>

using namespace std;

int main() {

    cout << "Test begins.\n\n";
    int i;
    short s;
    long l;
    bool b;
    char c;
    string S;
    cout<<"Testing OFSerial\nWriting to file\n";
    {
        OFSerial out("testFile");
        assert(out);
        assert(!out.fail());

        out << true;
        out << false;
        out << -8;
        out << 8;
        out << -2048;
        out << 2048;
    
        out << 34374;
        out << short(-84);
        out << 'g';
        out << "all type of test data"s;
        out << 7666555444;
        out << '`';
        out << " THANK	you	"s;
        out << '!';
        out << '@';
        out << '%';
        out << '^';
        out << '-';
        out << ':';
        out << '|';
        out << '	';
        out << '/';
        out << '5';
        out << 'f';
        out << '"';
        out << ',';
        out << '+';
        out << 35000;
        out << 2147483647;
        out << int(-2147483648);
        out << 32768;
        out << -32769;
        out << 3111222333;
        out << -4555666777;
        out << 9223372036854775807;
        out << -9223372036854775807-1;
        out << 2147483648;
        out << -2147483649;
        out << short(32767);
        out << short(6);
        out << short(-10);
        out << short(0);
        out << short(-32768);
        out << "This is HW2 test case."s;
        out << "Today is 12/02/2018 @csu & that's it."s;
        out << "#HW2	#CS253{}"s;
    }
    
    cout<<"File written\n";
    {
    ifstream ifs("testFile");
    stringstream strS;
    strS<<ifs.rdbuf();
    string current = strS.str();
    assert(current=="tfi\x08i\x10\x08i\x18\x00i\x20\x08\x00\x69\x20\x86\x46\x73\x1f\xac\x63\x67\x53\x10\x15\x61\x6c\x6c\x20\x74\x79\x70\x65\x20\x6f\x66\x20\x74\x65\x73\x74\x20\x64\x61\x74\x61\x6c\x41\xc8\xf6\x5a\x34\x63\x60\x53\x10\x0b\x20\x54\x48\x41\x4e\x4b\x09\x79\x6f\x75\x09\x63\x21\x63\x40\x63\x25\x63\x5e\x63\x2d\x63\x3a\x63\x7c\x63\x09\x63\x2f\x63\x35\x63\x66\x63\x22\x63\x2c\x63\x2b\x69\x20\x88\xb8\x69\x40\x7f\xff\xff\xff\x69\x4f\x80\x00\x00\x00\x69\x20\x80\x00\x69\x2f\x7f\xff\x6c\x40\xb9\x71\x7c\x3d\x6c\x4e\xf0\x76\x0a\xa7\x6c\x80\x7f\xff\xff\xff\xff\xff\xff\xff\x6c\x8f\x80\x00\x00\x00\x00\x00\x00\x00\x6c\x40\x80\x00\x00\x00\x6c\x4f\x7f\xff\xff\xff\x73\x20\x7f\xff\x73\x06\x73\x1f\xf6\x73\x00\x73\x2f\x80\x00\x53\x10\x16\x54\x68\x69\x73\x20\x69\x73\x20\x48\x57\x32\x20\x74\x65\x73\x74\x20\x63\x61\x73\x65\x2e\x53\x10\x25\x54\x6f\x64\x61\x79\x20\x69\x73\x20\x31\x32\x2f\x30\x32\x2f\x32\x30\x31\x38\x20\x40\x63\x73\x75\x20\x26\x20\x74\x68\x61\x74\x27\x73\x20\x69\x74\x2e\x53\x10\x0d\x23\x48\x57\x32\x09\x23\x43\x53\x32\x35\x33\x7b\x7d"s); //yikes amirite
    }

    cout<<"\nTesting IFSerial\n";
    
    IFSerial in("testFile");
    
    
    in >> b;
    assert(b == true);
    in >> b;
    assert(b == false);
    in >> i;
    assert(i == -8);
    in >> i;
    assert(i == 8);
    in >> i;
    assert(i == -2048);
    in >> i;
    assert(i == 2048);
    
    cout<<"testAll\n";
    in >> i;
    assert(i == 34374);
    in >> s;
    assert(s == -84);
    in >> c;
    assert(c == 'g');
    in >> S;
    assert(S == "all type of test data"s);
    in >> l;
    assert(l == 7666555444);
    in >> c;
    assert(c == '`');
    in >> S;
    assert(S == " THANK	you	"s);
    
    cout<<"testChar\n";
    in >> c;
    assert(c == '!');
    in >> c;
    assert(c == '@');
    in >> c;
    assert(c == '%');
    in >> c;
    assert(c == '^');
    in >> c;
    assert(c == '-');
    in >> c;
    assert(c == ':');
    in >> c;
    assert(c == '|');
    in >> c;
    assert(c == '	');
    in >> c;
    assert(c == '/');
    in >> c;
    assert(c == '5');
    in >> c;
    assert(c == 'f');
    in >> c;
    assert(c == '"');
    in >> c;
    assert(c == ',');
    in >> c;
    assert(c == '+');
    
    cout<<"testInt\n";
    in >> i;
    assert(i == 35000);
    in >> i;
    assert(i == 2147483647);
    in >> i;
    assert(i == -2147483648);
    in >> i;
    assert(i == 32768);
    in >> i;
    assert(i == -32769);
    
    cout<<"testLongs\n";
    in >> l;
    assert(l == 3111222333);
    in >> l;
    assert(l == -4555666777);
    in >> l;
    assert(l == 9223372036854775807);
    in >> l;
    assert(l == -9223372036854775807-1);
    in >> l;
    assert(l == 2147483648);
    in >> l;
    assert(l == -2147483649);
    
    cout<<"testShorts\n";
    in >> s;
    assert(s == 32767);
    in >> s;
    assert(s == 6);
    in >> s;
    assert(s == -10);
    in >> s;
    assert(s == 0);
    in >> s;
    assert(s == -32768);
    
    cout<<"testStrings\n";
    in >> S;
    assert(S == "This is HW2 test case."s);
    in >> S;
    assert(S == "Today is 12/02/2018 @csu & that's it."s);
    in >> S;
    assert(S == "#HW2	#CS253{}"s);
    
    
    cout<<"testFailBit\n";
    assert(!in.fail());
    assert(!in.eof());
    in >> i;
    assert(!in);		// same as in.fail()
    assert(in.fail());	// a conversion (in >> i) failed
    assert(in.eof());	// we hit end-of-file
    
    cout<<"testFile\n";
    {
    ifstream ifs("testFile");
    stringstream strS;
    strS<<ifs.rdbuf();
    string current = strS.str();
    assert(current=="tfi\x08i\x10\x08i\x18\x00i\x20\x08\x00\x69\x20\x86\x46\x73\x1f\xac\x63\x67\x53\x10\x15\x61\x6c\x6c\x20\x74\x79\x70\x65\x20\x6f\x66\x20\x74\x65\x73\x74\x20\x64\x61\x74\x61\x6c\x41\xc8\xf6\x5a\x34\x63\x60\x53\x10\x0b\x20\x54\x48\x41\x4e\x4b\x09\x79\x6f\x75\x09\x63\x21\x63\x40\x63\x25\x63\x5e\x63\x2d\x63\x3a\x63\x7c\x63\x09\x63\x2f\x63\x35\x63\x66\x63\x22\x63\x2c\x63\x2b\x69\x20\x88\xb8\x69\x40\x7f\xff\xff\xff\x69\x4f\x80\x00\x00\x00\x69\x20\x80\x00\x69\x2f\x7f\xff\x6c\x40\xb9\x71\x7c\x3d\x6c\x4e\xf0\x76\x0a\xa7\x6c\x80\x7f\xff\xff\xff\xff\xff\xff\xff\x6c\x8f\x80\x00\x00\x00\x00\x00\x00\x00\x6c\x40\x80\x00\x00\x00\x6c\x4f\x7f\xff\xff\xff\x73\x20\x7f\xff\x73\x06\x73\x1f\xf6\x73\x00\x73\x2f\x80\x00\x53\x10\x16\x54\x68\x69\x73\x20\x69\x73\x20\x48\x57\x32\x20\x74\x65\x73\x74\x20\x63\x61\x73\x65\x2e\x53\x10\x25\x54\x6f\x64\x61\x79\x20\x69\x73\x20\x31\x32\x2f\x30\x32\x2f\x32\x30\x31\x38\x20\x40\x63\x73\x75\x20\x26\x20\x74\x68\x61\x74\x27\x73\x20\x69\x74\x2e\x53\x10\x0d\x23\x48\x57\x32\x09\x23\x43\x53\x32\x35\x33\x7b\x7d"s); //oof
    }
    
    cout<<"\nBegin error testing.\n\n";
    
    cout<<"Checking: not a boolean\n";
    {
        ofstream ofs("tester");
        ofs<<"\x37"s;
    }
    {	
        IFSerial ifs("tester");
        ifs >> b;
        assert(ifs.fail());
        assert(!ifs);
    }


    cout<<"Checking: not a tagged short\n";
    {
        ofstream ofs("tester");
        ofs<<"\x69\x20\x9a\x6e"s;
    }
    {
        IFSerial ifs("tester");
        ifs >> s;
        assert(ifs.fail());
        assert(!ifs);
    }

    cout<<"Checking: too big for short\n";
    {
        ofstream ofs("tester");
        ofs<<"\x73\x42\x4a\x13\xfe\xf1"s;
    }
    {
        IFSerial ifs("tester");
        ifs >> s;
        assert(ifs.fail());
        assert(!ifs);
    }

    cout<<"Checking: not a tagged int\n";

    {
        ofstream ofs("tester");
        ofs<<"\x6c\x42\x4a\x13\xfe\xf1"s;
    }
    {
        IFSerial ifs("tester");
        ifs >> i;
        assert(ifs.fail());
        assert(!ifs);
    }

    cout<<"Checking: too big for int\n";
    {
        ofstream ofs("tester");
        ofs<<"\x69\x42\x4a\x13\xfe\xf1"s;
    }
    {
        IFSerial ifs("tester");
        ifs >> i;
        assert(ifs.fail());
        assert(!ifs);
    }

    cout<<"Checking: not a tagged long\n";
    {
        ofstream ofs("tester");
        ofs<<"\x73\x20\x9a\x6e"s;
    }
    {
        IFSerial ifs("tester");
        ifs >> l;
        assert(ifs.fail());
        assert(!ifs);
    }
/*
    cout<<"Checking: too big for long\n";
    {
        ofstream ofs("tester");
        ofs<<"\x6c\x90\x00\x7f\xff\xff\xff\xff\xff\xff\xff"s;
    }
    {
        IFSerial ifs("tester");
        ifs >> l;
        assert(ifs.fail());
        assert(!ifs);
    }*/

    cout<<"Checking: not a tagged char\n";
    {
        ofstream ofs("tester");
        ofs<<"\x69\x2b"s;
    }
    {
        IFSerial ifs("tester");
        ifs >> c;
        assert(ifs.fail());
        assert(!ifs);
    }

    cout<<"Checking: not a tagged string\n";
    {
        ofstream ofs("tester");
        ofs<<"\x73\x10\x16\x54\x68\x69\x73\x20\x69\x73\x20\x48\x57\x32\x20\x74\x65\x73\x74\x20\x63\x61\x73\x65\x2e"s;

    }
    {
        IFSerial ifs("tester");
        ifs >> S;
        assert(ifs.fail());
        assert(!ifs);
    }

    cout<<"Checking: length too large (string)\n";
    {
        ofstream ofs("tester");
        ofs<<"\x53\x10\x25\x54\x68\x69\x73\x20\x69\x73\x20\x48\x57\x32\x20\x74\x65\x73\x74\x20\x63\x61\x73\x65\x2e"s;
    }
    {
        IFSerial ifs("tester");
        ifs >> S;
        assert(ifs.fail());
        assert(!ifs);
    }

    cout<<"Checking: length too large (number)\n";
    {
        ofstream ofs("tester");
        ofs<<"\x69\x62\x4a\x13\xfe\xf1"s;
    }
    {
        IFSerial ifs("tester");
        ifs >> i;
        assert(ifs.fail());
        assert(!ifs);
    }



    cout<<"Checking: bad file\n";
    // Try writing to a file that can’t be created.
    OFSerial o("/this/does/not/exist");
    assert(!o);
    assert(o.fail());
    
    o << 2953108;	    // Must not complain, throw, or exit.
    assert(!o);
    assert(o.fail());

    cout << "\nTest ends.\n";
    
    return 0;
    
}
