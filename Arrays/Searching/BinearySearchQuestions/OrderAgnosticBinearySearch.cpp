# include <iostream>
# include <math.h>
using namespace std;
// This Search is applied when we don't know whether the array is sortted in ascending or descending order
int OrderAgnosticBinearySearch(int a[], int n, int target){

    int start=0;
    int end=n-1;
    
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        // return if the element at mid is the target element. 
        //Since this statement is going to be common in both descending or ascending soterd array that's why written here
        if(a[mid]==target){
        return mid;
        }                                        //     s     m   e
        // If the array is sorted in descending order  [9,8,7,6,5,4]  
        if(a[mid]<a[mid+1]){
         if(a[mid]<target){
             start=mid+1;
         }
         else{
             end=mid-1;
         }
         //                                             s     m   e
        // If the array is sorted in descending order  [1,2,4,5,6,7]
        else{
            if(a[mid]<target){
                end=mid-1; 
            }
            else{
                start=mid+1;
            }
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
cout<<OrderAgnosticBinearySearch(a,n, target);

return 0;
}