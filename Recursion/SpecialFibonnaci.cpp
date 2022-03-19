# include <iostream>
using namespace std;
int SpecialFibonacci(int n, int a, int b){
    if (n==0)
    {
        return a;
    }
     if (n==1)
    {
        return b;
    }
    return SpecialFibonacci(n-1,a,b)^SpecialFibonacci(n-2,a,b);
}
// n=0 a , n=1  b , n=2 a^b, n=3 (a^b)^b, n=4 ((a^b)^b)^(a^b) b
// hence when n%3==0 ans=a   , n%3==1 ans=b  , n%3==2 ans= a^b
int SpecialFibonacci2(int n , int a, int b){
    // time complexity O(1)
    int ans=0;
    if(n%3==0){
     ans=a;
    }
    else if(n%3==1){
        ans=b;
    }
    else{
        ans=a^b;
        return ans;
    }
}
int main(){
    int n,a,b;
    cout<<"Enter the number : ";
    cin>>n;
      cout<<"Enter the number a and b : ";
    cin>>a>>b;
     cout<<"Factorial : "<<SpecialFibonacci(n,a,b);
    return 0;

}
