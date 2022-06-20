//         (newEnd)left           right
//              last |              |
//     head      |   |              |
 //      14=>15=>16=>1 => 2 => 3 => 4 => 5
///      14=>15=>16=>3 => 2 => 1 => 4 => 5

// if last==NULL
//         (newEnd)left       right
//              last |          |
//         head  |   |          |
 //          |___1 => 2 => 3 => 4 => 5
node* LinkedList::PartReverse(int left, int right){
   if (left == right) {
            return head;
        }
      node *newEnd=head;
      node *last=NULL;

     // positioning last to 1 node before left
     // newEnd is the node at left

      for(int i=0; newEnd!=NULL && i<left-1; i++){
        last=newEnd;
        newEnd=newEnd->next;
        

      }
      // Reversing
      node *prev=last;
      node *current=newEnd;
      node *Next=current->next;

      for(int i=0; current!=NULL && i<right-left+1; i++){
        current->next=prev;
        prev=current;
        current=Next;
        if(Next!=NULL){
          Next=Next->next;
        }
      }

      if(last!=NULL){
        last->next=prev;
      }
      else{
         head=prev;
      }

      newEnd->next=current;

      return head;

}
