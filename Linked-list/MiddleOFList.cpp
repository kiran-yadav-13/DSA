# include <iostream>
using namespace std;

// Given the head of a singly linked list, return the middle node of the linked list.
//If there are two middle nodes, return the second middle node.

//Input: head = [1,2,3,4,5]
//Output: [3,4,5]
E//xplanation: The middle node of the list is node 3.

// note include LINKEDlIST AND NODE class to run it
// Approach : fast and slow pointer
// at the time when the fast pointer reach at the end the slow will reach at the middle element 
// because  fast is moving two steps at a time and slow is moving one step at a time

node* LinkedList::GetMidNode(){
  node *fast=head;
  node *slow=head;

  while(fast!=NULL && fast->next!=NULL){
    fast=fast->next->next;
    slow=slow->next;
  }
  return slow;
}
