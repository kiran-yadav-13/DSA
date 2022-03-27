# include <iostream>
# include <vector>

using namespace std;

vector<string> PrintpathList2(string p,int row, int col){
    // &&  because now we have to print all the moves
    vector<string> list;
     if(row==1 && col==1){
         list.push_back(p);
         return list;
     }
    
vector<string> temp;
// for moving diagonal
     if(row>1 && col>1){
        temp=PrintpathList2(p+'D',row-1,col-1);
        list.insert(list.end(),temp.begin(),temp.end());
     }

     if(row>1){
        temp=PrintpathList2(p+'V',row-1,col);
        list.insert(list.end(),temp.begin(),temp.end());
     }
     
    if(col>1){
          temp=PrintpathList2(p+'H',row,col-1);
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

cout<<"path : "<<endl;
//  
 ans=PrintpathList2("",row,col);
 for(int i=0; i<ans.size(); i++){
     cout<<ans[i]<<endl;
 }

    return 0;

}