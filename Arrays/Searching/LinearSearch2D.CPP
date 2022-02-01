# include <iostream>
# include <vector>
using namespace std;
// Return the index of a number that is searched
 vector<int> LinearSearch(int a[][10], int row,int col, int target){
     vector <int>dim;
     if(row==0){
         return dim;
     }
     for(int i=0; i<row; i++){
       for(int j=0; j<col; j++) 
         if(a[i][j]==target){
             dim.push_back(i);
             dim.push_back(j);
             return dim;
         }
     }
     return dim;
 }
int main(){
 vector<int> dim;
int row,col,target;
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
cout<<"Enter the target element : ";
cin>>target;
dim=LinearSearch(a,row,col,target);
for(int i:dim){
    cout<<i<<" ";
}
return 0;
}