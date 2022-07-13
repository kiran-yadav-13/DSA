//Problem statement : 
// Ninja is a building a entrepreneur. he likes to make money from money. he is given 1rs initially. he dreams of making N rs by 1rs via trading
// there are two types of trades:
// you make a profit of rs 1 (total amount increase by 1)
// you make a 100% profit (total amount is doubled)
// your task is to tell minimum number of days to make rs N
// ex- N=5
// Answer=3
# include <iostream>
using namespace std;
int solution(int n){

    int days=0;
    while(n>=1){
      if(n%2==0){
          n=n/2;
      }
      else{
          n=n-1;
      }
      days++;
    }
    return days;

}
int main()
{
    int n;
    cin>>n;
    cout<<solution(n)<<endl;

    return 0;
}
