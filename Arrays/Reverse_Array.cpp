# include <iostream>
using namespace std;

// Two pointers approach
void ReverseArray(int a[], int n){
    int i=0;
    int j=n-1;
    int temp=0;
    while(i<j){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }
}
void printArray( int a[], int n){
    for(int i=0; i<n; i++){
       cout<<a[i]<<"  ";
    }
    cout<<endl;
}
int main()
{   int a[100];
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ReverseArray(a,n);
    printArray(a,n);
    return 0;
}