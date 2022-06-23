

//Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

//Input: head = [], val = 1
//Output: []
//Example 3:

//Input: head = [7,7,7,7], val = 7
//Output: []


  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
      ListNode *temp=head;
      ListNode *prev=NULL;
        while(temp!=NULL){
            if(temp->val==val && temp==head){
                temp=temp->next;
                head=temp;
            }
            else if(temp->val==val){
                prev->next=temp->next;
                temp=temp->next;
            }
            else{
                prev=temp;
                temp=temp->next;
              
            }
        }
        return head;
    }
};
