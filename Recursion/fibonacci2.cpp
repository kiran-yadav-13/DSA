# include <iostream>
using namespace std;

int fibonacci(int n){

   if(n<=1){
       return n;
   }

  return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
int x,n;
    cout<<"Enter the number : ";
    cin>>n;
    int ans=fibonacci(n);
    cout<<"Result "<<ans<<endl;
    return 0;
}
