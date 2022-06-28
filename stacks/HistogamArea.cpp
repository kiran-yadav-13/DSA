# include <iostream>
# include <limits>
# include <stack>
# include <vector>
# include <string>

using namespace std;

//  5 4 3 1 2
// since length is constant we have to find the max breadth that can be achieved
//  for max breadth Firstly we have to find the index  of the nextsmalleRight and pevious smallleft unlike the previous quetion
// kha tak extend kar sakte hai- jab tak next bars bade ho // found the next smallest bar
// 
vector<int> nextSmallestRight(vector<int>& heights, int n){
    stack<int> st;
    // pushing 
    st.push(-1);
    vector<int> ans(n);

    
    
    for(int i=n-1; i>=0; i--){
        int curr=heights[i];
       while(st.top()!=-1 && curr<=heights[st.top()]){
        st.pop();
       }
      ans[i]=st.top();
      st.push(i);

    }
    return ans;
}
vector<int> nextSmallestleft(vector<int>& heights, int n){
 
    stack<int> st;
    vector<int> ans(n);

    // pushing 
    st.push(-1);
    
    for(int i=0; i<=n-1; i++){
        int curr=heights[i];
       while(st.top()!=-1 && curr<=heights[st.top()]){
        st.pop();
       }
      ans[i]=st.top();
      st.push(i);

    }
    return ans;

}

 int largestRectangleArea(vector<int>& heights) {
        
        int size=heights.size();
        vector<int> left(size);
     
         left=nextSmallestleft(heights , size);
     
        vector<int> right(size);
        right=nextSmallestRight(heights,size);
        int area=INT32_MIN;

        for(int i=0; i<size; i++){
          int l=heights[i];
         // when all in the right side is of same height as this particular one
          if(right[i]==-1){
            right[i]=size;
          }
           int b=right[i]-left[i]-1;
          
          int Newarea=l*b;
          area=max(area,Newarea);

        }
        
        return area;
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
     cout<<"Area : "<<largestRectangleArea(a);
    
    
}
