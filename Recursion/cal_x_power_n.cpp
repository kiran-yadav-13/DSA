# include <iostream>
using namespace std;

int x_power_n(int n, int pow){

    if(pow==0){
        return 1;
    }
    return n*x_power_n(n, pow-1);
}
int main(){
int x,n;
    cout<<"Enter the number : ";
    cin>>x;
    cout<<"Enter the power : ";
    cin>>n;
    cout<<"Result : "<<x_power_n(x,n);
    return 0;
}