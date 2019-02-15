#include "Serial.h"
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include<iomanip>

#include <cassert>

using namespace std; 

template<class T>
struct is_const_char
  : std::integral_constant<
      bool,
      std::is_same<char const *, typename std::decay<T>::type>::value ||
      std::is_same<char *, typename std::decay<T>::type>::value
> {};



Serial::Serial(): word(""){}

Serial::Serial(const Serial &rhs): word(rhs.word){}

Serial::~Serial(){}

Serial &Serial::operator=(const Serial &rhs){
    word = rhs.word;
    return *this;
}
// -----------------------------------------------UNSERIALIZE(GET)-----------------------------------------
long Serial::calculateInt(){
    
    int n = (int)word[0];
    int length =n&0xff;
    length = length>>4;
//     cout<<"Lenght: " <<length<<"\n";
    int nibble[length+1];
    nibble[0] = n&0x0f;
    word = word.substr(1,word.length());
    if(length!=0){
        for(int i =1; i<=length; i++){
            int num = (int)word[0];
            nibble[i] = num&0xff;
            word = word.substr(1,word.length());
//             cout<<hex<<nibble[i]<<"\n";
        }
    }
    
//     cout<<"nibble: ";
//     for(int i =0; i <=length; i++){
//         cout<<hex<<nibble[i]<<" ";
//     }
    long a=0;
    int c= nibble[0]&0x8;
    c=c>>3;
    if(c==1){a=-1;}
    if(length==0){ a=a<<4; a = a|nibble[0];}
    else{
        a=a<<4;
        a= nibble[0]|a;
        for(int i =1; i<=length; i++){
            a=a<<8; 
            if(nibble[i]==-1){
                a = a|0xff;
            }else{
                a = a|nibble[i];
            }
        }
    }/*cout<<"NUMBER: "<<a<<"\n";*/
    return a;
}
// -----------------------------------------------UNSERIALIZE(GET)-----------------------------------------

// -----------------------------------------------SERIALIZE(PUT)-----------------------------------------

 int numberBits(long i){
      int count=0;
      if(i>0){
          while(i!=0){
              i>>=1;
              count++;
          }
      }else{
          i*=(-1);
          long c = i;
          while(i!=0){

              i>>=1;
              count++;
          }
          if(c==8||c==2048||c==pow (2, 19)||c==pow (2, 27)||c==pow (2, 35)||c==pow (2, 43)||c==pow (2, 51)||c==pow (2, 59)){count--;}
      }
      return count;
}

int calculateNUM(long n){
    int count = numberBits(n);
    int lenght =0;
    while(count>=((8*lenght)+4)){
        lenght++;//getting the lenght by using the formula provided in the hw stringstream
    }
   
    return lenght;
}

string IntSer(long n){
    string word="";
    int count = numberBits(n);
    int lenght =calculateNUM(n);
    int nibbles[lenght+1];//making the array of nibbles
    for(int x = 0; x<=lenght; x++){
        nibbles[x] = n&0xff;//masking the two ending bits to make a nibble and adding into the array
        n= n>>8;//shifting the number to get thstr>>n;e next nibble for the next loop
    }
    int vnum = lenght<<4;
    nibbles[lenght] = (nibbles[lenght]&0x0f);
    nibbles[lenght] = (nibbles[lenght]|vnum);
    if(count<4){
        word+=char(nibbles[lenght]);
    }else{
        word+=char(nibbles[lenght]);//printing out the last element in the array to get the correct nibble since the array has the whole thing reversed
       // cout<<" "<<hex<<nibbles[lenght];
        int x = lenght-1;//starting form the next nibble after the first one
        while(x>=0){
            word+=char(nibbles[x]);
            //cout<<" "<<hex<<nibbles[x];
            x=x-1;
        }
    }
    // cout<<"\n";
    return word;
    
}


// -----------------------------------------------SERIALIZE(PUT) ENDING-----------------------------------------
//bool put
template<typename T>
void Serial::checker(const T s){
    static_assert(!is_const_char<T>::value, "Please enter a C++ style string not a C style string");
    put(s);
}

void Serial::put(const bool b){
    
    if(b){word+='t';
    }else{
        word+='f';}
}

void Serial::put(const char c){
    word+='c';
    word+=c;
}

void Serial::put(const short n){
    word+='s';
    word+=IntSer(n);
}

void Serial::put(const int n){
    word+='i';
    word+=IntSer(n);
}

void Serial::put(const long n){
    word+='l';
    if(abs(n)-1== 9223372036854775807){
        word+=char(0x8f);word+=char(0x80);
        for(int i =0; i < 7;i++){
             word+=char(0x00);
        }
    }else{
        word+=IntSer(n);
    }
}

void Serial::put(const string s){
    word+='S';
    int len = s.length();
    word+=IntSer(len);
    string a;
    for(unsigned int i=0; i< s.length(); i++){
        word+=s[i];
        
    }
}

template<typename T>
Serial& Serial::plusE(const T s){
    this->put(s);
    return *this;
}

