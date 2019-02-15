#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h> 
#include <cctype>
#include <unistd.h>
#include <string> 
#include<iomanip>
using namespace std;
//UNSERIALIZE START

long calculateInt(int nibble[],int length){
    long a=0;
    int c= nibble[0]&0x8;
    c=c>>3;
    if(c==1){a=-1;}
    if(length==0){ a=a<<4; a = a|nibble[0];}
    else{
        a=a<<4;
        a= nibble[0]|a;
//        cout<<"Nibble 1:"<<a<<"\n";
        for(int i =1; i<=length; i++){
            a=a<<8; 
            a = a|nibble[i];
        }
    }
    return a;
}

//UNSERIALIZE ENDING
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//SERIALIZE START
void CharSer(char c){
    int n = 'c'; 
    cout << hex << n<<" ";

    int a =c;
    cout<< hex<< a<<"\n"; 
}

void IntSer(long n, int count){       

      int lenght =0;
      while(count>=((8*lenght)+4)){
          lenght++;//getting the lenght by using the formula provided in the hw stringstream
      }        
      int nibbles[lenght+1];//making the array of nibbles
      for(int x = 0; x<=lenght; x++){
          nibbles[x] = n&0xff;//masking the two ending bits to make a nibble and adding into the array
          n= n>>8;//shifting the number to get thstr>>n;e next nibble for the next loop
      }
      if(count<4){                                                             //FOR 4 BIT NUMBERS
          cout<< hex << setw(2) << setfill('0') << (nibbles[0] & 0x0f)<<" " ;//PRINTING OUT WITH LENGHT
      }else{
          cout<<lenght <<hex<< setw(1) << setfill('0') << (nibbles[lenght] &0x0f) <<" ";//printing out the last element in the array to get the correct nibble since the array has the whole thing reversed
          int x = lenght-1;//starting form the next nibble after the first one
          while(x>=0){
              cout<<hex<<setw(2) << setfill('0') <<(nibbles[x]&0xff)<<" ";
              x=x-1;
          }
      }
 }
// //this is to find the number of bits
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
 void intType(long i){
     int bits=numberBits(i);
     int n=0;
     if(bits<16){
         n = 's';       
         cout << hex << n<<" ";
     }else if(bits<32){
         n = 'i';       
         cout << hex << n<<" ";
     }else{
         n = 'l';        
         cout << hex << n<<" ";
     }
}

void stringSer(string s){
     int n = 'S';       
     cout << hex << n<<" ";
     int len = s.length();
     IntSer(len,numberBits(len));
     for(unsigned int i=0; i< s.length(); i++){
         int x = s[i];
         cout<< hex << x<<" ";
     }
    cout<<"\n";
}

//UNSERIALIZING!!! 
void unserializeEverything(char* file){
    ifstream in(file);
    if(!in.is_open()){
        cerr<<"Error in opening the "<<file<<" file.\n";
        exit(0);
    }else{
        int n;//the input
        while(in>>hex>>n){
            int datatype = n;
           // cout<<"Datatype: "<<hex<<datatype<<"\n";
            
            if(datatype=='t'||datatype=='f'){if(datatype=='t'){cout<<"true\n";}else{cout<<"false\n";}}
            else if(datatype=='c'){in>>hex>>n; char i = n; cout<< "\'"<<i<<"\'\n";}
            else if(datatype=='s'||datatype=='l'||datatype=='i'||datatype=='S'){
                in>>n;
                int length =n&0xf0;
                length = length>>4;//cout<<"Lenght: " <<length<<"\n";
                int nibble[length];
                nibble[0] = n&0x0f;
                if(length!=0){
                    int i =1;
                    while(in>>hex>>n){
                        nibble[i] = n;
                        i++;
                        if(i>length){break;}
                    }
                }
               // cout<<"Nibble array: ";
               // for(int r = 0; r <=length; r++){cout<<nibble[r]<<" ";}
               // cout<<"\n";
                long number = calculateInt(nibble,length);
//                     cout<<"CURRENT STREAM"<<n<<"\n";
                if((numberBits(number)>=16)&&(datatype=='s')){cout<<"Please enter the right the identifyer for the number.\n"; exit(0);}
                if((numberBits(number)>=32)&&(datatype=='i')){cout<<"Please enter the right the identifyer for the number.\n"; exit(0);}
                if(datatype=='S'){  /*cout<<"string lenght:"<<number<<"\n";*/
                    string output;
                    for(int i = 0; i<number; i ++){
                            in>>n;/*cout<<"NUMBER IN STRING: "<<hex<<n<<"\n";*/
                            char a=n;                                  
                            output+=a;
                    }
                    cout<<"\""<<output<<"\"\n";
                }else{
                    cout/*<<"Number: "*/<<dec<<number<<"\n";
                }
            }else{cerr<<"Please use proper format.\n"; exit(0);}
        }
        if(!in.eof()){
            cerr<< "Error occured. Enter a something that makes sense\n";
            exit(1);
        }    
    }      
}

