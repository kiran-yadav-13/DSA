# include <iostream>
using namespace std;
int sumElement(int arr[],  int n){

    if(n==0){
        return 0;
    }
    int sum=sumElement(arr,n-1)+arr[n-1];
    return sum;
}
int main(){
int n;
cout<<"Enter the no of elements in an array : ";
cin>>n;
int a[n];
cout<<"Enter the elements : "<<endl;
for(int i=0; i<n; i++){
    cin>>a[i];
}
cout<<sumElement(a,n);

return 0;
}