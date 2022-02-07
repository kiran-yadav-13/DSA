// Ques :  write an algorithm to divide an array into m conitinous subarrays so that the largest sum of these subarrays are miniumum
// Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
// Write an algorithm to minimize the largest sum among these m subarrays
// Example 1:
// Input: nums = [7,2,5,10,8], m = 2
// Output: 18
// Explanation:
// There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8],
// where the largest sum among the two subarrays is only 18.

// Approcah:-
// Max sum of subarray when the array is divided into 0 parts (sum of whole array).
// Minimum sum of subarray is when  the array(of length n) is divided into n parts.(largest sum is the maximum element in the array)
// ABOVE TWO CASSES IS OF REGARDLESS OF SIZE GIVEN
// so the range of largest minimum sum is (max element of array to sum of all element of array). (Hint : This suggest to apply bineary search)
// try to see if u can divide the the array to give the max the mid of the given range 
// if the no of pieces u divided is less than the given no of  (this means that the given max sum(current middle)) is larger so reduce the sum(mid)
// similarly if the no of pieces is greater than the given no of pieces (this means that the given max sum(current middle)) is smaller so increase the sum(mid)
# include <iostream>
# include <math.h>
using namespace std;
int SplitArray(int a[], int n, int m){
    int start=0;
    int end=0;
    for(int i=0; i<n; i++){
        start=max(start, a[i]);
        end+=a[i];
    }
    while(start<end){
        // try middle for as potential ans
        int mid=start+(end-start)/2;
       // calcualting how many pieces you can divide it with the given max 
       int sum=0;
       int pieces=1;
       for(int i=0; i<n; i++){
         if(sum+a[i]>mid){
             // you cannot add this in this subarray so make the new subarray
             // you can add this in the new subarray, then sum=a[i]
             sum=a[i];
             pieces++;
         }
         else{
             sum+=a[i];
         }
       }
       if(pieces>m){
           start=mid+1;
       }else{
           end=mid;
       }

    }

  return end;// or start==end
}
int main()
{
int n,m_subarray;
cout<<"Enter the no of elements in an array : ";
cin>>n;
int a[n];
cout<<"Enter the elements : "<<endl;
for(int i=0; i<n; i++){
    cin>>a[i];
}
cout<<"Enter the max no of subarrays : ";
cin>>m_subarray;
cout<<"Index of the target element is : ";
cout<<SplitArray(a,n, m_subarray);

return 0;
}