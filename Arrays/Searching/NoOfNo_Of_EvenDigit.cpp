# include <iostream>
# include <math.h>
using namespace std;
int OptimisedDigits(int num){
    if(num<1){
        num=num*-1;
    }
    return (int)(log10(num))+1;
}
// No Of Digits
int digits(int n){
    if(n<1){
        n = n*-1;
    }
    int count=0;
    while(n>0){
        count++;
        n=n/10;
    }
    return count;
}
// To Find the no of digits in a number is even or not
bool even(int num){
    //int NoOfDigits=digits(num);
    int NoOfDigits=OptimisedDigits(num);
    return NoOfDigits%2==0;
}
int CountEvenDigitNo(int a[], int n){
    int count=0;
    if(n==0){
        return -1;
    }
    for(int i=0; i<n; i++ ){
      if(even(a[i])){
          count++;
      }
    }
    return count;
}
int main()
{
int n;
cout<<"Enter the no of elements in an array : ";
cin>>n;
int a[n];
cout<<"Enter the elements : "<<endl;
for(int i=0; i<n; i++){
    cin>>a[i];
}
cout<<"No of digits in a number is even : ";
cout<<CountEvenDigitNo(a,n);

return 0;
}