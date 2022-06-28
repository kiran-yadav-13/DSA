# include <iostream>
# include <stack>
# include <vector>
# include <string>
using namespace std;

// Approach ::
// Apprach elements from right because for the element at particular index its ans lies on the right it saves time and no of comparisons
// if we apprach from left for every element we have to do o(n^2) comparisions
// use a stack for storing traversed part
// for every elemnt we are trying to find the first smallest elemnt on right so if the top element is greater than the ccurrent element then pop until the element get smaller or stack element

// 2 1 4 3
// Assuming that we can only find the smaller element from the stack only 
// creating ans vector for storing ans
// initailly push -1 for 3
// for 3 check if s.top < 3 then ans is the top element and push current (3);  (agar chota element mil gya)  (since -1<3) ans[3]=-1   push 3 (element) stack  => 3 -1
// agar s.top chota element nhi hai to. chotta elemt dhundo by poping the elemnt till found s.top<current element znd then store the ans and push the current element

// for  4 i=2 since s.top<curr (3<4) ans[2]=3 push 4 stack=> 4 3 -1
// for 1 i=1  s.top>curr (4>1)  pop stack => 3 -1  s.top>curr (3>1) pop stack => -1  s.top < curr (-1<1) while stop ans[1]=-1  push current  NOW STACK=> 1 -1
// for  2 i=0 since s.top<curr (1<2) ans[0]=1 push 2 stack=> 2 1 -1


vector<int>

vector<int> NextSmaller(vector<int> &arr, int n){
   
    vector<int>ans;
    stack<int> st;
    st.push(-1);

   

    for(int i=n-1; i>=0; i--){
      int curr=arr[i];
        while(curr<=st.top()){
            st.pop();
        }
        ans[i]=st.top();
        st.push(curr);
    }
    return ans;
}

int main(){
    vector<int> a;
    vector<int>ans;
    int n,b;
    cout<<"Enter the size of the array : ";
    cin>>n;
    
    for (int i = 0; i < n; i++)
    {
        cin>>b;
        a.push_back(b);
    }
     ans=NextSmaller(a,n);
    
      for (int i = 0; i < ans.size(); i++)
    {
       cout<<ans[i]<<"   "<<endl;
    }
    return 0;
}
