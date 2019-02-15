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
    
    template<typename T>
    void checker(const T s);
    
    void put(const bool);
    void put(const short);
    void put(const int);
    void put(const long);
    void put(const char);
    void put(const std::string );
    
    template<typename T>
    Serial& plusE(const T);
    template<typename T>
    Serial plus(const T)const;
    
    Serial& operator+=(const bool);
    Serial& operator+=(const short);
    Serial& operator+=(const int);
    Serial& operator+=(const long);
    Serial& operator+=(const char);
    Serial& operator+=(const std::string);
    Serial& operator+=(const Serial);
    
    Serial operator+(const bool) const; 
    Serial operator+(const short) const; 
    Serial operator+(const int) const; 
    Serial operator+(const long) const; 
    Serial operator+(const char) const; 
    Serial operator+(const std::string) const; 
        
    void get(bool &);
    void get(char &);
    void get(short &);
    void get(int &);
    void get(long &);
    void get(std::string &);
    
    bool operator==(const Serial&)const;
    bool operator!=(const Serial&)const;    
    
    int size()const;
    std::string str()const; 
    void str(std::string);
    long calculateInt();
    bool empty()const;
private:
    std::string word;
};

void operator<<=(bool &, Serial &);
void operator<<=(char &, Serial &);
void operator<<=(short &, Serial &);
void operator<<=(int &, Serial &);
void operator<<=(long &, Serial &);
void operator<<=(std::string &, Serial &);

template<typename T>
Serial Dplus(const T, const Serial);

Serial operator+(const bool, const Serial);
Serial operator+(const char, const Serial);
Serial operator+(const short, const Serial);
Serial operator+(const int, const Serial);
Serial operator+(const long, const Serial);
Serial operator+(const std::string, const Serial);
Serial operator+(const Serial, const Serial);


#endif 
