#include <bits/stdc++.h>
using namespace std;

// Recursion through 
//1)parameter passing and 
//2) recursion through divide and conquer

// (q-1) sum of numbers from 1 to n

int sumNaturalNum(int sum , int n){
    if(n<1){
     return sum;
    }
    sum=sum+n;
   return sumNaturalNum(sum,n-1);
}

int sumNaturalNumFunc(int sum,int n){
   if(n<1){
      return 0;
   }
  
    sum=n+sumNaturalNumFunc(sum, n-1);
    // cout<<"n "<<n<<endl;
    // cout<<"sum "<<sum<<endl;
    return sum; 
}

int factorial(int n , int fact){
    if(n==1){
        return 1;
    }
   return fact=n*factorial(n-1,fact);
}

int fctrl(int n, int fact){
    if(n==1){
        return 1;
    }
    fact=n*fctrl(n-1, fact);
    return fact;
}


int main(){

    int n;
    cin>>n;
    cout<<"sum is "<<sumNaturalNum(0,n)<<endl;
    cout<<"sum is "<<sumNaturalNumFunc(0,n)<<endl;
    cout<<"factorial : "<<factorial(n,1)<<endl;
    cout<<"fctrl "<<fctrl(n,1)<<endl;

    return 0;
}