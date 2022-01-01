//  QUES - find a unique element in the arrray if every element repeat twice
# include <iostream>
using namespace std;

void sort(int a[], int n)
{   int key=0;
    for(int i=1; i<n; i++){
        key=a[i];
      int j=i-1;
       while(j>=0 && a[j]>key)
       {
           a[j+1]=a[j];
           j=j-1;
       }
       a[j+1]=key;
    }
}
int findUnique1st(int a[], int n)
{
    sort(a,n);
    for(int i=0; i<n; i=i+2)
    {
        if(i==n-1){
            return a[n-1];
        }
        if(a[i] != a[i+1]){
            return a[i];
        }

    }
    return -1;
}
int findUnique(int a[], int n){
    int res=0;
    for(int i=0; i<n; i++)
    {
        res=res^a[i];
        // xor -ing cancel out the duplicates 

    }
    return res;
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
sort(a,n);
for(int i=0; i<n; i++){
    cout<<a[i]<<" ";
}
 cout<<"Unique element of array is : "<<findUnique(a, n);
// cout<<"Unique element of array is : "<<findUnique1st(a, n);
 return 0;
}