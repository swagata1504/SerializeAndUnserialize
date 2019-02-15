#ifndef FSERIAL_H_INCLUDED
#define FSERIAL_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>

class OFSerial{
public:
    //OFSerial(); //default constructor 
    OFSerial(const std::string &);
    ~OFSerial();//Destructor
    
    OFSerial& operator<<(const char);
    OFSerial& operator<<(const bool);
    OFSerial& operator<<(const int);
    OFSerial& operator<<(const short);
    OFSerial& operator<<(const long);
    OFSerial& operator<<(const std::string);
    bool fail() const;
    operator bool() const;
private:
 //   std::string filename;
    std::ofstream stream;
    bool safe;
};

class IFSerial{
public:
    IFSerial(const std::string &);
    ~IFSerial();//Destructor
    
    IFSerial& operator>>(bool &);
    IFSerial& operator>>(char &);
    IFSerial& operator>>(int &);
    IFSerial& operator>>(short &);
    IFSerial& operator>>(long &);
    IFSerial& operator>>(std::string &);
    bool fail() const;
    bool eof() const;
    operator bool() const;
private:
    //std::string filename;
    std::ifstream in;
    bool safe;
};
#endif
