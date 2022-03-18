// Sum triangle from array
// Difficulty Level : Easy
// Last Updated : 10 Jun, 2021
// Given an array of integers, print a sum triangle from it such that the first level has all array elements. From then, at each level number of elements is one less than the previous level and elements at the level is be the Sum of consecutive two elements in the previous level. 
// Example :
 

// Input : A = {1, 2, 3, 4, 5}
// Output : [48]
//          [20, 28] 
//          [8, 12, 16] 
//          [3, 5, 7, 9] 
//          [1, 2, 3, 4, 5] 

// Explanation :
// Here,   [48]
//         [20, 28] -->(20 + 28 = 48)
//         [8, 12, 16] -->(8 + 12 = 20, 12 + 16 = 28)
//         [3, 5, 7, 9] -->(3 + 5 = 8, 5 + 7 = 12, 7 + 9 = 16)
//         [1, 2, 3, 4, 5] -->(1 + 2 = 3, 2 + 3 = 5, 3 + 4 = 7, 4 + 5
// DRY RUN
//arr=[1,2,3,4]
   // suma([1,2,3,4],4)  temp=[3,5,7]  cout <<1,2,3,4
   // sum([3,5,7],3) temp=[8,7] cout <<3,5,7
   // sum([8,7],2) temp=[15]  cout<< 8 ,7
   // sum([15],1) temp=0  cout<< 15
    // sum(0,0) -> return 
# include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n ){
    for(int i=0; i<n; i++){
      cout<<arr[i]<<" ";
    }
   cout<<endl;
}
void SumTriangle(int arr[], int n){
    if(n<1){
        return ;

    }
   int temp[n-1];
   for(int i=0; i<n; i++){
       int x=arr[i]+arr[i+1];
       temp[i]=x;
   }
   SumTriangle(temp, n-1);
   printArray(arr, n);


}
int main(){
int n;

cout<<"Enter no of element : ";
cin>>n;
int arr[n];
cout<<"Enter the elements : ";
for(int i=0; i<n; i++){
    cin>>arr[i];
}
SumTriangle(arr,n);
return 0;
}
© 2022 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
