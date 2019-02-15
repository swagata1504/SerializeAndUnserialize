 #include "Serial.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main() {
    
	cout << "Test begins\n\n";
	
	string S;
	short s;
	int i;
	long l;
	char c;
	bool b;
    
//C-STRINGS: should fail to compile if any of the following lines are uncommented
//     ser += "Hello";
//     ser = ser + " World";
//     ser = "C++" + ser;
//     ser.put("Hello");
//     

	cout<<"Testing constructors and Serial addition/comparison\n";
	//testContructors
	Serial ser;
	assert(ser.str() == ""s && ser.size()==0 && ser.empty());
	
	ser.str("FUCK ");
	
	Serial copy(ser);
	assert(copy==ser);
	assert(ser==copy);
	assert(ser.str()==copy.str());
    copy.str("JACK APPLIN");
    assert((ser+copy).str()=="FUCK JACK APPLIN"s);
    assert((copy+ser).str()=="JACK APPLINFUCK "s);
    ser+=copy;
    assert(ser.str()=="FUCK JACK APPLIN"s);
    
	Serial assign = ser;
	assert(assign==ser);
	assert(ser.str()==assign.str());
	ser.str("");
	assert(ser!=copy);
	assert(ser!=assign);

	cout<<"Testing const-correctness\n";
	//testConstCorrectness
	const Serial con;
	assert(con.size()==0 && con.str()=="" && con.empty());
	const string cS = "Hello World"s;
	ser+=cS;
	assert(ser.str()=="S\x10\x0b" "Hello World"s && ser.size()==14 && !ser.empty()); // cannot convert  bool (Serial::) error
	ser.str("");
	const int ci = 4;
	ser+=ci;
	assert(ser.str()=="i\x04"s && ser.size()==2 && !ser.empty());
	ser.str("");
	const long cl = 4;
	ser+=cl;
	assert(ser.str()=="l\x04"s && ser.size()==2 && !ser.empty());
	ser.str("");
	const short cs = 4;
	ser+=cs;
	assert(ser.str()=="s\x04"s && ser.size()==2 && !ser.empty());
	ser.str("");
	const char cc = 'f';
	ser+=cc;
	assert(ser.str()=="cf"s && ser.size()==2 && !ser.empty());
	ser.str("");
	const bool cb = true;
	ser+=cb;
	assert(ser.str()=="t"s && ser.size()==1 && !ser.empty());
	ser.str("");


    
    //HW2 TESTS +=
	cout<<"\nSerializing with +=\n\n";
	
    cout<<"testBool +=\n";
    //testBool
    ser+=true;
    assert(ser.str()=="\x74"s && ser.size()==1 && !ser.empty());
    ser+=false;
    assert(ser.str()=="\x74\x66"s && ser.size()==2 && !ser.empty());
    
	cout<<"testAll +=\n";
	//testAll
    ser.str("");
    ser+=34374;
    assert(ser.str()=="\x69\x20\x86\x46"s && ser.size()==4 && !ser.empty());
    ser.str("");
    ser+=short(-84);
    assert(ser.str()=="\x73\x1f\xac"s && ser.size()==3 && !ser.empty());
    ser.str("");
    ser+='g';
    assert(ser.str()=="\x63\x67"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+="all type of test data"s;
    assert(ser.str()=="\x53\x10\x15\x61\x6c\x6c\x20\x74\x79\x70\x65\x20\x6f\x66\x20\x74\x65\x73\x74\x20\x64\x61\x74\x61"s && ser.size()==24 && !ser.empty());
    ser.str("");
    ser+=7666555444;
    assert(ser.str()=="\x6c\x41\xc8\xf6\x5a\x34"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser+='`';
    assert(ser.str()=="\x63\x60"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+=" THANK	you	"s;
    assert(ser.str()=="\x53\x10\x0b\x20\x54\x48\x41\x4e\x4b\x09\x79\x6f\x75\x09"s && ser.size()==14 && !ser.empty());
    ser.str("");
	
	cout<<"testChar +=\n";
	//testChars
    ser+='!';
    assert(ser.str()=="\x63\x21"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+='@';
    assert(ser.str()=="\x63\x40"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+='%';
    assert(ser.str()=="\x63\x25"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+='^';
    assert(ser.str()=="\x63\x5e"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+='-';
    assert(ser.str()=="\x63\x2d"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+=':';
    assert(ser.str()=="\x63\x3a"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+='|';
    assert(ser.str()=="\x63\x7c"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+='	';
    assert(ser.str()=="\x63\x09"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+='/';
    assert(ser.str()=="\x63\x2f"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+='5';
    assert(ser.str()=="\x63\x35"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+='f';
    assert(ser.str()=="\x63\x66"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+='"';
    assert(ser.str()=="\x63\x22"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+=',';
    assert(ser.str()=="\x63\x2c"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+='+';
    assert(ser.str()=="\x63\x2b"s && ser.size()==2 && !ser.empty());
    ser.str("");
	
	cout<<"testInts +=\n";
	//testInts
    ser+=35000;
    assert(ser.str()=="\x69\x20\x88\xb8"s && ser.size()==4 && !ser.empty());
    ser.str("");
    ser+=2147483647;
    assert(ser.str()=="\x69\x40\x7f\xff\xff\xff"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser+=int(-2147483648);
    assert(ser.str()=="\x69\x4f\x80\x00\x00\x00"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser+=32768;
    assert(ser.str()=="\x69\x20\x80\x00"s && ser.size()==4 && !ser.empty());
    ser.str("");
    ser+=-32769;
    assert(ser.str()=="\x69\x2f\x7f\xff"s && ser.size()==4 && !ser.empty());
    ser.str("");
	
	cout<<"testLongs +=\n";
	//testLongs
    ser+=3111222333;
    assert(ser.str()=="\x6c\x40\xb9\x71\x7c\x3d"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser+=-4555666777;
    assert(ser.str()=="\x6c\x4e\xf0\x76\x0a\xa7"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser+=9223372036854775807;
    assert(ser.str()=="\x6c\x80\x7f\xff\xff\xff\xff\xff\xff\xff"s && ser.size()==10 && !ser.empty());
    ser.str("");
    ser+=-9223372036854775807-1;
    assert(ser.str()=="\x6c\x8f\x80\x00\x00\x00\x00\x00\x00\x00"s && ser.size()==10 && !ser.empty());
    ser.str("");
    ser+=2147483648;
    assert(ser.str()=="\x6c\x40\x80\x00\x00\x00"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser+=-2147483649;
    assert(ser.str()=="\x6c\x4f\x7f\xff\xff\xff"s && ser.size()==6 && !ser.empty());
    ser.str("");
	
	cout<<"testShorts +=\n";
	//testShorts
    ser+=short(32767);
    assert(ser.str()=="\x73\x20\x7f\xff"s && ser.size()==4 && !ser.empty());
    ser.str("");
    ser+=short(6);
    assert(ser.str()=="\x73\x06"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+=short(-10);
    assert(ser.str()=="\x73\x1f\xf6"s && ser.size()==3 && !ser.empty());
    ser.str("");
    ser+=short(0);
    assert(ser.str()=="\x73\x00"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser+=short(-32768);
    assert(ser.str()=="\x73\x2f\x80\x00"s && ser.size()==4 && !ser.empty());
    ser.str("");
	
	cout<<"testStrings +=\n";
	//testStrings
    ser+="This is HW2 test case."s;
    assert(ser.str()=="\x53\x10\x16\x54\x68\x69\x73\x20\x69\x73\x20\x48\x57\x32\x20\x74\x65\x73\x74\x20\x63\x61\x73\x65\x2e"s && ser.size()==25 && !ser.empty());
    ser.str("");
    ser+="Today is 12/02/2018 @csu & that's it."s;
    assert(ser.str()=="\x53\x10\x25\x54\x6f\x64\x61\x79\x20\x69\x73\x20\x31\x32\x2f\x30\x32\x2f\x32\x30\x31\x38\x20\x40\x63\x73\x75\x20\x26\x20\x74\x68\x61\x74\x27\x73\x20\x69\x74\x2e"s && ser.size()==40 && !ser.empty());
    ser.str("");
    ser+="#HW2	#CS253{}"s;
    assert(ser.str()=="\x53\x10\x0d\x23\x48\x57\x32\x09\x23\x43\x53\x32\x35\x33\x7b\x7d"s && ser.size()==16 && !ser.empty());
    ser.str("");
    
    
    //HW4 TESTS +
    cout<<"\nSerializing with + (Member)\n\n";
	
    cout<<"testBool + (Member)\n";
    //testBool
    ser= ser + true;
    assert(ser.str()=="\x74"s && ser.size()==1 && !ser.empty());
    ser= ser + false;
    assert(ser.str()=="\x74\x66"s && ser.size()==2 && !ser.empty());
    ser.str("");
    
	cout<<"testAll + (Member)\n";
	//testAll
    ser= ser + 34374;
    assert(ser.str()=="\x69\x20\x86\x46"s && ser.size()==4 && !ser.empty());
    ser.str("");
    ser= ser + short(-84);
    assert(ser.str()=="\x73\x1f\xac"s && ser.size()==3 && !ser.empty());
    ser.str("");
    ser= ser + 'g';
    assert(ser.str()=="\x63\x67"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + "all type of test data"s;
    assert(ser.str()=="\x53\x10\x15\x61\x6c\x6c\x20\x74\x79\x70\x65\x20\x6f\x66\x20\x74\x65\x73\x74\x20\x64\x61\x74\x61"s && ser.size()==24 && !ser.empty());
    ser.str("");
    ser= ser + 7666555444;
    assert(ser.str()=="\x6c\x41\xc8\xf6\x5a\x34"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser= ser + '`';
    assert(ser.str()=="\x63\x60"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + " THANK	you	"s;
    assert(ser.str()=="\x53\x10\x0b\x20\x54\x48\x41\x4e\x4b\x09\x79\x6f\x75\x09"s && ser.size()==14 && !ser.empty());
    ser.str("");
	
	cout<<"testChar + (Member)\n";
	//testChars
    ser= ser + '!';
    assert(ser.str()=="\x63\x21"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + '@';
    assert(ser.str()=="\x63\x40"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + '%';
    assert(ser.str()=="\x63\x25"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + '^';
    assert(ser.str()=="\x63\x5e"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + '-';
    assert(ser.str()=="\x63\x2d"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + ':';
    assert(ser.str()=="\x63\x3a"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + '|';
    assert(ser.str()=="\x63\x7c"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + '	';
    assert(ser.str()=="\x63\x09"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + '/';
    assert(ser.str()=="\x63\x2f"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + '5';
    assert(ser.str()=="\x63\x35"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + 'f';
    assert(ser.str()=="\x63\x66"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + '"';
    assert(ser.str()=="\x63\x22"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + ',';
    assert(ser.str()=="\x63\x2c"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + '+';
    assert(ser.str()=="\x63\x2b"s && ser.size()==2 && !ser.empty());
    ser.str("");
	
	cout<<"testInts + (Member)\n";
	//testInts
    ser= ser + 35000;
    assert(ser.str()=="\x69\x20\x88\xb8"s && ser.size()==4 && !ser.empty());
    ser.str("");
    ser= ser + 2147483647;
    assert(ser.str()=="\x69\x40\x7f\xff\xff\xff"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser= ser + int(-2147483648);
    assert(ser.str()=="\x69\x4f\x80\x00\x00\x00"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser= ser + 32768;
    assert(ser.str()=="\x69\x20\x80\x00"s && ser.size()==4 && !ser.empty());
    ser.str("");
    ser= ser + -32769;
    assert(ser.str()=="\x69\x2f\x7f\xff"s && ser.size()==4 && !ser.empty());
    ser.str("");
	
	cout<<"testLongs + (Member)\n";
	//testLongs
    ser= ser + 3111222333;
    assert(ser.str()=="\x6c\x40\xb9\x71\x7c\x3d"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser= ser + -4555666777;
    assert(ser.str()=="\x6c\x4e\xf0\x76\x0a\xa7"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser= ser + 9223372036854775807;
    assert(ser.str()=="\x6c\x80\x7f\xff\xff\xff\xff\xff\xff\xff"s && ser.size()==10 && !ser.empty());
    ser.str("");
    ser= ser + (-9223372036854775807-1);
    assert(ser.str()=="\x6c\x8f\x80\x00\x00\x00\x00\x00\x00\x00"s && ser.size()==10 && !ser.empty());
    ser.str("");
    ser= ser + 2147483648;
    assert(ser.str()=="\x6c\x40\x80\x00\x00\x00"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser= ser + -2147483649;
    assert(ser.str()=="\x6c\x4f\x7f\xff\xff\xff"s && ser.size()==6 && !ser.empty());
    ser.str("");
	
	cout<<"testShorts + (Member)\n";
	//testShorts
    ser= ser + short(32767);
    assert(ser.str()=="\x73\x20\x7f\xff"s && ser.size()==4 && !ser.empty());
    ser.str("");
    ser= ser + short(6);
    assert(ser.str()=="\x73\x06"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + short(-10);
    assert(ser.str()=="\x73\x1f\xf6"s && ser.size()==3 && !ser.empty());
    ser.str("");
    ser= ser + short(0);
    assert(ser.str()=="\x73\x00"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ser + short(-32768);
    assert(ser.str()=="\x73\x2f\x80\x00"s && ser.size()==4 && !ser.empty());
    ser.str("");
	
	cout<<"testStrings + (Member)\n";
	//testStrings
    ser= ser + "This is HW2 test case."s;
    assert(ser.str()=="\x53\x10\x16\x54\x68\x69\x73\x20\x69\x73\x20\x48\x57\x32\x20\x74\x65\x73\x74\x20\x63\x61\x73\x65\x2e"s && ser.size()==25 && !ser.empty());
    ser.str("");
    ser= ser + "Today is 12/02/2018 @csu & that's it."s;
    assert(ser.str()=="\x53\x10\x25\x54\x6f\x64\x61\x79\x20\x69\x73\x20\x31\x32\x2f\x30\x32\x2f\x32\x30\x31\x38\x20\x40\x63\x73\x75\x20\x26\x20\x74\x68\x61\x74\x27\x73\x20\x69\x74\x2e"s && ser.size()==40 && !ser.empty());
    ser.str("");
    ser= ser + "#HW2	#CS253{}"s;
    assert(ser.str()=="\x53\x10\x0d\x23\x48\x57\x32\x09\x23\x43\x53\x32\x35\x33\x7b\x7d"s && ser.size()==16 && !ser.empty());
    ser.str("");
    
    //HW4 TESTS REVERSE +
    cout<<"\nSerializing with + (Non-member)\n\n";
	
    cout<<"testBool + (Non-member)\n";
    //testBool
    ser= true + ser;
    assert(ser.str()=="\x74"s && ser.size()==1 && !ser.empty());
    ser= false + ser;
    assert(ser.str()=="\x66\x74"s && ser.size()==2 && !ser.empty());
    ser.str("");
    
	cout<<"testAll + (Non-member)\n";
	//testAll
    ser= 34374 + ser;
    assert(ser.str()=="\x69\x20\x86\x46"s && ser.size()==4 && !ser.empty());
    ser.str("");
    ser= short(-84) + ser;
    assert(ser.str()=="\x73\x1f\xac"s && ser.size()==3 && !ser.empty());
    ser.str("");
    ser= 'g' + ser;
    assert(ser.str()=="\x63\x67"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= "all type of test data"s + ser;
    assert(ser.str()=="\x53\x10\x15\x61\x6c\x6c\x20\x74\x79\x70\x65\x20\x6f\x66\x20\x74\x65\x73\x74\x20\x64\x61\x74\x61"s && ser.size()==24 && !ser.empty());
    ser.str("");
    ser= 7666555444 + ser;
    assert(ser.str()=="\x6c\x41\xc8\xf6\x5a\x34"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser= '`' + ser;
    assert(ser.str()=="\x63\x60"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= " THANK	you	"s + ser;
    assert(ser.str()=="\x53\x10\x0b\x20\x54\x48\x41\x4e\x4b\x09\x79\x6f\x75\x09"s && ser.size()==14 && !ser.empty());
    ser.str("");
	
	cout<<"testChar + (Non-member)\n";
	//testChars
    ser= '!' + ser;
    assert(ser.str()=="\x63\x21"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= '@' + ser;
    assert(ser.str()=="\x63\x40"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= '%' + ser;
    assert(ser.str()=="\x63\x25"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= '^' + ser;
    assert(ser.str()=="\x63\x5e"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= '-' + ser;
    assert(ser.str()=="\x63\x2d"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ':' + ser;
    assert(ser.str()=="\x63\x3a"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= '|' + ser;
    assert(ser.str()=="\x63\x7c"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= '	' + ser;
    assert(ser.str()=="\x63\x09"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= '/' + ser;
    assert(ser.str()=="\x63\x2f"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= '5' + ser;
    assert(ser.str()=="\x63\x35"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= 'f' + ser;
    assert(ser.str()=="\x63\x66"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= '"' + ser;
    assert(ser.str()=="\x63\x22"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= ',' + ser;
    assert(ser.str()=="\x63\x2c"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= '+' + ser;
    assert(ser.str()=="\x63\x2b"s && ser.size()==2 && !ser.empty());
    ser.str("");
	
	cout<<"testInts + (Non-member)\n";
	 //testInts
    ser= 35000 + ser;
    assert(ser.str()=="\x69\x20\x88\xb8"s && ser.size()==4 && !ser.empty());
    ser.str("");
    ser= 2147483647 + ser;
    assert(ser.str()=="\x69\x40\x7f\xff\xff\xff"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser= int(-2147483648) + ser;
    assert(ser.str()=="\x69\x4f\x80\x00\x00\x00"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser= 32768 + ser;
    assert(ser.str()=="\x69\x20\x80\x00"s && ser.size()==4 && !ser.empty());
    ser.str("");
    ser= -32769 + ser;
    assert(ser.str()=="\x69\x2f\x7f\xff"s && ser.size()==4 && !ser.empty());
    ser.str("");
    ser= 3111222333 + ser;
	
	cout<<"testLongs + (Non-member)\n";
	//testLongs
    assert(ser.str()=="\x6c\x40\xb9\x71\x7c\x3d"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser= -4555666777 + ser;
    assert(ser.str()=="\x6c\x4e\xf0\x76\x0a\xa7"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser= 9223372036854775807 + ser;
    assert(ser.str()=="\x6c\x80\x7f\xff\xff\xff\xff\xff\xff\xff"s && ser.size()==10 && !ser.empty());
    ser.str("");
    ser= (-9223372036854775807-1) + ser;
    assert(ser.str()=="\x6c\x8f\x80\x00\x00\x00\x00\x00\x00\x00"s && ser.size()==10 && !ser.empty());
    ser.str("");
    ser= 2147483648 + ser;
    assert(ser.str()=="\x6c\x40\x80\x00\x00\x00"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser= -2147483649 + ser;
    assert(ser.str()=="\x6c\x4f\x7f\xff\xff\xff"s && ser.size()==6 && !ser.empty());
    ser.str("");
    ser= short(32767) + ser;
	
	cout<<"testShorts + (Non-member)\n";
	//testShorts
    assert(ser.str()=="\x73\x20\x7f\xff"s && ser.size()==4 && !ser.empty());
    ser.str("");
    ser= short(6) + ser;
    assert(ser.str()=="\x73\x06"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= short(-10) + ser;
    assert(ser.str()=="\x73\x1f\xf6"s && ser.size()==3 && !ser.empty());
    ser.str("");
    ser= short(0) + ser;
    assert(ser.str()=="\x73\x00"s && ser.size()==2 && !ser.empty());
    ser.str("");
    ser= short(-32768) + ser;
    assert(ser.str()=="\x73\x2f\x80\x00"s && ser.size()==4 && !ser.empty());
    ser.str("");
	
	cout<<"testStrings + (Non-member)\n";
	//testStrings
    ser= "This is HW2 test case."s + ser;
    assert(ser.str()=="\x53\x10\x16\x54\x68\x69\x73\x20\x69\x73\x20\x48\x57\x32\x20\x74\x65\x73\x74\x20\x63\x61\x73\x65\x2e"s && ser.size()==25 && !ser.empty());
    ser.str("");
    ser= "Today is 12/02/2018 @csu & that's it."s + ser;
    assert(ser.str()=="\x53\x10\x25\x54\x6f\x64\x61\x79\x20\x69\x73\x20\x31\x32\x2f\x30\x32\x2f\x32\x30\x31\x38\x20\x40\x63\x73\x75\x20\x26\x20\x74\x68\x61\x74\x27\x73\x20\x69\x74\x2e"s && ser.size()==40 && !ser.empty());
    ser.str("");
    ser= "#HW2	#CS253{}"s + ser;
    assert(ser.str()=="\x53\x10\x0d\x23\x48\x57\x32\x09\x23\x43\x53\x32\x35\x33\x7b\x7d"s && ser.size()==16 && !ser.empty());
    ser.str("");

	cout<<"\nUnserializing with <<=\n\n";
	//testGETS
    try {
        cout<<"testBool <<=\n";
        //testBool
        ser.str("tf");
        b<<=ser;
        assert(b);
        b<<=ser;
        assert(!b);
        
		
		cout<<"testAll <<=\n";
		//testAll
        ser.str("\x69\x20\x86\x46"s);
        i <<= ser;
        assert(i == 34374);
        ser.str("\x73\x1f\xac"s);
        s <<= ser;
        assert(s == -84);
        ser.str("\x63\x67"s);
        c <<= ser;
        assert(c == 'g');
        ser.str("\x53\x10\x15\x61\x6c\x6c\x20\x74\x79\x70\x65\x20\x6f\x66\x20\x74\x65\x73\x74\x20\x64\x61\x74\x61"s);
        S <<= ser;
        assert(S == "all type of test data"s);
        ser.str("\x6c\x41\xc8\xf6\x5a\x34"s);
        l <<= ser;
        assert(l == 7666555444);
        ser.str("\x63\x60"s);
        c <<= ser;
        assert(c == '`');
        ser.str("\x53\x10\x0b\x20\x54\x48\x41\x4e\x4b\x09\x79\x6f\x75\x09"s);
        S <<= ser;
        assert(S == " THANK	you	"s);
		
		cout<<"testChars <<=\n";
		//testChars
        ser.str("\x63\x21"s);
        c <<= ser;
        assert(c == '!');
        ser.str("\x63\x40"s);
        c <<= ser;
        assert(c == '@');
        ser.str("\x63\x25"s);
        c <<= ser;
        assert(c == '%');
        ser.str("\x63\x5e"s);
        c <<= ser;
        assert(c == '^');
        ser.str("\x63\x2d"s);
        c <<= ser;
        assert(c == '-');
        ser.str("\x63\x3a"s);
        c <<= ser;
        assert(c == ':');
        ser.str("\x63\x7c"s);
        c <<= ser;
        assert(c == '|');
        ser.str("\x63\x09"s);
        c <<= ser;
        assert(c == '	');
        ser.str("\x63\x2f"s);
        c <<= ser;
        assert(c == '/');
        ser.str("\x63\x35"s);
        c <<= ser;
        assert(c == '5');
        ser.str("\x63\x66"s);
        c <<= ser;
        assert(c == 'f');
        ser.str("\x63\x22"s);
        c <<= ser;
        assert(c == '"');
        ser.str("\x63\x2c"s);
        c <<= ser;
        assert(c == ',');
        ser.str("\x63\x2b"s);
        c <<= ser;
        assert(c == '+');
		
		cout<<"testInts <<=\n";
		//testInts
        ser.str("\x69\x20\x88\xb8"s);
        i <<= ser;
        assert(i == 35000);
        ser.str("\x69\x40\x7f\xff\xff\xff"s);
        i <<= ser;
        assert(i == 2147483647);
        ser.str("\x69\x4f\x80\x00\x00\x00"s);
        i <<= ser;
        assert(i == -2147483648);
        ser.str("\x69\x20\x80\x00"s);
        i <<= ser;
        assert(i == 32768);
        ser.str("\x69\x2f\x7f\xff"s);
        i <<= ser;
        assert(i == -32769);
		
		cout<<"testLongs <<=\n";
		//testLongs
        ser.str("\x6c\x40\xb9\x71\x7c\x3d"s);
        l <<= ser;
        assert(l == 3111222333);
        ser.str("\x6c\x4e\xf0\x76\x0a\xa7"s);
        l <<= ser;
        assert(l == -4555666777);
        ser.str("\x6c\x80\x7f\xff\xff\xff\xff\xff\xff\xff"s);
        l <<= ser;
        assert(l == 9223372036854775807);
        ser.str("\x6c\x8f\x80\x00\x00\x00\x00\x00\x00\x00"s);
        l <<= ser;
        assert(l == -9223372036854775807-1);
        ser.str("\x6c\x40\x80\x00\x00\x00"s);
        l <<= ser;
        assert(l == 2147483648);
        ser.str("\x6c\x4f\x7f\xff\xff\xff"s);
        l <<= ser;
        assert(l == -2147483649);
		
		cout<<"testShorts <<=\n";
		//testShorts
        ser.str("\x73\x20\x7f\xff"s);
        s <<= ser;
        assert(s == 32767);
        ser.str("\x73\x06"s);
        s <<= ser;
        assert(s == 6);
        ser.str("\x73\x1f\xf6"s);
        s <<= ser;
        assert(s == -10);
        ser.str("\x73\x00"s);
        s <<= ser;
        assert(s == 0);
        ser.str("\x73\x2f\x80\x00"s);
        s <<= ser;
        assert(s == -32768);
		
		cout<<"testStrings <<=\n";
		//testStrings
        ser.str("\x53\x10\x16\x54\x68\x69\x73\x20\x69\x73\x20\x48\x57\x32\x20\x74\x65\x73\x74\x20\x63\x61\x73\x65\x2e"s);
        S <<= ser;
        assert(S == "This is HW2 test case."s);
        ser.str("\x53\x10\x25\x54\x6f\x64\x61\x79\x20\x69\x73\x20\x31\x32\x2f\x30\x32\x2f\x32\x30\x31\x38\x20\x40\x63\x73\x75\x20\x26\x20\x74\x68\x61\x74\x27\x73\x20\x69\x74\x2e"s);
        S <<= ser;
        assert(S == "Today is 12/02/2018 @csu & that's it."s);
        ser.str("\x53\x10\x0d\x23\x48\x57\x32\x09\x23\x43\x53\x32\x35\x33\x7b\x7d"s);
        S <<= ser;
        assert(S == "#HW2	#CS253{}"s);
        
    } catch (string msg) {
			cerr << "Unserialize error: "s << msg << '\n';
	}
	
	cout<<"\nBegin error testing.\n\n";
	
	cout<<"Checking: not a boolean\n";
	bool caught = false;
	try{
		ser.str("\x37"s);
		ser.get(b);
	}
	catch (string msg) {
		caught = true;
	}
	assert(caught); caught = false;

	
	cout<<"Checking: not a tagged short\n";
	try{
		ser.str("\x69\x20\x9a\x6e"s);
		ser.get(s);			
	}
	catch (string msg) {
		caught = true;
	}
	assert(caught); caught = false;
	
	
	cout<<"Checking: too big for short\n";
	try{
		ser.str("\x73\x20\x9a\x6e"s);
		ser.get(s);			
	}
	catch (string msg) {
		caught = true;
	}
	assert(caught); caught = false;
	
	
	cout<<"Checking: not a tagged int\n";
	try{
		ser.str("\x6c\x42\x4a\x13\xfe\xf1"s);
		ser.get(i);			
	}
	catch (string msg) {
		caught = true;
	}
	assert(caught); caught = false;
	
	
	cout<<"Checking: too big for int\n";
	try{
		ser.str("\x69\x42\x4a\x13\xfe\xf1"s);
		ser.get(i);			
	}
	catch (string msg) {
		caught = true;
	}
	assert(caught); caught = false;
	
	
	cout<<"Checking: not a tagged long\n";
	try{
		ser.str("\x73\x20\x9a\x6e"s);
		ser.get(l);			
	}
	catch (string msg) {
		caught = true;
	}
	assert(caught); caught = false;
	
			
	cout<<"Checking: too big for long\n";
	try{
		ser.str("\x6c\x90\x00\x7f\xff\xff\xff\xff\xff\xff\xff"s);
		ser.get(l);			
	}
	catch (string msg) {
		caught = true;
	}
	assert(caught); caught = false;
	
	
	cout<<"Checking: not a tagged char\n";
	try{
		ser.str("\x69\x2b"s);
		ser.get(c);			
	}
	catch (string msg) {
		caught = true;
	}
	assert(caught); caught = false;
	
	
	cout<<"Checking: not a tagged string\n";
	try{
		ser.str("\x73\x10\x16\x54\x68\x69\x73\x20\x69\x73\x20\x48\x57\x32\x20\x74\x65\x73\x74\x20\x63\x61\x73\x65\x2e"s);
		ser.get(S);			
	}
	catch (string msg) {
		caught = true;
	}
	assert(caught); caught = false;
	
	
// 	cout<<"Checking: length too large (string)\n";
// 	try{
// 		ser.str("\x53\x10\x25\x54\x68\x69\x73\x20\x69\x73\x20\x48\x57\x32\x20\x74\x65\x73\x74\x20\x63\x61\x73\x65\x2e"s);
// 		ser.get(S);			
// 	}
// 	catch (string msg) {
// 		caught = true;
// 	}
// 	assert(caught); caught = false;
	
	
// 	cout<<"Checking: length too large (number)\n";
//     
// 	try{
// 		ser.str("\x69\x62\x4a\x13\xfe\xf1"s);
// 		ser.get(i);			
// 	}
// 	catch (string msg) {
// 		caught = true;
// 	}
// 	assert(caught); caught = false;
// 	
	cout << "\nAll errors caught\n\n";
    cout<<"Running Jack's test\n\n";
    ser.str("");
    ser+=true;
    ser.put(-1);
	const Serial t(ser);	    // s = t = true -1
	assert(t == ser);

 	ser.get(b); 
    assert(b);	    // s = -1
  	ser = ser + 'x';		    // s = -1 'x'
  	assert(ser != t);
	ser = (1L<<63) + t;	    // s = LONG_MIN true -1
 
 	assert((ser+t).str() == "l\x8f\x80\0\0\0\0\0\0\0ti\x0fti\17"s);
 
 	caught = false;
 	try {
 		ser.get(b);
 	}
 	catch (string st) {
 		caught = true;
 	}
 	assert(caught);
 
	l <<= ser; assert(l == 1L<<63);   // true -1

	const string now = "2018-04-15T09:48:31.196607";
	ser += now;			// true -1 now
	ser.get(b);			// -1 now
	ser.get(i);			// now
	string foo="bar";
	ser.get(foo);
	assert(foo == now);

	cout << "Test ends\n\n";
    cout << "Remember, you aren't really finished until C-Strings produce a compile-time error.\n";
    cout << "Check out the top of the test file for some C-style fun! ¯\\_(ツ)_/¯\n";

	return 0;
}

  
