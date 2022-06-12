# include <iostream>
using namespace std;

bool sortting(int a[], int n){
    if((a[n-1]<a[n-2]) ||(a[n-1]<a[n-2] && n==2)) {
        return false;
    }

    sortting(a,n-1);
  return true;  
}
// 2nd approach

bool sorted(int a[], int n , int index){
    if(index==n-1){
        return true;
    }

    return ((a[index]<a[index+1]) && sorted(a,n,index+1));
}
int  main(){
int n;
cout<<"Enter the no of elements in an array : ";
cin>>n;
int a[n];
cout<<"Enter the elements : "<<endl;
for(int i=0; i<n; i++){
    cin>>a[i];
}
cout<<"Sortting "<<sortting(a,n);
return 0;

}