#include "functions.h"
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include<iomanip>

using namespace std;

long calculateInt(istream &in){
    char chara;
    in.get(chara);
    int length =chara&0xff;
    length = length>>4;
//     cout<<"Lenght: " <<length<<"\n";
    int nibble[length+1];
    int n = chara;
    nibble[0] = n&0x0f;
    if(length!=0){
        for(int i =1; i<=length; i++){
            in.get(chara);
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

//this is to find the number of bits
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

void IntSer( long n,  ostream &stream){
    int count = numberBits(n);
    int lenght =0;
    while(count>=((8*lenght)+4)){
        lenght++;//getting the lenght by using the formula provided in the hw stringstream
    }
    int nibbles[lenght+1];//making the array of nibbles
    for(int x = 0; x<=lenght; x++){
        nibbles[x] = n&0xff;//masking the two ending bits to make a nibble and adding into the array
        n= n>>8;//shifting the number to get thstr>>n;e next nibble for the next loop
    }
    int vnum = lenght<<4;
    nibbles[lenght] = (nibbles[lenght]&0x0f);
    nibbles[lenght] = (nibbles[lenght]|vnum);
    if(count<4){
        stream<< char(nibbles[lenght]);
    }else{
        stream<<char(nibbles[lenght]);//printing out the last element in the array to get the correct nibble since the array has the whole thing reversed
        int x = lenght-1;//starting form the next nibble after the first one
        while(x>=0){
            stream<<char(nibbles[x]);
            x=x-1;
        }
    }
}

void serialize(bool b, ostream &out){
    char a;
    if(b){
        a = 't';
    }else{a ='f';}
    out<<a;
}

void serialize(char c, ostream &out){
    out<<'c'<<c;
}

void serialize(short n, ostream &out){
    out << 's';
    IntSer(n, out);
}

void serialize(int n, ostream &out){
    out << 'i';IntSer(n, out);
}

void serialize(long n, ostream &out){
    out << 'l';
    if(abs(n)-1== 9223372036854775807){
         out<<char(0x8f) << char(0x80);
         for(int i =0; i < 7;i++){
             out<<char(0x00);
        }
        
    }else{IntSer(n, out);}
     

}

void serialize(const string &s, ostream &out){
    out<<'S';
    int len = s.length();
    IntSer(len,out);
    for(unsigned int i=0; i< s.length(); i++){
       out<<s[i];
    }
}

void unserialize(istream &in, bool &b){
    string error;
    char a;
    in.get(a);
    if(a=='t'){
        b= true;
    }else if(a=='f'){
        b = false;
    }else{
        error = "Please enter the correct format for a boolean\n";
        throw error;
    }
}

void unserialize(istream &in, char &c){
    string error;
    char a;
    in.get(a);
    if(a!='c'){
        error = "Wrong tag or wrong datatype used for char\n";
        throw error;
    }
    in.get(a);
    c=a;
}


void unserialize(istream &in, short &n){
    string error;
    char a;
    in.get(a);
    if(a!='s'){error= "Wrong tag or wrong datatype used for short integer\n";throw error;}  
    long number =calculateInt(in);
    if(numberBits(number)>16){error= "This doesn't fit in the range of the short values\n";throw error;}
    n = number;
}

void unserialize(istream &in, int &n){
    string error;
    char a;
    in.get(a);
    if(a!='i'){error= "Wrong tag or wrong datatype used for ints\n";throw error;}  
    long number =calculateInt(in);
    if(numberBits(number)>32){error= "This doesn't fit in the range of the int values\n";throw error;}
    n = number;
}

void unserialize(istream &in, long &n){
    string error;
    char a;
    in.get(a);
    if(a!='l'){error= "Wrong tag or wrong datatype used for long integer\n";throw error;}  
    n=calculateInt(in);
}


void unserialize(istream &in, string &str){
    string error;
    char a;
    str = "";
    in.get(a);
    if(a!='S'){error= "Wrong tag or wrong datatype used for string variable\n";throw error;}  
    int lenght = calculateInt(in);
    for(int i =0 ; i<lenght ; i++){
        if(in.get(a)){
        int num = a;
        str += char(num);}
        else{error= "The string length vnum is too long!\n";throw error;}
    }
    if(in.get(a)){error= "The string length vnum is too short!\n";throw error;}
}

