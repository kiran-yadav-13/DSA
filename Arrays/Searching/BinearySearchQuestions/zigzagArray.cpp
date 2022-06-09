# include <iostream>
using namespace std;

int findpeak(int a[], int n){
    int start=0;
    int end=n-1;
    while(start<=end){

        mid=start+(end-start)/2;

        if(a[mid]<a[mid+1]){
           start=mid+1;
        }
        else{
            end=mid;  //mid can be the peak element
        }
    }
    return start;
}

int search(int a[], int n, int target){
  int peak=findpeak(a, n);
  int start=0;
  int end=n-1;
   if(target<a[peak]){
         end=peak;
     }
     else{
         start=peak;
     }
  while(start<=end){
     int mid=start+(end-start)/2;
      if(a[mid]==target){
          return mid;
      }
      else if(a[mid]<target){
          start=mid+1;
      }
      else{
          end=mid-1;
      }
  }
  return -1;
}


int main(){
int n, target;
cout<<"Enter the no of elements in an array : ";
cin>>n;
int a[n];
cout<<"Enter the elements : "<<endl;
for(int i=0; i<n; i++){
    cin>>a[i];
}
cout<<"Enter the no of elements in an array : ";
cin>>target;
cout<<"leftmost Index of element is : ";
cout<<search(a,n, target);

return 0;
}