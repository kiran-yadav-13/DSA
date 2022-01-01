# include <iostream>
using namespace std;
// N & N-1 ALWAYS SETS LSB TO 0
int noOfBitsFlipped(int a, int b){
    int count =0;
   // Give no of different bits
    int n= a^b;
    // count no of different bits
    while(n!=0)
    {
        n=n & (n-1);
        count++;
    }
    return count;
}
int main()
{
    cout<<"No of bits should be flipped : "<<noOfBitsFlipped(5,7)<<endl;
    return 0;
}