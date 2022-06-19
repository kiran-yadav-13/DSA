# include <iostream>
using namespace std;

//       prev cur  next 
//      null   |   |
//  orignal     1=>2=>3=>4=>5
///             1<=2<=3<=4<=5
//  reversed    5=>4=>3=>2=>1

// Approach in Linked List questions just draw the orignal and changed LinkedList and see the changes or links req to change the Linked List
// and write the code . don't overthink
// current->next=prev
// prev=current
// current=next;
//next=next->next //check for null pointer

// Note : Include LinkedList and node class to run the code

node* LinkedList::IterativeReverse(){
  node *prev=NULL;
  node *current=head;
  node *Next=current->next;

  if(head==NULL){
    return head;
  }

  while(current!=NULL){
    current->next=prev;
    prev=current;
    current=Next;
    if(Next!=NULL){
         Next=Next->next;
    }
  }
  head=prev;
  return head;

}
