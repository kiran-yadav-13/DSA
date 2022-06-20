//                         mid
// orignal : 10 ->20 ->30 ->40 ->30 ->20 ->10 ->END
//  list after getting reversed : 10 ->20 ->30 ->40 ->END
// temp->val10
// Secondhead->val10
// temp->val20
// Secondhead->val20
// temp->val30
// Secondhead->val30
// temp->val40
// Secondhead->val40

// pallindrome :1
// 10 ->20 ->30 ->40 ->30 ->20 ->10 ->END
bool LinkedList::Pallindrome(node *temp){
  // APPROCAH :
  // GET THE MIDDLE ELEMENT AND REVERSE THE HALF OF THE LINKEDlIST using the mid element as head
  // take the head of the reversed linkedList and start compairing their elemt till one of them become null
  // NULL MEANS THEY SUCESSFULLY FINISHED THE LOOP TRAVERSAL AND DOESNOT BREAK IN BETWEEN HENCE PALLINDROME

      
      node *mid=GetMidNode();
      node *headSecond=IterativeReverse(mid);
      node  *ReverseHead=headSecond;
       
       while(temp!=NULL && headSecond!=NULL){
        if(temp->val!=headSecond->val){
          break;
        }

      
        temp=temp->next;
        headSecond=headSecond->next;
     
       }
       display();
        IterativeReverse(ReverseHead);
        
   return temp==NULL || headSecond==NULL; // THIS MEANS THEY SUCESSFULLY FINISHED THE LOOP TRAVERSAL AND DOESNOT BREAK IN BETWEEN HENCE PALLINDROME
}
