# include <iostream>
# include <cstdlib>
using namespace std;
// Question : Return all the Duplicates present in the array if the elements in the array is 1 to  n-1;
// abs return all the positive result;
// aproach :
// since (-(-))=+ 
// Picking up a element and putting the negative of that element if the picked up element is +ve
// and if the element is 0 then we assign the 'n' because the element in array is (1 to n-1)

void duplicates(int a[], int n){
       int dup[n]={0};
       int j=0;
       for(int i=0; i<n; i++){
           int e=a[abs(a[i])];
           //checking if element is +ve
           if(e>0){
               a[abs(a[i])] = - a[abs(a[i])];
           }
           // checking if the element is 0
           else if(e==0){
               a[abs(a[i])] = - n;
           }
           // since we have assigned the negative of that element. if there is a duplicacy of a elemnt then
           else{
               if(abs(a[i])==n){
                   dup[j]=0;
               }
               else{
                   dup[j] = abs(a[i]);
               }
               j++;
           }
       }
       cout<<"Duplicate element in an arrray : ";
       for(int i=0; i<j; i++){
       cout<<dup[i]<<"  ";
    }
    cout<<endl;
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
duplicates(a,n);
return 0;
}

