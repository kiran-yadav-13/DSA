
# include <bits/stdc++.h>
# include <iostream>
# include <vector>
using namespace std;
// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, or false otherwise.
bool uniqueOccurrences(vector<int> arr){
    
       sort(arr.begin(),arr.end()); // sorting vector 
       int start=0; // for pointing unique elemnts of array
       int e=start;  
       vector<int> count;
       int no=0;   // will help in  counting ocurrence of every number in arr
       int k=0;    // will help in maintaining correct index of count vector
       while(start<arr.size()){
         
         if(arr[start]==arr[e] && e<arr.size()){
             e++;  // incrementing e till we find element different from previous one
             no++;
         }
        
         else if(arr[start]!=arr[e]) {
          // count[k]=no;
          count.push_back(no);
          start=e;
          no=0;
          k++;
         }

        
       }
       sort(count.begin(),count.end());
        for(int i=0; i<k-1; i++){
          if(count[i]==count[i+1]){
              return false;
          }
        }
 
    return true;

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
  
  cout<< "result "<<uniqueOccurrences(nums);
    return 0;
 }