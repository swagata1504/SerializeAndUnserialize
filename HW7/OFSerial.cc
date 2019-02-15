#include "FSerial.h"
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include<iomanip>

#include <cassert>

using namespace std;

//FSerial::FSerial(): word(""){}
OFSerial::OFSerial(const string &f){
    stream.open(f);
    if(stream.is_open()){
        safe = true;
    }else{safe =false;}
}
OFSerial::~OFSerial(){stream.close();}

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
    int *nibbles = new int[lenght+1];//making the array of nibbles
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
OFSerial& OFSerial::operator<<(const char c){ 
    string word; 
    word='c';
    word+=c;
//     cout<<"IN OFSerial::WORD:"<<word<<"\n";
    stream<<word;
    return *this;
}

OFSerial& OFSerial::operator<<(const bool b){ 
    string word; 
    if(b){word='t';
    }else{
        word='f';}
    stream<<word;
    return *this;
}

OFSerial& OFSerial::operator<<(const int n){
    string word;
    word='i';
    word+=IntSer(n);
    
    stream<<word;
    return *this;
}

OFSerial& OFSerial::operator<<(const short n){
    string word;
    word='s';
    word+=IntSer(n);
    stream<<word;
    return *this;
    
}

OFSerial& OFSerial::operator<<(const long n){
    string word;
    word+='l';
    if(abs(n)-1== 9223372036854775807){
        word+=char(0x8f);word+=char(0x80);
        for(int i =0; i < 7;i++){
             word+=char(0x00);
        }
    }else{
        word+=IntSer(n);
    }
//     cout<<"IN OFSerial::WORD:"<<n<<"\n";
    stream<<word;
    return *this;
    
}

OFSerial& OFSerial::operator<<(const string s){
    string word;
    word+='S';
    int len = s.length();
    word+=IntSer(len);
    string a;
    for(unsigned int i=0; i< s.length(); i++){
        word+=s[i];
    }
    stream<<word;
    return *this;
    
}

bool OFSerial::fail() const{
    return !safe;
}


OFSerial::operator bool() const{
    return safe;
}
