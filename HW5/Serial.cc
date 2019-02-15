#include "Serial.h"
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include<iomanip>

#include <cassert>

using namespace std;

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
void Serial::put(const bool b){
    if(b){word+='t';
    }else{
        word+='f';}
}


//char put
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
    word = word.substr(1,3);
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

int Serial::size()const{
    return word.length();;
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
