# include <iostream>
using namespace std;
class stacks{
   private:
   int *arr;
   int top;
   int size;
   public:
   stacks(int n){
     size=n;
     arr=new int[size];
     top=-1;
   }
   int pop();
   void push(int x);
   void display();
};
int stacks::pop(){
    if(top==-1){
        cout<<"hey you better stop right here otherwise stack is going to be unerflow condition "<<endl;
        return -1;
    }
  int temp=arr[top];
  top--;
  return temp;

}
void stacks::push(int x){
    if(top==size-1){
        cout<<"hey you better stop right here otherwise stack is going to be overflow condition"<<endl;
        return;
    }
    top=top+1;
    arr[top]=x;
    
}
void stacks::display(){
     if(top==-1){
        cout<<"There is nothing in the stack to display "<<endl;
        return;
     }
     cout<<"Elements of the stack are : "<<endl;
     for(int i=0; i<=top; i++){
      cout<<arr[i]<<"   ";
     }
     cout<<endl;
}
int main(){
   stacks s=stacks(7);
   for(int i=1; i<=8; i++){
    cout<<"Pushing "<<i*10<<endl;
     s.push(i*10);
      s.display();
   }
    
   s.display();
   for(int i=1; i<=8; i++){
    cout<<"Pop : "<<s.pop()<<endl;
     s.display();
   }
  
  
   return 0;
}
