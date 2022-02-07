# include <iostream>
using namespace std;
int FindPeak(int a[], int n){

    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if( mid<end && a[mid]>a[mid+1]){
            return mid;
        }
        if(mid>start && a[mid]<a[mid-1]){
            return mid-1;
        }
        if(a[start]>=a[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}
// My approach
int countRotation(int a[], int n){
    int pivot=FindPeak(a,n);

    if(pivot!=-1){
        return ((n-1)-pivot);
    }
    return 0;
}
// for the array having duplicates
int findPivotWithDuplicates(int a[], int n){

    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        // 4 casses over here
        if(mid<end && a[mid]>a[mid+1] ){
         return mid;
        }
        if(mid<start && a[mid-1]>a[mid]){
         return mid-1;
        }
        // if elements at begining, end and middle are equal then just skip the duplicates
        if(a[mid]==a[start] && a[mid]==a[end]){
            // skip the duplicates
            // Note : what if these element at start and were the pivot ??
            // check if the start is pivot
            if(start<end && a[start]>a[start+1]){
                return start;
            }
            start++;
            if(end>start && a[end]<a[end-1]){
                return end-1;
            }
            end--;

        }
        // left side is sorted so pivot should be inb the right
        else if(a[start]<a[mid] || (a[start]==a[mid] && a[mid]>a[end])){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return -1;
}
// with every shift pivot shifting one position from the orignal array. and since index starts from 0 that's why pivot+1
int Count(int a[], int n){
    //int pivot=FindPeak(a,n);
    int pivot=findPivotWithDuplicates(a,n);
    return pivot+1;
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

cout<<"No of times the array is rotated : ";
cout<<Count(a,n);

return 0;
}