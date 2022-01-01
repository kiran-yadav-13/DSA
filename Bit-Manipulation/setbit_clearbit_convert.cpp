# include<iostream>
using namespace std;
int noOfSetBits(int n )
{ 
    int count =0;
    while(n!=0){
       n=n & (n-1);
       count++;
    }
    return count;
   
}
// set ith  bit of the number
int setBit(int n, int pos)
{
    
    n=(n | (1<<pos));
    return n;
}
// find ith bit of number
int getbit(int n, int pos)
{
    n=(n && (n<<pos));
    return n;
}
// clear the  ith bit 
int clearbit(int n, int pos)
{  int mask=~(1<<pos);
   n=(n & mask);
   return n;
}
// udate bit with the desired value bit(0,1)
int updatebit(int n, int pos, int value)
{
  int mask=(n & ~(1<<pos));
  n = ( mask | (value<<pos));
  return n;
}

// toggle bit (change 1->0, 0->1)
int togglebit(int n , int pos)
{
    return (n xor (1<<pos));
}
int main(){
   
   cout<<"Set bit : "<<setBit(1,1)<<endl;
   cout<<"clear bit: "<<clearbit(7,0)<<endl;
   cout<<"Get bit : "<<getbit(7,1)<<endl;
   cout<<"toggle bit: "<<togglebit(7,2)<<endl;
   cout<<"update bit : "<<updatebit(3,1,0)<<endl;;
   cout<<"No of set bits "<<noOfSetBits(7)<<endl;
    
   return 0;

}