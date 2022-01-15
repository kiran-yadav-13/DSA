# include <iostream>
using namespace std;

// Question : all the elements in the given array is either 0 or 1 .
// Move all the 0's to left and all 1's to right side of array

// aproach 1: count no of 1's and 0's and assign that no of 0 first in an array then that no of 1's
// aproach 2: apply sortting
// aproach 3: two pointer approach
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
    while(left<right){
    // covered all the zero which is already in place 
    while(a[left]==0 && left<right)
    {
        left++;  
    }
    // covered all the 1's which are already in place 
    while(a[right]==1 && left<right)
    {
        right--;
    }
    // now if we reach at this point it means that the element at left and right position are in reverse order
    if(a[left]>a[right] ){
        swap(a[left], a[right]);

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
    move(a,n);
    printArray(a,n);
    return 0;
}