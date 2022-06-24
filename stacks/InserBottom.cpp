# include <iostream>
# include <stack>
# include <vector>
# include <string>
using namespace std;

void Helper(stack<int>& myStack, int x){

    if(myStack.empty()){
      myStack.push(x);
      return ;
    }
    int temp=myStack.top();
    myStack.pop();
    Helper(myStack, x);
    myStack.push(temp);
 

}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
     Helper(myStack,x);
    return myStack;
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
  cout<<"New element : ";
 cin>>a;


 ans=pushAtBottom(s,a);
  cout<<"After inserting : ";
   while(ans.size() > 0) {
    cout << ans.top() << " ";
    ans.pop();
} 
 cout<<endl;
 return 0;

}
