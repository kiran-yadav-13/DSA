# include <iostream>
using namespace std;
int factorialR(int n){
    if(n==1)
        return 1;


   int fact=n*factorialR(n-1);
   return fact;
}
int factorial(int n){
    int fact=1;
 for(int i=1; i<=n; i++)
 {
     fact=fact*i;
 }
 return fact;
}
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
   cout<<"Factorial : "<<factorial(n);
    return 0;

}
