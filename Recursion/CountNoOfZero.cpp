# include <iostream>
using namespace std;
// Ques : Find the no of zeros in a number
 int countZero(int n, int c){
     if(n<=0)
     return c;

     int digit=n%10;
     if(digit==0){
         countZero(n/10, c+1);
     }
     else
     {
         countZero(n/10, c);
     }
 }
int count1(int n , int c){

     if(n%10==n)
     return c;

    if((n%10)==0){
        return count1(n/10, c+1);
    }
    else{
         return count1(n/10, c);
    }
}
int countZero1(int n){

    return count1(n,0);
}
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
   cout<<"No of Zeros : "<<countZero1(n);
    return 0;
}
