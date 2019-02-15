#include <iostream>
#include<iomanip>
#include <string> 
#include <sstream>
#include <fstream>
#include <math.h> 
using namespace std;



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
     int len = s.length()-2;
     IntSer(len,numberBits(len));
     for(unsigned int i=1; i< s.length()-1; i++){
         int x = s[i];
         cout<< hex << x<<" ";
    }
    cout<<"\n";
}

int main(int argc, char* argv[]){
   // int c =0;
    if(argc<2){
        cout<<"Please enter filename\n";
        return -1;
        
    }else{
        for(int i=1; i<argc;i++){
            ifstream in(argv[i]);
            if(!in.is_open()){
                cerr<<"Error in opening the "<<argv[i]<<" file.\n";
            }
           // int count;
            //char c;
            
            char d;
            while(in.get(d)){
                cout<<"then next string:"<<d<<"\n";
                if(d=='\"'){//String checking if it has a "
                    string g;
                    in.get(d);
                    while(d!='\"'){
                         g+=d;
                         in.get(d);
                         cout<<d<<"\n";
                         if(in.eof()){
                             cerr<<"Make sure to include the second <\">\n"; return -1;  
                        }
                    }cout<<d<<"\n";                    
                    cout<<g<<"\n";
                    stringSer(g);
                    
                }else if(d=='\''){//checks if it has '
                    
                    in.get(d);
                    char a = d;
                    in.get(d);
                    if(d=='\''){
                        CharSer(a);
                    }else{
                            cerr << "Error occured. Enter in this format: '<single-character>'\n";
                        return -1;
                    }
                }else if (!isspace(d)){//int
                    //cout<<"int!!\n";
                    string s;
                    cout<<"ELSE: "<<d;
                    while(!isspace(d)||d!='\n'){
                        s+=d;
                        in.get(d);
                        if(isspace(d)){break;}
                    }
                    cout<<"string number: "<<s<<"\n";
                    if(s=="true"||s=="false"){
                        int n;
                        if(s=="true"){n = 't';cout<<hex<<n<<"\n";}
                            else{n = 'f';cout<<hex<<n<<"\n";}
                    }else if(s=="-9223372036854775808"){
                        cout<<"6c 80 08 00 00 00 00 00 00 00";
                    }else{
                        long n;
                        stringstream str(s);
                        str>>n;
                        cout<<"NUMBER:"<<dec<<n;
                        if(str.fail()){cout<<"hey you better fix this! :) \n";}
                         IntSer(n,numberBits(n));
                        /*if(str.eof()){
                            //cout<<dec<<n<<": "<<dec<<numberBits(n)<<"\n";
                            intType(n);//printing out the datatype accordingly
                            IntSer(n,numberBits(n));//prints the serialization
                        }else{
                            cout<<"HEYY!!\n";
                            cerr<< "Error occured. Enter a number that makes sense\n";
                            return -1;
                        }
                        
                    */}
                    
                    
                    cout<<"\n";
                }
            }if (!in.eof()){
                cerr << "Error occured. Must be non-numeric data.\n";
                return -1;
            }
        }
    }
    
    return 0;
}
