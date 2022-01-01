# include <iostream>
using namespace std;
void swap(int *p, int *q){
     int temp;
     temp=*p;
     *p=*q;
     *q=temp;

}
void swapxor(int &a, int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}
int main(){
int a,b;
cout<<"Enter the value of a and b ";
cin>>a>>b;
//swap(&a, &b);
 
swapxor(a,b);
cout<<" a: "<<a<<" b: "<<b<<endl;
return 0;
}