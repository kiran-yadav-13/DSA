# include <iostream>
using namespace std;
void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void PrintArray(int a[], int n){
     cout<<"Array elements : ";
   for(int i=0; i<n; i++){
       cout<<a[i]<<"  ";
   }
   cout<<endl;
}
void InsertionSort(int arr[], int n, int c){
    if(c==n){
       return;
    }
    
    int key=arr[c];

    int i=c-1;
    cout<<"c  " <<c<<" i "<<i<<endl;
    int* ati=&arr[i];
    cout<<" key "<<key<<endl;
    while(arr[c]<arr[i] && i>=0){
        cout<<" before a[i] : "<<arr[i]<<" a[i+1] "<<arr[i+1]<<" i "<<i<<endl;
    
        arr[i+1]= arr[i];
        i--;
        cout<<" after a[i] : "<<arr[i]<<" a[i+1] "<<arr[i+1]<<" i "<<i<<endl;
    }
    arr[i+1]=key;
    PrintArray(arr,n);
    InsertionSort(arr, n,c+1);
}
int main(){
int a[100];
   int n;
   cout<<"Enter the no of elements in an array : ";
   cin>>n;
   cout<<"Enter the elements : ";
   for(int i=0; i<n; i++){
       cin>>a[i];
   }
   InsertionSort(a, n,1);
   PrintArray(a, n);
   

    return 0;

}