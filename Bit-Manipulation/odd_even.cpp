# include <iostream>
using namespace std;
void odd_even(int n){
  
  if((n & 1)==0){
      cout<<n<<" is Even number"<<endl;
  }
  else{
      cout<<n<<" is Odd number"<<endl;
  }
}
int main(){
odd_even(8);
return 0;

}