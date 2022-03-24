# include <iostream>
using namespace std;
// Take a pointer and compare the current from the next one if is sorted then move and if not the break the loop
bool Sortted(int arr[], int n , int index){
    if(index==n-1){
        return true;
    }
    return arr[index]<arr[index+1] && Sortted(arr, n, index+1);
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
    cout<<"Result : "<<Sortted(a, n,0);
    return 0;
}