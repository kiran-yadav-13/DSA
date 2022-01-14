# include <iostream>
using namespace std;
int ReverseNum(int n){
      if( n<=0)
        return n;



    int R_num =  R_num*10+n%10;
    cout<<"Reversed number is : "<<R_num<<endl;
    ReverseNum(n/10);

    return R_num;
}
int main()
{
    int n=ReverseNum(5124);
    cout<<n<<endl;

    return 0;
}
