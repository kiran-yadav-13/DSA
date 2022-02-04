# include <iostream>
# include <math.h>
using namespace std;
// Applicable for array of sorted element
int BinearySearch(int a[], int n, int target){

    int start=0;
    // index no of the last element
    int end=n-1;
    while(start<=end){
    // Better way to find mid because in an arrray of large size it might be possible that (start+end) may exceed the integer value range
    int mid=start+(end-start)/2;
    // return if the element at mid is the target element
    if(a[mid]==target){
        return mid;
    }
    // if the element at mid position is less than the target elemnt this means target element is in the (mid+1 , end) part of the array
    // so move start=mid+1
    else if(a[mid]<target){
       start=mid+1;
    }
    // if the element at mid position is greater than the target elemnt this means target element is in the (start , mid-1) part of the array
    // so move end=mid-1
    else{
        end=mid-1;
    }
    }
    // if the element is not found in the array then return -1. Indicating the target element is not in array
    return -1;
}

int main()
{
int n,target;
cout<<"Enter the no of elements in an array : ";
cin>>n;
int a[n];
cout<<"Enter the elements : "<<endl;
for(int i=0; i<n; i++){
    cin>>a[i];
}
cout<<"Enter target elements of an array : ";
cin>>target;
cout<<"Index of the target element is : ";
cout<<BinearySearch(a,n, target);

return 0;
}
