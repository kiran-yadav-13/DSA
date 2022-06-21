// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

class Solution {
public:
    int Length(ListNode* head){
        int l=0;
         for(ListNode* temp=head; temp!=NULL; temp=temp->next ){
            l++;
        }
        return l;
    }
    int getDecimalValue(ListNode* head) {
        int decimal=0;
        int l=Length(head)-1;
        
        for(ListNode* temp=head; temp!=NULL; temp=temp->next ){
            decimal+=temp->val*pow(2,l);
            l--;
              
        }
      
        return decimal;
    }
};
