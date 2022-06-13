# include <iostream>
using namespace std;


// question

// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

// Return the kth positive integer that is missing from this array.

 

// Example 1:

// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
// Example 2:

// Input: arr = [1,2,3,4], k = 2
// Output: 6
// Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.



 int findKthPositive(vector<int>& arr, int k) {
        // in this question at index i the number should be present is i+1
        // so for checking how many no are missing number present-number should be prsent
        // =>a[index(mid)]-index+1(mid+1)   (no ofr elements missing)
        // for arr = [1,2,3,4], k = 2 since there is no no is missing in the array
        // missing part is out of the array =>end+k-missing no in array
        // if wants to find out missing when arr size=2 arr=[2,3] hence end=-1 return k itself(1)(msising no)

        int start=0;
        int end=arr.size()-1;
      
        while(start<=end){
             int mid=start+(end-start)/2;
            if((arr[mid]-(mid+1))>=k){
                end=mid-1;
            }
            else{
                   start=mid+1;
            }
        }
        if(end==-1){
            return k;
            
        }
        return arr[end]+k-(arr[end]-(end+1));
    }
int main(){

    return 0;

}