node* LinkedList::ReverseKGroup(int k){
    if(k<=1 || head==NULL){
     return head;
   }

   int length=getLength(head);
   int count=length/k;     // counting the groups to be reversed


   node *current=head;
   node *prev=NULL;
   
   while(count>0){
   node* last=prev;
   node* newEnd=current;
   node *Next=current->next;

   for(int i=0; i<k && current!=NULL; i++){
      current->next=prev;
       prev=current;
       current=Next;
       if(Next!=NULL){
          Next=Next->next;
       }
   }
   if(last!= NULL){
    last->next=prev;
   }
   else{
    head=prev;
   }
    newEnd->next=current;  // last end of the last kth group is pointing to the current heAD
    prev=newEnd;          //pointing to the latest end
    count--;
     
   }
   return head;

}
