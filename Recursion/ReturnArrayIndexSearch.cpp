# include <iostream>
# include <vector>
using namespace std;
vector<int> LinearSearch(vector<int> arr, int target, vector<int>& ans, int index){
    if(index==arr.size()){
       return ans;
    }  
    if(arr[index]==target){
     ans.push_back(index);
    }

    return  LinearSearch(arr, target, ans, index+1);

}
int main(){
   vector<int> a;
   vector<int> ans,res;
    int n,m,target;
    cout<<"Enter the size of the array : ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {  cin>>m;
        a.push_back(m);
    }
    cout<<"Enter the target : ";
    cin>>target;
    res=LinearSearch(a,target,ans,0 );
    cout<<"Result : ";
    for (int i = 0; i < res.size(); i++)
    {
        /* code */
        cout<<res[i]<<"  ";

    }
    
    

    return 0;
}