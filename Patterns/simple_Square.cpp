# include <iostream>
using namespace std;
void pattern1(int n){
    for(int row=1; row<=n; row++){
        for(int col=1; col<=n; col++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
int main()
{
   int n;
   cout<<"Enter the no of rows ";
   cin>>n;
   pattern1(n);
   return 0;
}
