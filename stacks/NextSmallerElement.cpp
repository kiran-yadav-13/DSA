# include <iostream>
# include <stack>
# include <vector>
# include <string>
using namespace std;

vector<int> NextSmaller(vector<int> &arr, int n){

    vector<int>ans;
    stack<int> st;
    st.push(-1);

    for(int i=n-1; i>=0; i--){
      int curr=arr[i];
        while(curr<=st.top()){
            st.pop();
        }
        ans[i]=s.top();
        st.push(curr)
    }
    return ans;
}

int main(){
    vector<int> a;
    vector<int>ans;
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    
    cout<<"Enter the sum u want : ";
    cin>>sum;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    PairSum(a,n, sum);
    
    return 0;
}
