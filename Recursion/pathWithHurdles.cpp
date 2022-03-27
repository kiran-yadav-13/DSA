# include <iostream>
# include <vector>
using namespace std;
void Printpath(bool m[20][20],string p,int row, int col, int& r, int& c){
    // &&  because now we have to print all the moves
     if(row==r-1 && col==c-1){
         cout<<p<<endl;
         return;
     }
     if(!m[row][col]){
         return;
     }
     if(row<r-1){
        Printpath(m,p+'D',row+1,col,r,c);
     }
    if(col<c-1){
        Printpath(m,p+'R',row,col+1,r,c);
     }

}
int main(){
int row, col;

vector<string> ans;
cout<<"Enter the no of rows : ";
cin>>row;
cout<<"Enter the no of columns : ";
cin>>col;
bool m[20][20];
cout<<"Enter the boolean matrix (0/1) : ";
for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
        cin>>m[i][j];
    }
}
cout<<"PATH"<<endl;
Printpath(m,"",0,0,row,col);
}