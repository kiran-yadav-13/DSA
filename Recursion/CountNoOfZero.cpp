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
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
   cout<<"No of Zeros : "<<countZero(n,0);
    return 0;
}
