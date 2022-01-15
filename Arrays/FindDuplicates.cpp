# include <iostream>
using namespace std;

int  duplicates(int a[], int n){
    int ans=0;
    // xoring all elemets so that array have result of all unique elements together except duplicates one 
    for(int i=0; i<n; i++)
    {
        ans=ans^a[i];
    }
    //since array have elements from 1 to n-1
    // ans have all the unique element now xoring from 1 to n will give the unique

    for(int i=1; i<n; i++){
        ans=ans^i;
    }
    return ans;
}
void printArray( int a[], int n){
    for(int i=0; i<n; i++){
       cout<<a[i]<<"  ";
    }
    cout<<endl;
}
int main(){
    int a[100];
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<duplicates(a,n);
   // printArray(a,n);
    return 0;
}