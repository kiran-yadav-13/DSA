# include <iostream>
using namespace std;
int INT_SIZE=8 * sizeof(unsigned int);
int count[32];

// QUES unique element in an array where all elements occur k times except one
// we count the no of sets bits for that given position for all numbers in an array
// if the count of that position is not the multiple of k it will contribute in the  req result
int functio(int a[], int n, int k){

  for(int i=0; i<INT_SIZE;  i++){
      for(int j=0; j<n; j++){
          if((a[j] & (1<<i))!=0){
              count[i]+=1;
          }
      }
  }
  unsigned  res=0;
  for(int i=0; i<INT_SIZE; i++)
  {
      res+=(count[i]%k) * (1<<i);//(1<<i) will generate 2's power
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
cout<<"Unique no :"<<functio(a,n,3);
    return 0;
}