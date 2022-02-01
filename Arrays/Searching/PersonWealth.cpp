# include <iostream>
using namespace std;
// Ques : You are given an m x n integer grid accounts where accounts[i][j] is the amount of money
//        the ith customer has in the jth bank. Return the wealth that richest customer have
int PersonWealth(int a[10][10],int r , int c){
    int sum=0;
    int maxW=-1;
    for(int person=0; person<r; person++){
        sum=0;
        for(int wealth=0; wealth<c; wealth++){
            sum=sum+a[person][wealth];
        }
      if(sum>maxW){
          maxW=sum;
      }
    }
  return maxW;
}
 int main()
{

int row,col;
cout<<"Enter the no of rows in an array : ";
cin>>row;
cout<<"Enter the no of columns in an array : ";
cin>>col;
int a[10][10];
cout<<"Enter the elements : "<<endl;
for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
        cin>>a[i][j];
    }
}
cout<<"Enter the no of columns in an array : "<<PersonWealth(a,row, col);

return 0;
}
