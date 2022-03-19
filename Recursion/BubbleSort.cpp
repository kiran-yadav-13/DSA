# include <iostream>
using namespace std;
void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void Bubble_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
               swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
void BubbleSort(int arr[], int n){
    // Base case
    if(n==1){
        return;
    }
    for(int i=0; i<n-1; i++){
          if(arr[i]>arr[i+1]){
               swap(&arr[i], &arr[i+1]);
            }
    }
    Bubble_sort(arr, n-1);
}
void PrintArray(int a[], int n){
     cout<<"Array elements : ";
   for(int i=0; i<n; i++){
       cout<<a[i]<<"  ";
   }
   cout<<endl;
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
   BubbleSort(a, n);
   PrintArray(a, n);
   

    return 0;

}