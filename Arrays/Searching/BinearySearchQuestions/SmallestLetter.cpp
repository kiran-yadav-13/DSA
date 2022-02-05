// Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.
// Note that the letters wrap around.
// For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.
// Example 1:
// Input: letters = ["c","f","j"], target = "a"
// Output: "c"
# include <iostream>
# include <string>
using namespace std;

char SmmallestLetter(char a[], int n, char target){
    int start=0;
    int end=n-1;
    int mid=0;
//    if(target>a[n-1]){
//        return a[0];
//    }
    while(start<=end){
      mid=start+(end-start)/2;
      if(a[mid]==target){
          return a[mid];
      }
      if(a[mid]<target){
          start=mid+1;
      }
      else if(a[mid]>target){
          end=mid-1;
      }
    }
    return a[start%n];
}
int main()
{
int n;
char target;
cout<<"Enter the no of elements in an array : ";
cin>>n;
char a[n];
cout<<"Enter the elements : "<<endl;
for(int i=0; i<n; i++){
    cin>>a[i];
}
cout<<"Enter target elements of an array : ";
cin>>target;
cout<<"Index of the target element is : ";
cout<<SmmallestLetter(a,n, target);

return 0;
}


