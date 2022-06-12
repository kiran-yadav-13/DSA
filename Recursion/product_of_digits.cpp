# include <iostream>
using namespace std;


int product(int n){
 if(n%10==n){
    return n;
 }

 return ((n%10)*product(n/10));
}
int main(){
int n;
cout<<"Enter the no of elements in an array : ";
cin>>n;
cout<<"Product  "<<product(n);
return 0;
}