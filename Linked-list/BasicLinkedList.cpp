# include <iostream>
using namespace std;
class node{
    
    public :
    int val;
    node* next;     // to point rhe value of node type
 node(int val){

        val=val;
        next=NULL;
     }
     node(int val, node* ptr=NULL){
        val=val;
        next=ptr;
     }
};

class LinkedList{
       public:
     node* head;
     node* tail;
      int size;
      LinkedList(){
        head=tail=NULL;

      }
      node createnewNode(int val);
      void insertFirst(int);
      void insertLast(int);
      void display();
      int deleteBegin();
      int deleteAtEnd();
      node* get(int index);
     
};
node LinkedList::getPrevious(int index){
    node* targetprev=head;
      for(int i=0; i<index; i++){
        targetpt=targetprev->next;
      }
      return targetprev;
}
void LinkedList::display(){

    if(head!=NULL){
     cout<<"LinkedList is Empty. Nothing to display :( "<<endl;
     return;
    }
   for(node* temp=head; temp!=NULL; temp=temp->next){
     cout<<temp->val<<"->";
   }
   cout<<"END\n";

}
node LinkedList::createnewNode(int val){
 node Node=new node(info);
 return Node;
}
void LinkedList::insertFirst(int info ){
       node temp=createnewNode( info);
       if(head==NULL){
        tail=head=temp;
       }
       temp->next=head;
       head=temp;
       size++;

}
void LinkedList::insertLast(int info ){
       node temp=createnewNode(int info);
       if(head==NULL){
        tail=head=temp;
       }
       tail->next=temp;
       tail=temp;
       size++;

}

int LinkedList::deleteBegin(){
       
       if(head==NULL){
           cout<<"LinkedList is Empty. Nothing to delete :( "<<endl;
           return -1;
         }

       node temp=head;
       int begin=temp->val;
        if(head==tail){
           head=tail=NULL;
        }
        size--;
       delete temp;
       return begin;

}

int LinkedList::deleteAtEnd(){
      if(head==NULL){
           cout<<"LinkedList is Empty. Nothing to delete :( "<<endl;
           return -1;
         }

       node temp=tail;
       int begin=temp->val;
        if(head==tail){
           head=tail=NULL;
        }
       size--;
       delete temp;
       return begin;
}

int main(){
 
  LinkedList l=new LinkedList();
  l.insertFirst(10);
  l.insertLast(20);
  l.insertFirst(30);
  l.insertLast(40);
  l.display();
  return 0;
}