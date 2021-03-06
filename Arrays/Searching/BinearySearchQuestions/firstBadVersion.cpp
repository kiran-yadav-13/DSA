# include <iostream>
using namespace std;

// question :
// You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

// Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

// You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.


// sample output
// Input: n = 5, bad = 4
// Output: 4
// Explanation:
// call isBadVersion(3) -> false
// call isBadVersion(5) -> true
// call isBadVersion(4) -> true
// Then 4 is the first bad version.

//NOTE:
// UNLIKE DOING start=mid AND end=mid in if and else blocks you need to do mid+1, mid-1 and store result to return in end so thet no timelimit exceed

class Solution {
public:
    int firstBadVersion(int n) {
        int start =1;
        int end=n;
        int result=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isBadVersion(mid)){
                   result=mid;
                end=mid-1;
             
            }
            else{
                start=mid+1;
            }
        }
        return result;
    }
};