# include <iostream>
using namespace std;

// Question : find all the combination of all those elements whose sum equals to the given number

void PairSum(int a[], int n, int sum){

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((a[i]+a[j])==sum){
                cout<<a[i]<<" , "<<a[j]<<endl;
            }
        }
    }
}
int main()
{
    int a[100];
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int sum=0;
    cout<<"Enter the sum u want : ";
    cin>>sum;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    PairSum(a,n, sum);
    
    return 0;
}