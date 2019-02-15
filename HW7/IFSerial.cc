#include "FSerial.h"
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include<iomanip>

#include <cassert>

using namespace std;


IFSerial::IFSerial(const string &f){
    in.open(f);
    if(in.good()){
        safe = true;
    }else{safe =false;in.setstate(ios_base::failbit);}
}

IFSerial::~IFSerial(){in.close();}
// -----------------------------------------------Checking bits-----------------------------------------
 int nBits(long i){
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
// -----------------------------------------------End of checking bits-----------------------------------------
// -----------------------------------------------UNSERIALIZE(GET)-----------------------------------------
long calculateInt(ifstream &in,bool &safe){
    char chara;
     if(!in.get(chara)){safe=false;}
    int length =chara&0xff;
    length = length>>4;
//     cout<<"Lenght: " <<length<<"\n";
    int *nibble = new int[length+1];
    int n = chara;
    nibble[0] = n&0x0f;
    if(length!=0){
        for(int i =1; i<=length; i++){
            if(!in.get(chara)){safe=false;}
            nibble[i] = chara&0xff;
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

IFSerial& IFSerial::operator>>(bool &b){
    char a;
   if(in.get(a)){
            if(a=='t'){
            b= true;
        }else if(a=='f'){
            b = false;
        }else{
            safe=false;/*in.setstate(ios_base::failbit);*/
        }
    }else{safe=false; }
    return *this;
}

IFSerial& IFSerial::operator>>(char &c){
    char a;
     if(in.get(a)){
//        /* cout<<"IN IFSerial::Type:"<<a<<"....";*/
        if(a!='c'){
            safe=false;;/*in.setstate(ios_base::failbit)*/;
        }
        if(in.get(a)){
//         cout<<"CHAR:"<<a<<"\n";
        c=a;  }else{safe=false; }
    }else{safe=false; }
    return *this;
}

IFSerial& IFSerial::operator>>(int &n){
    char a;
    if(in.get(a)){
//        /* cout<<"IN IFSerial::Type:"<<a<<"....";*/
        if(a!='i'){
            safe=false; 
        }
        long number =calculateInt(in,safe);
        if(nBits(number)>32){safe=false; }
        n = number;
//         cout<<"Number:"<<n<<"\n";
        
    }else{safe=false;}
    return *this;
}

IFSerial& IFSerial::operator>>(short &n){
    char a;
    if(in.get(a)){
       /* cout<<"IN IFSerial::Type:"<<a<<"....";*/
        if(a!='s'){
            safe=false; 
        }
        long number =calculateInt(in,safe);
        
        if(nBits(number)>16){safe=false;}
        n = number;
//         cout<<"Number:"<<n<<"\n";
        
    }else{safe=false; }
    return *this;
}

IFSerial& IFSerial::operator>>(long &n){
     string error;
    char a;
    if(in.get(a)){
    if(a!='l'){safe=false;}  
    n=calculateInt(in,safe);
        
    }else{safe=false; }
    return *this;
}

IFSerial& IFSerial::operator>>(string &str){
    char a;
    str = "";
    if(in.get(a)){
        if(a!='S'){safe=false;}
    int lenght = calculateInt(in,safe);
        for(int i =0 ; i<lenght ; i++){
            if(in.get(a)){
            int num = a;
            str += char(num);}
            else{safe=false;}
        }
        
    }else{safe=false; }
    return *this;
}

bool IFSerial::eof() const{
    return in.eof();
}

bool IFSerial::fail() const{
    return !safe;
}

IFSerial::operator bool() const{
    return safe;
}

