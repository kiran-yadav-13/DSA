# include <iostream>
using namespace std;
int powerof2(int pow){
    return (1<<pow);
}
// power of 2 only have 1 bit set
// AND with n-1 gives 0 ex- 4 & 3( 100 & 11)
bool ispower2(int n){
    if((n & (n-1))==0){
        return true;
    }
    else
    return false;
}
int main(){
    int n ,i;
    cout<<"Enter the power of 2 you want : ";
    cin>>i;
    cout<<"2 power "<<i<<" is : "<<powerof2(i)<<endl;
    cout<<"Enter a number to check : ";
    cin>>n;
    if(ispower2(n))
    {
        cout<<"Yes! it is a power of 2"<<endl;
    }
    else
    {
        cout<<"No! it is not a power of 2"<<endl;
    }

    return 0;
}