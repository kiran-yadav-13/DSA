# include <iostream>
# include <math.h>
using namespace std;
// Smallest element in the array that is graeter than or equal to target
// for ex [2,3,5,9,14,16,18] if target =14 cieling=14 , if target=15 cieling=16
int Ceiling(int a[], int n, int target){

    int start=0;
    int end=n-1;
    int mid=0;
    while(start<=end){

        mid=start+(end-start)/2;
        if(a[mid]==target){
            return mid;
        }
        else if(a[mid]<target){
            start=mid+1;
        }
        else if(a[mid]>target){
            end=mid-1;
        }
    }
    return start;
}
int main()
{
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
cout<<Ceiling(a,n, target);

return 0;
}