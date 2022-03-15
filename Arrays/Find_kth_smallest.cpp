# include <iostream>
# include <vector>
# include <bits/stdc++.h>
using namespace std;
int KSmallest(vector<int> nums, int k){
  sort(nums.begin(), nums.end());
   return nums[k-1];
}
void swap(int* a, int* b){
   int temp=*a;
   *a=*b;
   *b=temp;

}
int partition(vector<int>nums, int l, int r){
    int x=nums[r];
    int i=l;
    for(int j=l; j<= r-1; j++){
        if(nums[j]<=x){
            swap(&nums[i],&nums[j]);
            i++;
        }
    }
    swap(&nums[i], &nums[r]);
    return i;
}
int toFindKsmallest(vector<int>nums, int l, int r, int k){
    if(k>0 && k<=r-l+1){
       int pos=partition(nums, l,r);
       // if index is same as k
       if(pos-l==k-1){
           return nums[pos];
       }
       // if the index of pivot is greater recurrence for left subarray
       if(pos-l>k-1){
        return toFindKsmallest(nums, l, pos-1,k);
       }
       
       // eles recurrence for right subarrray
       return toFindKsmallest(nums,pos+1,r, k-pos+l-1);
    }
    // IF K IS GREATER THAN NO OF ELEMENTS IN THE ARRAY
    return INT16_MAX;
}
int main(){
     vector<int> nums;
     int a,n;
     cout<<"Enter the size of vector : ";
     cin>>n;
     cout<<"Enter the elements : ";
     for(int i=0; i<n ; i++){
         cin>>a;
         nums.push_back(a);
     }
     cout<<"Enter the VALUE of K : ";
     cin>>a;
    cout<<"smallest "<<a<<" : "<<toFindKsmallest(nums, 0, n-1, a);
    return 0;
 }