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

    while(key<arr[i] && i>=0){        // in this while condition we cannot wirte a[c] instead of c because we are updating values at indexes 
        arr[i+1]= arr[i];
        i--;
        
    }
    arr[i+1]=key;
 
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