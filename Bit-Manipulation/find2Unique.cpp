# include <iostream>
using namespace std;
// n & ~(n-1) will give the rightmost set bit
void Find2Unique(int a[], int n){
    int xored=0;
    int rightSetBit=0;
    int x=0;
    int y=0;
    // contains xored result of two unique no
    for(int i=0; i<n; i++){
        xored=xored^a[i];
    }
    // to seperate these two no . we divide the whole arrray on the basis of rightmost set bit of xored 

    rightSetBit=xored & ~(xored-1);
    for(int i=0; i<n; i++){
     // and the other part doesnot have this bit set
        if(a[i] & rightSetBit){
            x=x^a[i];
        }
        else{
         // the first part contain the no's whose bit is set at the position in the rightmostsetbit
            y=y^a[i];
        }
    }
// now after the duplicates are cancelled in each part of the array and the left result is the unique element
cout<<"Unique no in the arrays are : "<<x<<" "<<y<<endl;
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
Find2Unique(a,n);
return 0;
}