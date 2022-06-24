# include <iostream>
# include <stack>
# include <vector>
# include <string>
using namespace std;

// approach :
// top element ko side rakh lo
// use recursion to reverse the remaining element 
// wapas aate hue us top elemnt ko reversed stack me push kar do

void InsertAtBottom(stack<int> &stack, int element){
    if(stack.empty()){
        stack.push(element);
        return;
    }
    int temp=stack.top();
    stack.pop();
    InsertAtBottom(stack, element);
   stack.push(temp);

}


void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return;
    }
    int temp=stack.top();
    stack.pop();
    reverseStack(stack);
    InsertAtBottom(stack, temp);
    
}

int main(){
stack<int> s,ans;
 int n,a;
 cout<<"How many element : ";
 cin>>n;
 for(int i=0; i<n; i++){
    cin>>a;
    s.push(a);
 }

  reverseStack(s);
  cout<<"After Reversing : ";
 while(s.size() > 0) {
    cout << s.top() << " ";
    s.pop();
} 
 cout<<endl;
 return 0;
}
