#include <iostream>
 #include<iomanip>
 #include <string> 
#include <sstream>
#include <math.h>       /* pow */
using namespace std;

int main(){
    long n;

    while (cin >> n) {
       int count = 0;
       long i= n;
       //this is to find the number of bits
       if(i>0){
            while(i!=0){
                i>>=1;
                count++;
            }           
        }else{
            i*=(-1);
            long long c =i;
            while(i!=0){
                i>>=1;
                count++;
            }
            if(c==8||c==2048||c==pow (2, 19)||c==pow (2, 27)||c==pow (2, 35)||c==pow (2, 43)){count--;}//this is for all the numbers that are in the bounderies of changing the lenght bit
        }
       
        cout << dec << n;//printing out the input number for format
        int lenght =0;
        
        while(count>=((8*lenght)+4)){
            lenght++;//getting the lenght by using the formula provided in the hw 
        }        
        int nibbles[lenght+1];//making the array of nibbles
        for(int x = 0; x<=lenght; x++){
            nibbles[x] = n&0xff;//masking the two ending bits to make a nibble and adding into the array
            n= n>>8;//shifting the number to get the next nibble for the next loop
        }
        if(count<4){                                                             //FOR 4 BIT NUMBERS
           cout << ": " << hex << setw(2) << setfill('0') << (nibbles[0] & 0x0f) << "\n";//PRINTING OUT WITH LENGHT
        }else{
            cout << ": "<<lenght <<hex<< setw(1) << setfill('0') << (nibbles[lenght] & 0x0f) <<" ";//printing out the last element in the array to get the correct nibble since the array has the whole thing reversed
            int x = lenght-1;//starting form the next nibble after the first one
            while(x>=0){
                cout<<hex<<setw(2) << setfill('0') <<(nibbles[x]&0xff)<<" ";
                x=x-1;
            }
            cout<<"\n";
        }
    }  
    //this is for the error message
    if (!cin.eof()){
        cerr << "Error occured. Must be non-numeric data.\n";
        return -1;
    }
    return 0;
}
