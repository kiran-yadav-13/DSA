# include <iostream>
using namespace std;

// NOTE : INCLUDE node and LinkedList class before execeuting it :)
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
