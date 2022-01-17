# include <iostream>
# include <cstdlib>
# include <math.h>
using namespace std;


// we have to make helper function because if we have to pass the value to some recursive function then we have to pass it by argument or by returning it
int helper(int n , int digits){

    if(n%10==n){
        return n;
    }
    int rem=n%10;
    return (int) rem*pow(10,digits-1)+helper(n/10, digits-1);
}
int Reverse(int n){
     // fORMULA TO FIND NO OF DIGITS
     int digits = (int)(log10(n))+1;
     return helper(n, digits);
}

int ReverseNum(int n){
    //My BrutForce approach 
    static int sum;
      if( n<=0)
        return sum;
   
    int rem=n%10;
     sum = sum*10+rem;
    ReverseNum(n/10);
}
int main()
{
    int n=ReverseNum(5124 );
    //int n=Reverse(5124 );
    cout<<n<<endl;

    return 0;
}
