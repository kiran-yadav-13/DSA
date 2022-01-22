# include <iostream>
using namespace std;
// without rEcursion
int BinearySearch(int a[], int n , int target){

    int mid,start=0;
    int end=n-1;
    while(start<end){
        mid=(start+end)/2;
        if(a[mid]==target){
            return mid;
        }
        else if(a[mid]>target){
             end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

}
// with recursion
int BinearySearchR(int a[], int n, int target, int start , int end){

     int mid=(start+end)/2;
     if(start>end){
         return -1;
     }
     if(a[mid]==target){
         return mid;
     }
     else if(a[mid]>target){
        return BinearySearchR(a,n,target,start, mid-1);
     }
     else if(a[mid]<target){
         return BinearySearchR(a,n,target,mid+1,end);
     }
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
    cout<<"Result : "<<BinearySearchR(a,n,target, 0,n-1)<<endl;
    return 0;

}