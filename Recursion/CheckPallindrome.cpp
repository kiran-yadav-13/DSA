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

bool Pallindrome(string& name, int start, int end){
  if(start>end){
      return true;
  }
   if(name[start]!=name[end]){
   return false;
   }
   Pallindrome(name,start+1,end-1);
   return true;
}
int main(){
   string n;
    cout<<"Enter the number : ";
    cin>>n;

    cout<<"Pallindrome : "<<Pallindrome(n,0,n.size()-1);
    return 0;

    
}