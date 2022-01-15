# include <iostream>
using namespace std;

void swap(int *a , int* b){
     int *temp=a;
     a=b;
     b=temp;

}
void printArray( int a[], int n){
    for(int i=0; i<n; i++){
       cout<<a[i]<<"  ";
    }
    cout<<endl;
}
void swapAlternate(int a[], int n){
    for(int i=0; i<n-1; i=i+2)
    {
        if(i+1<n-1){
            swap(a[i], a[i+1]);
        }
    }
}
int main()
{
    int a[100];
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    swapAlternate(a,n);
    printArray(a,n);
    return 0;
}