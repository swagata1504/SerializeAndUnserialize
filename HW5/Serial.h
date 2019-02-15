#ifndef SERIAL_H_INCLUDED
#define SERIAL_H_INCLUDED
#include <string>
#include <iostream>

class Serial{

public:
    Serial(); //default constructor
    Serial(const Serial &);//Copy constructor
    ~Serial();//Destructor
    Serial &operator=(const Serial &);//Assignment operator
    
    void put(const bool);
    void put(const short);
    void put(const int);
    void put(const long);
    void put(const char);
    void put(const std::string );
    
    void get(bool &);
    void get(char &);
    void get(short &);
    void get(int &);
    void get(long &);
    void get(std::string &);
    int size()const;
    std::string str()const; 
    void str(std::string);
    long calculateInt();
    bool empty()const;
private:
    std::string word;
};

#endif 
