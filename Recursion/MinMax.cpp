# include <bits/stdc++.h>
using namespace std;
void MinMax(int arr[], int n, int& min, int& max){
    if(n<=0){
        return;
    }
     
    min=min<arr[n-1]?min:arr[n-1];
    max=max>arr[n-1]?max:arr[n-1];

    MinMax(arr,n-1, min, max);
   
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
int min=arr[0];
int max=arr[0];
MinMax(arr,n,min , max);
cout<<"Min and max are "<<min<<" , "<<max;
return 0;
}