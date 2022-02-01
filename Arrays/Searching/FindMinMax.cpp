# include <iostream>
using namespace std;

int FindMin(int a[], int n ){
    int min=a[1];
    if(n==0){
        return -1;
    }
    for(int i=0; i<n; i++){
        if(min>a[i]){
            min=a[i];
        }
    }
   return min;

}
int FindMax(int a[], int n ){
    int max=a[1];    // max=INT_MAX;
    if(n==0){
        return -1;
    }
    for(int i=0; i<n; i++){
        if(max<a[i]){
            max=a[i];
        }
    }

   return max;

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
cout<<"Minimum element in array : ";
cout<<FindMin(a,n);
cout<<endl;
cout<<"Maximum element in array : ";
cout<<FindMax(a,n);
return 0;
}