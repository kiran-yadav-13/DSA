# include <iostream>
# include <vector>
using namespace std;
void solve(vector<string>& ans, string str,string output, int index ){
    // base case
    if(index>=str.length()){
        if(output.length()>0){
            ans.push_back(output);
        }
        
        return ;
    }
    // exclude
    solve(ans,str,output,index+1);
    // include
  
    output.push_back(str[index]);
    solve(ans,str,output,index+1);
}


vector<string > Subsequence(string str){
   vector<string> ans;
   string output="";
   int index=0;
   solve(ans, str,output, index);
   return ans;
}
int main(){
   string a;
    vector<string> ans;
    cout<<"Enter the string : ";
    cin>>a;
   ans=Subsequence(a);
   cout<<" ans vector : ";
      cout<<"[";
   for(int i=0; i<ans.size(); i++){
        cout<<"[";
      for(int j=0; j<ans[i].size(); j++){
      cout<< ans[i][j]<<" ";
      }
cout<<"],"<<endl;
    }
    cout<<"]"<<endl;
    return 0;
}