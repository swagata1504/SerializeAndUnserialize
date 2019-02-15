 I/O Streams!                

Description                
For this assignment, you will write two classes, IFSerial and OFSerial. They will behave much like ifstream and ofstream, except that they will read & write serialized data.                 

Methods                
Your classes must have the folowing operators & methods:                 

IFSerial:

ctor that takes a std::string filename
dtor
IFSerial >> bool
IFSerial >> int
IFSerial >> short
IFSerial >> long
IFSerial >> char
IFSerial >> std::string
IFSerial.eof()
IFSerial.fail()
Evaluation in a boolean context.
OFSerial:

ctor that takes a std::string filename
dtor
OFSerial << bool
OFSerial << int
OFSerial << short
OFSerial << long
OFSerial << char
OFSerial << std::string
OFSerial.fail()
Evaluation in a boolean context.
The above may be methods, or free functions, as you wish.                 

Const-correctness, both arguments & methods, is your job. For example, it must be possible to call .eof() on a const IFSerial.                 

You may add other functions, methods, or operators, public or private, as you wish.                 

.eof()                
.eof() will return true if and only if end-of-file has been encountered. It reflects the past; it does not predict the future.
.fail()                
.fail() will return true if and only if a conversion has failed, or if the given filename can’t be opened in the desired manner.
Boolean context                
Evaluating an IFSerial or OFSerial in boolean context yields the opposite boolean result than .fail().
FSerial.h                
The header file FSerial.h will contain class declarations for both IFSerial and OFSerial.
Include FSerial.h and any necessary code in your hw7.tar.
Errors                
None of the required methods, functions, or operators should write to cout or cerr, throw anything, or exit.
Instead, if an error is detected, .fail() should return true.
Failure is “sticky”. That is, once a stream enters the failure state, it stays in the failure state. Unfortunately, no method is defined to clear the failure state.
Same for end-of-file.
