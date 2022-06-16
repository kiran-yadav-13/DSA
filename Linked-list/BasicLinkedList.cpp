# include <iostream>
using namespace std;

struct node{
    
    public :
    int val;
    node *next;     // to point rhe value of node type
  //  node(){

  //  }
  //   node(int info){
      
  //       this->val=info;
  //       this->next=NULL;
  //    }

  //    node(int info, node *ptr=NULL){
  //       this->val=info;
  //       this->next=ptr;
  //    }
};

class LinkedList{

     public:
     node* head;
     node* tail;
     int size=0;

    LinkedList(){
       head=tail=NULL;

      }

      node* createnewNode(int val);
      void insertFirst(int);
      void insertLast(int);
      void display();
      int deleteBegin();
      int deleteAtEnd();
      node* getPrevious(int index);
      node* InsertRecursive(int val, int index, node* current);
      node* RemoveDuplicates();
      // LinkedList Merge(  LinkedList L1, LinkedList l2);
      bool DetectCycle();
};

node* LinkedList::getPrevious(int index){
    node* targetprev=new node();
   targetprev= head;
      for(int i=0; i<index; i++){
        targetprev=targetprev->next;
     
      }
      return targetprev;
}

void LinkedList::display(){

    if(head==NULL){
     cout<<"LinkedList is Empty. Nothing to display :( "<<endl;
     return;
    }

   for(node* temp=head; temp!=NULL; temp=temp->next){
     cout<<temp->val<<" ->";
   }
   cout<<"END\n";

}

// node* LinkedList::createnewNode(int info){
//  node* Node=new node();
//  Node=createnewNode(info);
//  cout<<Node->val;
//  return Node;
// }

 node* LinkedList:: createnewNode(int newinfo){
        node *newNode=new node();
        newNode->val=newinfo;
        newNode->next=NULL;
        return newNode;
    }

void LinkedList::insertFirst(int info ){

       node *temp =new node();
       temp=createnewNode( info);
       if(head==NULL){
          size++;
        tail=head=temp;
        cout<<head->val<<endl;
        return;
       }
       temp->next=head;
       head=temp;
       size++;

}

void LinkedList::insertLast(int info ){
       node* temp=new node();
       temp=createnewNode(info);
       if(head==NULL){
          size++;
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

       node* temp  =new node();
       temp=head;
       int begin=temp->val;
        if(head==tail){
           head=tail=NULL;
         size--;
       delete temp;
       return begin;
        }
        head=head->next;
        size--;
       delete temp;
       return begin;

}

int LinkedList::deleteAtEnd(){
      if(head==NULL){
           cout<<"LinkedList is Empty. Nothing to delete :( "<<endl;
           return -1;
      }
       node* temp;
       temp=tail;
       int begin=temp->val;
        if(head==tail){
           head=tail=NULL;
             size--;
        delete temp;
       return begin;
        }
// node* t;
// for(t=head; t->next->next!=NULL; t=t->next){
     
// }
// tail=t;

   tail=getPrevious(size-2);
       cout<<"tail "<<tail->val<<endl;
   tail->next=NULL;
 
       size--;
       delete temp;
       return begin;
}

node* LinkedList::InsertRecursive(int val,int index,node* current){
  if(index==0){
     node* Node  =new node();
     Node=createnewNode(val);
     Node->next=current;
     return Node;
  }

  current->next=InsertRecursive(val,index-1,current->next);
  return current;
     
}
node* LinkedList::RemoveDuplicates(){
  // for sortted linked List => duplicate is just after the element
  node* temp=head;
  // cannot use for loop instead of while because for loop also iterates when if condition got true and we removed the duplicate element and now at the new element(for loop do temp=temp->next without checking for duplicates)
  while(temp->next!=NULL){
      if(temp->val==temp->next->val){
      temp->next=temp->next->next;
    }
    else{
      temp=temp->next;
    }
  }
 
  tail=temp;
  tail->next=NULL;
  return head;
}
bool LinkedList::DetectCycle(){

  // using the concept of fast and slow pointer .
  // fast pointer moves 2 steps at a time while the slow pointer is taking one step at a time 
  // if there's no loop(cycle) fast pointer will reach to null first 
  // if there is cycle the fast pointer will meet the slower one at 2nd round through cycle
   if(head==NULL){
    return false;

   }

node *fast=head;
node *slow=head;
  while(fast!=NULL && fast->next!=NULL){ 
    // no need to check for slow as if first become Null slow will also become null sfter some time 
    // need to check fast->next beacuse we are move fast as fast->next->next
    fast=fast->next->next;
    slow=slow->next;
    if(fast==slow){
      return true;
    }
  }
  return false;
}


// LinkedList LinkedList:: Merge( LinkedList l1,LinkedList l2){
//     LinkedList ans;
//     node* head1=l1.head;
//     node* head2=l2.head;
//     while(head1!=NULL && head2!=NULL){
//       if(head1->val<=head2->val){
//         ans.insertLast(head1->val);
//       }
//     }
//     while(head1!=NULL){
//       ans.insertLast(head1->val);
//     }
//      while(head2!=NULL){
//       ans.insertLast(head2->val);
//     }
//     ans.display();
// //     cout<<"erge"<<endl;
//  return ans;

}
int main(){
 
  LinkedList l,l2,l1;
  LinkedList ans;
  //  l.InsertRecursive(80,1,l.head);
  l.insertFirst(10);
  l.insertLast(20);
  l.insertFirst(30);
  l.insertLast(40);
  l.InsertRecursive(80,1,l.head);
  l.display();
  l.deleteBegin();
  l.display();
  l.deleteAtEnd();
  l.display();
  l.InsertRecursive(80,1,l.head);
  l.insertLast(20);
  l.display();
  l.insertLast(20);
  l.display();
  l.RemoveDuplicates();
  cout<<"Removing";
  l.display();
 
 l1.insertLast(10);
  l1.insertLast(20);
  l1.insertLast(30);
  l1.insertLast(70);

 l2.insertFirst(10);
  l2.insertLast(50);
  l2.insertFirst(60);
  l2.insertLast(70);

  // ans=l.Merge(l1,l2);
  // ans.display();


  return 0;
}