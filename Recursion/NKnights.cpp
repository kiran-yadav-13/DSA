# include <iostream>
using namespace std;

 void display(bool board[10][10], int n) {

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]){
                cout<<"K ";
            }
            else{
                cout<<"X ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isValid(bool board[10][10], int row, int col, int n){
      if(row>=0 && row<n && col>=0 && col<n){
         return true;
      }
    return false;
}
 bool isSafe(bool board[10][10], int row, int col, int n){
            if(isValid(board, row-2, col-1, n)){
           if(board[row-2][col-2]){
               return false;
           }
       }
       if (isValid(board, row - 1, col - 2,n)) {
            if (board[row - 1][col - 2]) {
                return false;
            }
        }

        if (isValid(board, row - 2, col + 1,n)) {
            if (board[row - 2][col + 1]) {
                return false;
            }
        }

        if (isValid(board, row - 1, col + 2, n)) {
            if (board[row - 1][col + 2]) {
                return false;
            }
 }
 }
int Knights(bool board[10][10],int row, int col, int knight, int n){
    if(knight==0){
        display(board, n);
        return 1;
    }
    if(row==n && col==n){
        return 0;
    }
    if(col==n){
        Knights(board,row+1,0,knight,n);
        return 0;
    }
    int count=0;
    if(isSafe(board, row, col,n)){
       board[row][col]=true;
      count+= Knights(board,row, col+1, knight-1, n);
       board[row][col]=false;
       
    }
    Knights(board, row, col+1, knight,  n);

    return count;
}
   
int main(){
    bool board[10][10]={false};
    int n,k;
  cout<<"Enter the no of rows : ";
  cin>>n;
  cout<<"Enter the no of rows : ";
  cin>>k;
cout<<"count "<<Knights(board,0,0,k,n)<<endl;
  return 0;
}