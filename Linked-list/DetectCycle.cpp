
  # include <iostream>
using namespace std;
  // Question : Note use pos to denote the position to which tail of ll is connected
// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).








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
