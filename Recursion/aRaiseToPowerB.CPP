#include <iostream>
using namespace std;
// case 1 : when power is even :- then a^b= a^b/2 *  a^b/2
// case 2 : when power is odd:- then a^b= a * a^b/2 * a^b/2

// b=5 a=2 ans=32
// ->b=5 ans=power(2,2) ans=8   b=5(odd)   return= 2*4*4=32
// ->b=2 ans=power(2,1) ans=2,  b=2(even) return= 2*2=4
//-> b=1 return 2 
int power(int a, int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans=power(a,b/2);
    if(b%2==0){
     return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}
int main(){
    int a, b;
    cout<<"Enter the number ";
    cin>>a;
     cout<<"Enter the power ";
    cin>>b;
    cout<<""<<a<<" raise to the  power "<<b<<" is"<<power(a,b);
    return 0;
}