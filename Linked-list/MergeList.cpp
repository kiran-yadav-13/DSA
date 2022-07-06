// 10=>30=>50=>70=>90>END
// 20=>40=>60=>80=>100>END

node* LinkedList:: Merge(LinkedList l2){
   
    node* head1=head;
    node *prev=NULL;
    node* head2=l2.head;
    cout<<"Hello world : "<<endl;
    while(head1!=NULL && head2!=NULL){
      
      //  cout<<"prev "<<head2->val<<endl;
      if(head1->val<head2->val){
       prev=head1;
        head1=head1->next;
        
      }
      else if(head1->val==head2->val){
          prev=head1;
          head1=head1->next;
          prev->next=head2;
          head2=head2->next;
          prev->next->next=head1;
           prev=prev->next;
      }
      else{
          prev->next=head2;
          prev->next->next=head1;
          head2=head2->next;
          prev=prev->next;
      }
      cout<<"head 1 "<<head1->val<<endl;
      cout<<"head 2 "<<head2->val<<endl;
      cout<<"Prev "<<prev->val<<endl;
       
      cout<<"CURRENT LIST "<<endl;
      display();
    }
    while(head1!=NULL){
       cout<<"head 1 "<<head1->val<<endl;
       head1=head1->next;
    }
     while(head2!=NULL){
      // cout<<"prev "<<prev->val<<endl;
      cout<<"head 2 "<<head2->val<<endl;
       prev->next=head2;
       head2=head2->next;
    }
    
    display();
//     cout<<"erge"<<endl;
 return head;

}
