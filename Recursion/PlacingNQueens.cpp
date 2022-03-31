# include <iostream>
# include <vector>
using namespace std;

  bool isSafe(bool board[10][10], int row, int col, int n) {
        // check vertical row
        for (int i = 0; i < row; i++) {
            if (board[i][col]) {
                return false;
            }
        }

        // diagonal left
        int maxLeft = min(row, col);
        for (int i = 1; i <= maxLeft; i++) {
            if(board[row-i][col-i]) {
                return false;
            }
        }

        // diagonal right
        int maxRight = min(row, n- col - 1);
        for (int i = 1; i <= maxRight; i++) {
            if(board[row-i][col+i]) {
                return false;
            }
        }

        return true;
    }

     void display(bool board[10][10], int n) {

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]){
                cout<<"Q ";
            }
            else{
                cout<<"X ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

   int queens(bool board[10][10], int row, int n) {
        if (row == n) {
            display(board,n);
            cout<<endl;
            return 1;
        }

        int count = 0;

        // placing the queen and checking for every row and col
        for (int col = 0; col <n; col++) {
            // place the queen if it is safe
            if(isSafe(board, row, col,n)) {
                board[row][col] = true;
                count += queens(board, row + 1,n);
                board[row][col] = false;
            }
        }

        return count;
    }

   
int main(){
    bool board[10][10]={false};
    int n;
  cout<<"Enter the no of rows : ";
  cin>>n;
cout<<"count "<<queens(board,0,n)<<endl;
  return 0;
}