# include <iostream>
using namespace std;
void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void printArray( int a[], int n){
    for(int i=0; i<n; i++){
       cout<<a[i]<<"  ";
    }
    cout<<endl;
}
void MoveNegative(int arr[], int n){
   int i=0;
   int j=n-1;
  while(i<j){
      if(arr[i]>0 && arr[j]<0){
           swap(&arr[i], &arr[j]);
           i++;
           j--;
      }
      else if(arr[i]<0 && arr[j]<0){
         i++;
      }
      else if(arr[i]>0 && arr[j]>0){
           j--;
      }

   }
      
}
int main(){
 
 int a[100];
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<"Enter the elements  : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    MoveNegative(a,n);
    cout<<"output array after moving negative nums : ";
    printArray(a,n);
  return 0;
}