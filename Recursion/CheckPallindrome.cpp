# include <iostream>
using namespace std;

int ReverseNum(int n){
    //My BrutForce approach 
    static int sum;
      if( n<=0)
        return sum;
   
    int rem=n%10;
     sum = sum*10+rem;
    ReverseNum(n/10);
}

bool check_Pallindrome(int n){
if(n==ReverseNum(n))
     return true;
 else
    return false;

}
int main(){
   int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"Pallindrome : "<<check_Pallindrome(n);
    return 0;

    
}