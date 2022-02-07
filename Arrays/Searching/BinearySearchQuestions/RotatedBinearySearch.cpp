# include <iostream>
using namespace std;
// BINEARY SEARCH IN ROTATED ARRAY
// Approach :-
// What is Rotated array ?
// orignal array- [1,2,3,4,5,6,7,8]. after 1st rotation:-[2,3,4,5,6,7,8,1] , 2nd rotation:-[3,4,5,6,7,8,1,2]
// Step-1 : find the peak element in the array.
// Step-2 : Search in the first half (0, pivot) 
// Step-3 : Search in the second half (pivot, end)
// Qusetion : How to find pivot ??
// Pivot: from where your next array is ascending 
// case 1 and 2 is applicable when peak is near the mid
// case-1 element found i.e a[mid]>a[mid+1] (return ans=mid+1) 8 is mid. [3,4,5,6,7,8,1,2] only 8,7 is in the descending order in the array
// case 2 element found i.e a[mid]<a[mid-1] (return ans=mid-1) 1 is mid here
// case 3 start element>=mid elemnt then (end=mid-1). this means that elements after mid is smaller than the left part so ignore them. beacuse we want to find the greatest element
// case 4 start elemnt < mid elemnt then (start=mid+1).this means that elements before mid is smaller than the right part so ignore them. beacuse we want to find the greatest element
int FindPivot(int a[], int n){

   int start=0;
   int end=n-1;

   while(start<=end){
     int mid=start+(end-start)/2;
     if(mid<end && a[mid]>a[mid+1] ){
         return mid;
     }
     if(mid>start && a[mid-1]>a[mid]){
         return mid-1;
     }
     if( a[mid]<=a[start]){
         end=mid-1;
     }
     else{
         start=mid+1;
     }
   }
   return -1;
}
int BinearySearch(int a[], int n, int target, int start, int end){

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
int findPivotWithDuplicates(int a[], int n){

    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        // 4 casses over here
        if(mid<end && a[mid]>a[mid+1] ){
         return mid;
        }
        if(mid<start && a[mid-1]>a[mid]){
         return mid-1;
        }
        // if elements at begining, end and middle are equal then just skip the duplicates
        if(a[mid]==a[start] && a[mid]==a[end]){
            // skip the duplicates
            // Note : what if these element at start and were the pivot ??
            // check if the start is pivot
            if(start<end && a[start]>a[start+1]){
                return start;
            }
            start++;
            if(end>start && a[end]<a[end-1]){
                return end-1;
            }
            end--;

        }
        // left side is sorted so pivot should be inb the right
        else if(a[start]<a[mid] || (a[start]==a[mid] && a[mid]>a[end])){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return -1;
}
int Search(int a[], int n, int target){

    int Pivot=FindPivot(a, n);

    // int Pivot=findPivotWithDuplicates(a, n);
    cout<<"Pivot "<<Pivot<<endl;
    // if pivot not found this means array is not rotated
    if(Pivot==-1){
        // Just do simple bineary search
       return BinearySearch(a,n,target,0,n-1);
    }
    // pivot is found, you have 2 ascending sorted arrays
    if(a[Pivot]==target){
        return Pivot;
    }
    if(target>=a[0]){
        return BinearySearch(a, n, target, 0, Pivot);
    }
    return BinearySearch(a, n, target, Pivot+1, n-1);
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
cout<<Search(a,n, target);

return 0;
}
