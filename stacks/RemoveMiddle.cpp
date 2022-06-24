# include <iostream>
# include <stack>
# include <vector>
# include <string>
using namespace std;
// https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246

// INPUT : ARR [ ] = [ 1 , 2 , 3 , 4 , 5 ] , N = 4
// OUTPUT: ARR [ ] = [ 1 , 2 , 4,  5 ]


void Helper(stack<int> &s, int count, int size){
    if(count==size/2){
    s.pop();
    return;
    }
    int temp=s.top();
    cout<<"temp "<<temp<<endl;
    s.pop();
    Helper(s,count+1, size);
    s.push(temp);
  return;
}

void RemoveMiddle(stack<int> &s, int n){
//   int mid=s.size()/2;

  Helper(s,0, n);

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
 cout<<"Orignal : ";
//   for(int i=0; i<s.size(); i++){

//     cout<< s.top()<<" ";
//  }
 cout<<endl;
 RemoveMiddle(s,s.size()-1);
  cout<<"After removal : ";
  for(int i=0; i<s.size(); i++){

    cout<< s.top()<<" ";
    s.pop();
 }
 cout<<endl;
 return 0;

}
