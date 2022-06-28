# include <iostream>
# include <limits>
# include <stack>
# include <vector>
# include <string>

using namespace std;

// Brute Force
int FindCelebrity(vector<vector<int>>&  M, int n){
    for(int i=0; i<n; i++){
        int row=i;
        int col=0;
        int zeros=0;
        // checking row
        while(col<n){
        if(M[row][col]==0){
         zeros++;
        }
        col++;
        }
        row=0;
        col=i;

        // checking column
        int ones=0;
       while(row<n){
        if(M[row][col]==1){
         ones++;
        }
        row++;
        }
        if(zeros==n && ones==n-1){
            return i;
        }
    }

return -1;
}

// cut 
  int celebrity(vector<vector<int>>&  M, int n){

   stack<int> s;
  // putting all the person in stack
    
    for(int i=0; i<n; i++){
        s.push(i);
    }

    while(s.size()!=1){
        // poping out first 2 elements and checking who knows whom
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();
        // checking if a knows b then keep b back as it can be the potential ans
        if(M[a][b]==1){
          s.push(b);
        }
         // checking if b knows a then keep a back as it can be the potential ans
        else{
            s.push(a);
        }
    }
    // in the last only element will be there in the stack and can be the potential ans
    if(!s.empty()){
        int zeros=0;
        int ones=0;
        for(int i=0; i<n; i++){
            if(M[s.top()][i]==0)
               zeros++;  
        }

        for(int i=0; i<n; i++){

            if(M[i][s.top()]==1)
               ones++;  
            
        }

   // since the person who is celebrity knows no one  this means all the row elemnts should be zero (hence total zeros=n in row)
   // he/she is known by eveyone which means its column contain all 1 except for the row numbered him/her itself (hence total no of the ones=n-1)
        if(zeros==n && ones==n-1){
            return s.top();
        }
           
    }
    return -1;
  }
 