Serial& Serial::operator+=(const bool b){   
    return plusE<bool>(b);
}

Serial& Serial::operator+=(const char c){
     return plusE<char>(c);
}

Serial& Serial::operator+=(const short n){
    return plusE<short>(n);
}

Serial& Serial::operator+=(const int n){
    return plusE<int>(n);
}

Serial& Serial::operator+=(const long n){
   return plusE<long>(n);
}

Serial& Serial::operator+=(const string s){
    return plusE<string>(s);
}

Serial& Serial::operator+=(const Serial s){
    this->str(this->str()+=s.str());
    return *this;
}

template<typename T>
Serial Serial::plus(const T s)const{
    Serial temp;
    temp.str(this->str());
    temp.put(s);
    return temp;
}


Serial Serial::operator+(const bool b) const {
    return plus<bool>(b);
}
//char put
Serial Serial::operator+(const char c) const {
    return plus<char>(c);
}

Serial Serial::operator+(const short n) const {
    return plus<short>(n);
}

Serial Serial::operator+(const int n) const {
    return plus<int>(n);
}

Serial Serial::operator+(const long n) const {
    return plus<long>(n);
}


Serial Serial::operator+(const string s) const {
    return plus<string>(s);
}

template<typename T>
Serial Dplus(const T val, const Serial s){
    Serial temp;
    temp.put(val);
    temp.str(temp.str()+s.str());
    return temp;
}


Serial operator+(const bool b, const Serial s){
    return Dplus<bool>(b,s);    
}

Serial operator+(const char c, const Serial s){
    return Dplus<char>(c,s);    
}

Serial operator+(const short n, const Serial s){
    return Dplus<short>(n,s);    
}

Serial operator+(const int n, const Serial s){
    return Dplus<int>(n,s);    
}

Serial operator+(const long n, const Serial s){
    return Dplus<long>(n,s);
}

Serial operator+(const string S, const Serial s){
    return Dplus<string>(S,s);
}

Serial operator+(const Serial a, const Serial b){
    Serial temp;
    temp.str(a.str()+b.str());
    return temp;
}

//bool get
void Serial::get(bool &b){
    string error;
    char a = word[0];
    if(a=='f'){
        b = false;
    }else if(a=='t'){
        b = true;
    }else{
        error = "Please enter the correct format for a boolean\n";
        throw error;
    }
    word = word.substr(1,word.length());
    cout<<"Word: "<<word.length()<<"\n";
}

//char get
void Serial::get(char &c){
    string error;
    char a =word[0];
    if(a!='c'){
        error = "Wrong tag or wrong datatype used for char\n";
        throw error;
    }
    c = word[1];
    word = word.substr(2,word.length());
}

void Serial::get(short &n){
    string error;
    char a =word[0];
    word = word.substr(1,word.length());
   // cout<<word;
    if(a!='s'){
        error = "Wrong tag or wrong datatype used for short\n";
        throw error;
    } 
    long number= calculateInt();
    if(numberBits(number)>=16){error= "This doesn't fit in the range of the short values\n";throw error;}
    n=number;
}

void Serial::get(int &n){
    string error;
    char a =word[0];
    word = word.substr(1,word.length());
    if(a!='i'){
        error = "Wrong tag or wrong datatype used for int\n";
        throw error;
    }
    long number= calculateInt();
    if(numberBits(number)>=32){error= "This doesn't fit in the range of the int values\n";throw error;}
    n=number;
}

void Serial::get(long &n){
    string error;
    char a =word[0];
    word = word.substr(1,word.length());
    //cout<<word;
    if(a!='l'){
        error = "Wrong tag or wrong datatype used for long\n";
        throw error;
    }
    int length =(int)word[0]&0xff;
    length = length>>4;
    if(length>=9){
        error = "The length of the long is too long!!!\n";
        throw error;
    }
    n= calculateInt();
}

void Serial::get(string &str){
    string error;
    str="";
    char a =word[0];
    word = word.substr(1,word.length());
    cout<<a<<"\n";
    if(a!='S'){error= "Wrong tag or wrong datatype used for string variable\n";throw error;}  
    int length= calculateInt();
    for(int i =0 ; i<length ; i++){
        str += (char)word[0];
        word = word.substr(1,word.length());
    }
}


void operator<<=(bool & b, Serial &s){
    s.get(b);
}
void operator<<=(char & c, Serial &s){
    s.get(c);
}
void operator<<=(short & n, Serial &s){
    s.get(n);
}
void operator<<=(int & n, Serial &s){
    s.get(n);
}
void operator<<=(long & n, Serial &s){
    s.get(n);
}
void operator<<=(string & S, Serial &s){
    s.get(S);
}


bool Serial::operator==(const Serial &s)const{
    return (this->str()==s.str());
}

bool Serial::operator!=(const Serial &s)const{
    return (this->str()!=s.str());
}


int Serial::size()const{
    return word.length();
}

void Serial::str(string s){
    word=s;
}

bool Serial::empty()const{
    if(word.length()>0){
        return false;
    }return true; 
}
string  Serial::str() const{
    return word;
}
