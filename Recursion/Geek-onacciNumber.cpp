# include <iostream>
using namespace std;

int Geek_onacci(int n, int a, int b, int c){
    if (n==1)
    {
        return a;
    }
    if (n==2)
    {
        return b;
    }
    if (n==3)
    {
        return c;
    }
    return (Geek_onacci(n-1,a,b,c)+Geek_onacci(n-2,a,b,c)+Geek_onacci(n-3,a,b,c));
}
int main(){
    int n,a,b,c;
    cout<<"Enter the number a , b and c: ";
    cin>>a>>b>>c;
    cout<<"Enter the number nth term : ";
    cin>>n;
     cout<<"geek-onacci : "<<Geek_onacci(n,a,b,c);
    return 0;

}