# include <iostream>
using namespace std;
bool helper(int n, int i){


    if(n==i ){
        return true;
    }
   if(n%i==0){
        return false;
    }
        helper(n, i+1);
}
bool check_prime(int n){
    return helper( n, 2);
}
int main(){
int x,n;
    cout<<"Enter the number : ";
    cin>>n;
    bool ans=check_prime(n);
    cout<<"Result "<<ans<<endl;
    return 0;
}
