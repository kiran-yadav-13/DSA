# include <iostream>
using namespace std;
const int MAX=3;
class Queue{
   private:
   int f,r;
   int q[MAX];
   public:
   Queue(){
      f=r=-1;
   }
   void addition(int in);
   int deletion();
   int isfull();
   int isEmptty();
   void Display();
   int Search(int s);
   int count ();

};
int Queue :: isEmptty(){
    if(f==r==-1){
        return 1;
    }
    else
    {
        return -1;
    }
}
int Queue ::isfull(){
    if(r==(MAX-1)){
        return 1;
    }
    else{
        return -1;
    }
}
void Queue :: addition(int in){
      if(f==r==-1){
          f=r=0;
          q[0]=in;
      }
      else{
          r++;
          q[r]=in;

      }
}
int Queue :: deletion(){
    int del;
    if(f==r){
        del=q[f];
        f=r=-1;
        return del;
    }
    else{
        del=q[f];
        f--;
        return del;

    }
}
void Queue::Display(){
    if(f==r==-1){
        cout<<"Queue is Empty(Underflow) . Nothing to display"<<endl;
    }
    else{
        cout<<"Elements of the Queues from front to rear end are: "<<endl;
        for (int  i = f; i <= r; i++)
        {
           cout<<q[i]<<" ";
        }
      cout<<endl;
    }
}
int Queue ::Search(int s){
    int pos=0;
    for(int pos=f; pos<=r;  pos++)
     {
         if(q[pos]==s){
             return pos;
         }
     }
     return -1;
}
int Queue :: count(){
    int c=0;
     for(int i=f; i<=r; i++)
     {
         c++;
     }
     return c;
}
int main(){
   Queue q;
   int in , choice, e, c;
   char c='y';
   while(c=='y'|| c=='Y')
  {
    cout<<"Main menu"<<endl;
    cout<<" 1.Add an element in the queue"<<endl;
    cout<<" 2.Delete an element from the queue"<<endl;
    cout<<" 3.check for emptyness"<<endl;
    cout<<" 4.check for full condition"<<endl;
    cout<<" 5.No of elements in Queue"<<endl;
    cout<<" 6.Search an Element in arrray"<<endl;
    cout<<"Enter your choice";
    cin>>choice;
    switch(choice)
    {
         case 1:  if(!q.isfull());
                 {
                    cout<<"Enter the element to be inserted : ";
                    cin>>in;
                    q.addition(in);
                 }
                 else{
                     cout<<"Queue is Full (overflow) . No more elements can be inserted!! "<<endl;
                 }
                 break;
         case 2:  if(!q.isEmptty());
                 {
                   e= q.deletion();
                 }
                 else{
                     cout<<"Queue is Empty (underflow) . No more elements can be deleted!! "<<endl;
                 }
                 break;
         case 3: if(q.isEmptty());
                 {
                   cout<<"Queue is Empty"<<endl;
                 }
                 else{
                     cout<<"Queue is not Empty "<<endl;
                 }
                 break;
         case 4: if(q.isfull());
                 {
                   cout<<"Queue is Full"<<endl;
                 }
                 else{
                     cout<<"Queue is not Full "<<endl;
                 }
                 break;
         case 5:  c=q.count();
                 cout<<"No of elements in queue is : "<<c<<endl;
                 break;
         case 6: if(!q.isEmptty()){
                   cout<<"Enter the element you want to be searched : ";
                   cin>>in;
                  e=q.Search(in);
                  if(e!=-1)
                  cout<<"Element found at the position: "<<e<<endl;
                  else
                  cout<<"Element not found "<<endl;
                    }
                    else{
                        cout<<"Queue is empty . Nothing can be searched "<<endl;
                    }
                    break;
        default:   cout<<"You entered a wrong choice "<<endl;
    } 
    cout<<"Do you want to continue ? ";
    cin>>c;
    }

   return 0;
}
