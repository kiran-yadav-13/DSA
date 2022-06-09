# include <iostream>
using namespace std;

int binearySearch(int a[], int target, int start, int end){


    while(start<=end){
    // Better way to find mid because in an arrray of large size it might be possible that (start+end) may exceed the integer value range
    int mid=start+(end-start)/2;
    // return if the element at mid is the target element
    if(a[mid]==target){
        return mid;
    }
    // if the element at mid position is less than the target elemnt this means target element is in the (mid+1 , end) part of the array
    // so move start=mid+1
    else if(a[mid]<target){
       start=mid+1;
    }
    // if the element at mid position is greater than the target elemnt this means target element is in the (start , mid-1) part of the array
    // so move end=mid-1
    else{
        end=mid-1;
    }
    }
    // if the element is not found in the array then return -1. Indicating the target element is not in array
    return -1;
}

//ASSUMING THAT THE ARRAY IS OF INFINITE SIZE
int result(int a[], int target){
  // starting from array of size 2 and slowly increasing its size upto last element
   int start=0;
   int end=0;
   // repeatedly increasing the size
   while(target>a[end]){
   // updating the value of start
   int newStart=end+1;
   // end=previous end+size of the box * 2;
   end=end+(end-start+1)*2;
   start=newStart;
    }
    return binearySearch(a, target, start, end);
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
cout<<"Enter target elements of an array : ";
cin>>target;
cout<<"Index of the target element is : ";
cout<<result(a, target);


return 0;
}