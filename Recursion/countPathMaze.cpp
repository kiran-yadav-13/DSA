# include <iostream>
# include <vector>

using namespace std;
int pathMazecount(int row, int col){
    if(row==1 || col==1){
        return 1;
    }
    int MoveDown=pathMazecount(row-1, col);
    int MoveRight=pathMazecount(row,col-1);
    return MoveDown+MoveRight;

}

void Printpath(string p,int row, int col){
    // &&  because now we have to print all the moves
     if(row==1 && col==1){
         cout<<p<<endl;
     }
     if(row>1){
        Printpath(p+'D',row-1,col);
     }
    if(col>1){
        Printpath(p+'R',row,col-1);
     }

}
// if veritical , downward , diagonal, movesw are allowed
vector<string> PrintpathList(string p,int row, int col){
    // &&  because now we have to print all the moves
     if(row==1 && col==1){
         vector<string> list;
         list.push_back(p);
         return list;
     }
     vector<string> list;

     if(row>1){
        vector<string> left=PrintpathList(p+'D',row-1,col);
        list.insert(list.end(),left.begin(),left.end());
     }
     
    if(col>1){
          vector<string> right=PrintpathList(p+'R',row,col-1);
          list.insert(list.end(),right.begin(),right.end());
     }
     return list;

}
// experiment
vector<string> PrintpathList2(string p,int row, int col){
    // &&  because now we have to print all the moves
    vector<string> list;
     if(row==1 && col==1){
         list.push_back(p);
         return list;
     }
    
vector<string> temp;
     if(row>1){
        temp=PrintpathList2(p+'D',row-1,col);
        list.insert(list.end(),temp.begin(),temp.end());
     }
     
    if(col>1){
          temp=PrintpathList2(p+'R',row,col-1);
          list.insert(list.end(),temp.begin(),temp.end());
     }
     return list;

}
int main(){
int row, col;
vector<string> ans;
cout<<"Enter the no of rows : ";
cin>>row;
cout<<"Enter the no of columns : ";
cin>>col;
cout<<"No of paths : "<<pathMazecount(row, col)<<endl;
cout<<"path : "<<endl;
//  
 ans=PrintpathList2("",row,col);
 for(int i=0; i<ans.size(); i++){
     cout<<ans[i]<<endl;
 }

    return 0;

}