int LinkedList::CountCycleLength(){
   if(head==NULL){
    return 0;

   }
   node *fast=head;
   node *slow=head;
   while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast){

      // if slow and fast are equal that means there is a cycle
      // now for counting length we have to make one of them stationary and move other(one step at a time that's why slow choosen) to count
      // use the do  while  loop beacuse condition not to be false at first step 
      // use of temp mvariable
      // count and return the length

   
     int count=0;
       do{
              slow=slow->next;
              count++;
        } while(fast!=slow);
        return count;
    }
   }
   return 0;

}
