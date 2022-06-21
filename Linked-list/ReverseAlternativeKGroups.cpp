node* LinkedList::ReverseAlternativeKGroup(int k){
     
     if(k<=1 || head==NULL){
      return head;
     }

//   skip  the left-1 nodes
  node *current=head;
  node *prev=NULL;

  while(current!=NULL){
    node *last=prev;
    node *newEnd=current;
    node *Next=current->next;
//  reverse between left and right
      
    node *temp=current;
    for(int i=0; temp!=NULL && i<k; i++){
        temp=temp->next;
   }
   if(temp==NULL){
      break;
    }
    
   cout<<"current : "<<current->val<<endl;

    for(int i=0; current!=NULL && i<k; i++){
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


   
   // skip the k nodes;
   for(int i=0; current!=NULL && i<k; i++){
    prev=current;
    current=current->next;
   }
    

  }

  return head;
}
