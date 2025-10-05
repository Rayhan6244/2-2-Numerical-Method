#include <iostream>
using namespace std;

int octToDec(int oct){
    int dec=0,b=1;
    while(oct){ dec += (oct%10)*b; b*=8; oct/=10; }
    return dec;
}

void decToHex(int dec){
    if(dec==0){ cout<<"0"; return; }
    char h[20]; int i=0;
    while(dec){ int r=dec%16; h[i++]=r<10?r+'0':r-10+'A'; dec/=16; }
    for(int j=i-1;j>=0;j--) cout<<h[j];
}

int main(){
    int oct;
    cout<<"Enter Octal: "; cin>>oct;
    int dec=octToDec(oct);
    cout<<"Hexadecimal: "; decToHex(dec); cout<<endl;
    return 0;
}
