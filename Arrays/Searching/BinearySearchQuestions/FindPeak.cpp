//Mountain/Biotonic array : - the array first increasing then decreasing ex- [1,2,3,7,6,5,4]
// Approach:-
// Array sortted- Bineary Search , but target element is unknown
// if a[mid]<a[mid+1] means in the smaller part of the array since we want to find the peak element [may be mid+1 is the peak but check in right side of array whether another peak exsist or not] ignore start to mid part
// if a[mid]>a[mid+1] means in the grater/decreasing part of the array since we want to find the peak element [may be mid is the peak but check in left side of array whether another peak exsist or not] ignore end to mid-1 part
//in the end start==end pointing to the largest number because of the 2 checks in the bineary search
// start and end try always to find max element in the 2 checks of while loop
// more elaboration: at every point of time for start and end, they have the best possible answer till that time
// and if we are saying that only one item is remaining, hence cuz of above line that is the best possible an
# include <iostream>
using namespace std;

int FindPeak(int a[], int n){

    int start=0;
    int end=n;
    while(start<end){
     int mid=start+(end-start)/2;
     if(a[mid]<a[mid+1]){
         start=mid+1;
     }
     else{
         end=mid;
     }
    }
  return start; // or return end
}
int main()
{
int n;
cout<<"Enter the no of elements in an array : ";
cin>>n;
int a[n];
cout<<"Enter the elements : "<<endl;
for(int i=0; i<n; i++){
    cin>>a[i];
}

cout<<"Index of Peak element is : ";
cout<<FindPeak(a,n);

return 0;
}

