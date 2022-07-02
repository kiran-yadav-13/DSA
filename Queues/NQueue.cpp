# include <iostream>
# include <stack>
# include <queue>
using namespace std;

class Queue{
    private:
    int* arr;
    int* next;
    int* front;
    int* rear;
    int n;     // no of queues
    int size; // for array size;
    int freeSpace;
    public:
    Queue(int N, int s){
        n=N;
        size=s;
        front=new int[n];
        rear=new int[n];
        arr=new int[size];
        next=new int[size];
        for(int i=0; i<n; i++){
            front[i]=-1;
    }
    
    for(int i=0; i<n; i++){
            rear[i]=-1;
    }
   
    for(int i=0; i<n; i++){
            front[i]=-1;
    }
    int i;
    for(i=0; i<size; i++){
        next[i]=i+1;
    }
    next[i-1]=-1;
    freeSpace=0;


    }

    void push(int x, int n){
        if(rear[n]==size-1){
            cout<<"Hey its going to be overflow. so, you better stop right here"<<endl;
            return;
        }
       // found the index

       int index=freeSpace;

       // update the freespace
       freeSpace=next[index];
        if(front[n-1]==-1){
            front[n-1]=index;
            
        }
        else{
          next[rear[n-1]]=freeSpace;
        }
       // update next
       next[index]=-1;

       // upate rear
       rear[n-1]=index;

       //push element
       arr[index]=x;
    }
    int pop(int n){
        
        if(front[n-1]==-1){
            cout<<"Underflow  "<<endl;
        }
       

        // find index to pop
         int  index=front[n-1];
          int poped=arr[index];
         // front ko aage bdhao
         front[n-1]=next[index];

         // freeslots ko manage karo
         next[index]=freeSpace;
         freeSpace=index;

         return poped;
    }

};

int main(){
    Queue q= Queue(3,7);
    q.push(10,1);
    q.push(20,1);
    q.push(30,2);
    q.push(40,1);
    q.push(50,3);
    cout<<q.pop(1)<<endl;
    cout<<q.pop(2)<<endl;
     cout<<q.pop(3)<<endl;


}
