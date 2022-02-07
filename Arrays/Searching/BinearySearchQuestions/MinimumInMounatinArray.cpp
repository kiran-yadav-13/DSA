# include <iostream>
using namespace std;
// Find the minimum index of the target element in the mountain arrray
// Input: array = [1,2,3,4,5,3,1], target = 3
// Output: 2
// Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
// Example 2:

// Input: array = [0,1,2,4,2,1], target = 3
// Output: -1
// Explanation: 3 does not exist in the array, so we return -1
// Apprpoach : -
// Find peak element. Since we know that the array toward left and toward right are sorted in ascending or descending order respectively.
// so we first search in the left part to get the minimum 
int FindPeak(int a[], int n){

    int start=0;
    int end=n;
    while(start<end){
     int mid=start+(end-start)/2;
     if(a[mid]<a[mid+1]){
         start=mid+1;
     }
     else{
         end=mid;
     }
    }
  return start; // or return end
}
int OrderAgnosticBinearySearch(int a[], int n, int target, int start, int end){

    
    
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
int MinimumMountain(int a[], int n, int target){
  int start=0;
  int end=n-1;
  int peak=FindPeak(a,n);
  int FirstTry= OrderAgnosticBinearySearch(a,n, target,start,peak);
  if(FirstTry!=-1){
     return FirstTry;
  }
  OrderAgnosticBinearySearch(a,n, target,peak+1,end);
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
cout<<MinimumMountain(a,n, target);

return 0;
}