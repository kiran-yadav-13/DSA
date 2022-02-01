# include <iostream>
using namespace std;

// Return boolean value
bool LinearSearch(int a[], int n, int target){
     if(n==0){
         return false;
     }
     for(int i=0; i<n; i++){
         if(a[i]==target){
             return true;;
         }
     }
     return false;
 }
// Return the index of a number that is searched
 int LinearSearch(int a[], int n, int target){
     if(n==0){
         return -1;
     }
     for(int i=0; i<n; i++){
         if(a[i]==target){
             return i;;
         }
     }
     return -1;
 }
 int main(){
int n,target;
cout<<"Enter the no of elements in an array : ";
cin>>n;
int a[n];
cout<<"Enter the elements : "<<endl;
for(int i=0; i<n; i++){
    cin>>a[i];
}
cout<<"Enter the target element : ";
cin>>target;
cout<<LinearSearch(a,n,target);

return 0;
}