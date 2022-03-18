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
void move(int a[], int n){
    int left=0;
    int right=n-1;
    // for(int i=0; i<n; i++){

    // }
    while(left<right){

      while(a[left]==0 && left<right)
      {
        left++;  
      }
    // covered all the 1's which are already in place 
    while(a[right]==2 && left<right)
    {
        right--;
    }
    if(a[left]==2 && a[right]==0){
     swap(a[left], a[right]);
     left++;
     right--;
    }
    cout<<left<<endl;
     printArray(a,n);
    }
}
int main(){
 
 int a[100];
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    move(a,n);
    printArray(a,n);
  return 0;
}