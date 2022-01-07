# include <iostream>
using namespace std;
// Pattern1 : print the following pattern
//   1
//   1 2
//   1 2 3
//   1 2 3 4
//   1 2 3 4 5
void pattern1(int n){
    for(int row=1; row<=n; row++){
        for(int col=1; col<=row; col++){
           cout<<col<<" ";
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