void serializeEverything(char* file){
    ifstream in(file);
    if(!in.is_open()){
        cerr<<"Error in opening the "<<file<<" file.\n";exit(0);
    }
    char d;
    //cout<<"Hello\n";
    while(in.get(d)){
        if(d=='\"'){//String checking if it has a "
            string g;
            in.get(d);
            while(d!='\"'){
                    g+=d;
                    in.get(d);
                    if(in.eof()){
                        cerr<<"Please enter something that makes sense\n";
                        exit(0);
                }
            }
            stringSer(g);
            
        }else if(d=='\''){//checks if it has '
            in.get(d);
            char a = d;
            in.get(d);
            if(d=='\''){
                CharSer(a);
            }else{
                cerr << "Error occured. Enter in this format: '<single-character>'\n";
                exit(0);
            }        
        }else if (!isspace(d)){//int
            //cout<<"int!!\n";
            string s;
            while(!isspace(d)||d!='\n'){
                s+=d;
                in.get(d);
                if(isspace(d)){break;}
            }
//             cout<<"string number: "<<s<<"\n";
            if(s=="true"||s=="false"){
                int n;
                if(s=="true"){n = 't';cout<<hex<<n;}
                    else{n = 'f';cout<<hex<<n;}
            }else if(s=="-9223372036854775808"){
                cout<<"6c 80 08 00 00 00 00 00 00 00";
            }else{
                long n;
                stringstream str(s);
                str>>n;/*cout<<"Number: "<<dec<<n<<"\n";*/
                if(str.fail()){
                    cerr<< "Error occured. Enter a something that makes sense\n";
                    exit(1);
                }else{
                //cout<<dec<<n<<": "<<dec<<numberBits(n)<<"\n";
                    intType(n);//printing out the datatype accordingly
                    IntSer(n,numberBits(n));//prints the serialization
                }
            }cout<<"\n";
        }
    }if(!in.eof()){
            cerr<< "Error occured. Enter a something that makes sense\n";
            exit(1);
    }
    
}


int main(int argc, char* argv[]){
    if(argc<2){
        cout<<"Please enter filename\n";
        exit(0);
        
    }else{
         int opt;
         bool sBool = false;
         bool uBool = false;
         bool vBool = false;
         while ((opt = getopt(argc, argv, "+suv")) != -1) {
             switch (opt) {
             case 's': sBool = true; break;
             case 'u':uBool = true;break;
             case 'v':vBool = true;break;
             default: exit(1);
             }
         }
         for(int i = optind; i <argc;i++){
             if(sBool&&uBool){
                 cerr<<"Wrong entry. Please enter either [-u] or [-s] not both together\n";
                 exit(0);
             } if(sBool){//serialize
                 if(vBool){cerr<<"Processing file "<<argv[i]<<"\n";}
                 serializeEverything(argv[i]);
            } if(uBool){
                  if(vBool){cerr<<"Processing file "<<argv[i]<<"\n";}
                  unserializeEverything(argv[i]);
              }if(!sBool&&!uBool){
                  serializeEverything(argv[i]);
              }if(vBool){cerr<<"Processing file "<<argv[i]<<"\n";}            
            }
        
        }
    return 0;
}

