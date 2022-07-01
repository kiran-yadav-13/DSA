# include <iostream>
# include <stacks>
# include <queue>
using namespace std;

// aPPROACH1
void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    if(q.size()<=2){
        return;
    }
    int mid=q.size()/2;
    queue<int> q2;
    int i=0; 
    while(i<mid){
        q2.push(q.front());
        q.pop();
        i++;
    }
    i=0;
    while(i<mid){
     
      q.push(q.front());
      q.pop();
      q.push(q2.front());
      q2.pop();
      i++;

    }


}

// APPROACH 2
// NO other queue is allowed
    void interLeaveQueue(queue < int > & q) {
   
 if(q.size()<=2){
        return;
    }
    int mid=q.size()/2;
    stack<int> st;
    int i=0;
    // first push on the stack the first half get reversed
    while(i<mid){
        
        st.push(q.front());
        q.pop();
        i++;

       
    }

    
 // now reversed second half is at the end
    while(!st.empty()){
        q.push(st.top());
        st.pop();
       
    }
    // putting the 2nd next half at the back so that 1st revese half can come in front an can be taken
        i=0;
        while(i<mid){
        q.push(q.front());
        q.pop();
        i++;
    }
// fetching an Re-reversing(rignal) the other 1st half in stack
      i=0;
    while(i<mid){
         st.push(q.front());
        q.pop();
        i++;
    }


 // Now 1st half is in queue in correct order 
// 2nd half is in queue itself
    while(!st.empty()){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();

    }
}

int main(){
    queue<int>q;
    for(int i=0; i<10; i++){
        q.push(i*10);
    }
    return 0;
}
