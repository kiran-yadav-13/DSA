# include <iostream>
# include <vector>
using namespace std;
vector<int> LinearSearch(vector<int> arr, int target, int index){
   vector<int> list;
   if(index==arr.size()){
       return list;
   }
   if(arr[index]==target){
       list.push_back(index);
   }
   vector<int> ansFromBelowCalls=LinearSearch(arr, target, index+1);
   list.insert(list.end(),ansFromBelowCalls.begin(),ansFromBelowCalls.end());
   return list;
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
    res=LinearSearch(a,target,0 );
    cout<<"Result : ";
    for (int i = 0; i < res.size(); i++)
    {
        /* code */
        cout<<res[i]<<"  ";

    }
    
    

}