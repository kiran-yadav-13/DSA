# include <iostream>
# include <math.h>
using namespace std;
//  Greatest element in the array that is smaller than or equal to target
// for ex [2,3,5,9,14,16,18] if target = 14 floor=14 , if target=15 cieling=16
// Floor of the no that is not presnt in the array is the last element or end element. ex target=20 floor=18 
// floor of the smallest element in the array is -1(end=-1 in this case) ex target=1 floor=-1
int Ceiling(int a[], int n, int target){

    int start=0;
    int end=n-1;
    int mid=0;
    
    
    // invalid condition when (start>end)
    // Simple BinearySearch if the target element present in the array or getting closer to the target
    while(start<=end){

        mid=start+(end-start)/2;
        if(a[mid]==target){
            return mid;
        }
        else if(a[mid]<target){
            start=mid+1;
        }
        else if(a[mid]>target){
            end=mid-1;
        }
    }
    // if not found return the greatest number less than target element
    // if the condition is valid (start   ans    end)
    // invalid (end   ans   start ). So position end representing the position where the graeates element smaller than target presnt
    return end;
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
cout<<Ceiling(a,n, target);

return 0;
}