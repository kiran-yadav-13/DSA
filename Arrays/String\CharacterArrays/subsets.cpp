# include <iostream>
# include <vector>
using namespace std;
void solve(vector<int>nums, vector<int> output, int index, vector<vector<int>>& ans){
    // base case
    if(index>=nums.size()){
        ans.push_back(output);
        return ;
    }
    // exclude
    solve(nums,output,index+1,ans);
    // include
    int element=nums[index];
    output.push_back(element);
    solve(nums,output,index+1, ans);
}

// Dry Run:
// nums=[1,2,3] nums.size() = 3
// solve([1,2,3],[],0,[[]])  element=1 output=[3,2,1] solve([1,2,3],[3,2,1],1,[[],[3],[3,2]])
// solve([1,2,3],[],1,[[]])  element=2 output=[3,2]   solve([1,2,3],[3,2],2,[[],[3]]) -> solve([1,2,3],[3,2],3,[[],[3]]) ans=[[],[3], [3,2]]
                 //                                  element=2   solve([1,2,3],[3,2]  )
// solve([1,2,3],[],2,[[]])  element=3 output=[3]     solve([1,2,3],[3],3,[[]]) -> ans=[[],[3]]  return
// solve([1,2,3],[],3,[[]])  ans=[]  return
vector<vector<int> > Subsets(vector<int>& nums){
   vector<vector<int>> ans;
   vector<int> output;
   int index=0;
   solve(nums, output, index, ans);
   return ans;
}
int main(){
   int n,a;
    cin>>n;

    vector<vector<int>> ans;
    vector<int> num;
    cout<<"Enter the elements in nums : ";
    for(int i=0; i<n; i++){
     cin>>a;
      num.push_back(a);
    }
   ans=Subsets(num);
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
