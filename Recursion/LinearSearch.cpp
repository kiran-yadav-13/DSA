# include <iostream>
using namespace std;
// Without Recursion
int LinearSearch(int a[], int n , int target){
    for(int i=0; i<n; i++){
        if(a[i]==target)
        return i;
    }
    return -1;
}
// Returning a bool whwther it is found or not
bool LinearSearchR(int a[], int n ,int target, int index){
    if(index==n){
       return false;
    }
    return (a[index]==target || LinearSearchR(a, n, target, index+1));
}
// Returning the index
int LinearSearchIndex(int a[], int n ,int target, int index){
    if(index==n){
       return -1;
    }
    if(a[index]==target){
        return index;
    }
    return (LinearSearchIndex(a, n, target, index+1));
}
int main(){

   int a[100];
   int n, target;
   cout<<"Enter the no of elements in an array : ";
   cin>>n;
   cout<<"Enter the elements : ";
   for(int i=0; i<n; i++){
       cin>>a[i];
   }
   cout<<"Enter the element you want to search  : ";
   cin>>target;

   cout<<"Result : "<<LinearSearch(a,n,target)<<endl;
//    cout<<"Result Index : "<<LinearSearchIndex(a,n,target,0)<<endl;
   return 0;
}