# include <iostream>
# include <stack>
# include <vector>
# include <string>
using namespace std;

void Arrange(stack<int> &stack, int temp){
    if(stack.empty() || (temp>stack.top())){
        stack.push(temp);
        return;
    }

    int demp=stack.top();
    stack.pop();
    Arrange(stack, temp);
    stack.push(demp);

    

}

void sortStack(stack<int> &stack)
{
	if(stack.empty()){
        return;
    }
    int element=stack.top();
    stack.pop();
    sortStack(stack);
    Arrange(stack,  element);

}
int main(){
stack<int> s;
 int n,a;
 cout<<"How many element : ";
 cin>>n;
 for(int i=0; i<n; i++){
    cin>>a;
    s.push(a);
 }

  sortStack(s);
  cout<<"After Reversing : ";
 while(s.size() > 0) {
    cout << s.top() << " ";
    s.pop();
} 
 cout<<endl;
 return 0;
}
