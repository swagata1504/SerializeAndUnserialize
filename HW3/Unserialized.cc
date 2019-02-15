#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h> 
#include <cctype>
#include <string> 
using namespace std;

long calculateInt(int nibble[],int length){
    long a=0;
    int c= nibble[0]|0x8;
    c=c>>3;
    if(c==1){a=-1;}
    a= nibble[0]&a;
    if(length==0){ a=a<<4; a = a|nibble[0];}
    else{
        for(int i =1; i<=length; i++){
            a=a<<8; 
            a = a|nibble[i];
        }
            
    }
    return a;
}

int main(int argc, char* argv[]){
    if(argc<2){
        cout<<"Please enter filename\n";
        return -1;
        
    }else{

        for(int i=1; i<argc;i++){
            ifstream in(argv[i]);
            if(!in.is_open()){
                cerr<<"Error in opening the "<<argv[i]<<" file.\n";
            }else{
                int n;//the input
                while(in>>hex>>n){
                    int datatype = n;
                    cout<<"Datatype: "<<hex<<datatype<<"\n";
                    if(datatype=='t'||datatype=='f'){if(datatype=='t'){cout<<"true\n";}else{cout<<"false\n";}}
                    else if(datatype=='c'){in>>hex>>n; char i = n; cout<< "\'"<<i<<"\'\n";}
                    else{
                        in>>n;
                        int length =n&0xf0;
                        length = length>>4;cout<<"Lenght: " <<length<<"\n";
                        int nibble[length];
                         nibble[0] = n&0x0f;
                         if(length!=0){int i =1;
                         while(in>>hex>>n){
                             nibble[i] = n;
                             i++;
                             if(i>length){break;}
                         }} cout<<"Nibble array: ";
                         for(int r = 0; r <=length; r++){cout<<nibble[r]<<" ";}
                         cout<<"\n";
                         long number = calculateInt(nibble,length);
                         
                         if(datatype=='S'){
                             string output;
                             for(int i = 0; i<number; i ++){
                                 
                                 in>>n;char a=n;                                  
                                 cout<<a;
                            }
                             cout<<"\n";
                        }else{cout<<"Number: "<<dec<<number<<"\n";}
                }
                }
            }
        }}
            
            
        
    return 0;
        
}

    

