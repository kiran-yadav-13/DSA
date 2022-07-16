# include <iostream>
using namespace std;

struct node{
    
    public :
    int val;
    node *next;     // to point rhe value of node type
  //  node(){

  //  }
  //   node(int info){
      
  //       this->val=info;
  //       this->next=NULL;
  //    }

  //    node(int info, node *ptr=NULL){
  //       this->val=info;
  //       this->next=ptr;
  //    }
};

class LinkedList{

     public:
     node* head;
     node* tail;
     int size=0;

    LinkedList(){
       head=tail=NULL;

      }

      node* createnewNode(int val);
      void insertFirst(int);
      void insertLast(int);
      void display();
      int deleteBegin();
      int deleteAtEnd();
      node* getNode(int index);
      node* InsertRecursive(int val, int index, node* current);
      node* RemoveDuplicates();
      node* Merge(  LinkedList l2);
      int CountCycleLength(node *head);
      node* findStartCycle();
      
      bool DetectCycle();
      void BubleSort();
      void BubbleSortHelper(int row, int  col);
      node* GetMidNode();
      node* RecursionReverse(node*);
      node* IterativeReverse(node*);
      node* PartReverse(int left, int right);
      bool  Pallindrome(node *);
      node* Reorder(node*);
      node* ReverseKGroup(int k);
      node* ReverseAlternativeKGroup(int k);
      int getLength(node *head);
      int getValue(int index);
      void AddatIndex(int index, int value);
};
void LinkedList::AddatIndex(int index, int value){
  node *temp=getNode(index-1);
  cout<<temp->val<<endl;
}

int LinkedList::getValue(int index){
   node *temp=head;
        for(int i=1; temp!=NULL && i<index; i++){
            temp=temp->next;
        }
        return temp->val;
}

int LinkedList::getLength(node* head){

      if(head==NULL){
        return -1;
      }
     int l=0;
      for(node* temp=head; temp!=NULL; temp=temp->next){
        l++;
       }
 return l;

  
}

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


//       headFirst                          headSecond
//  orignal : 10 ->20 ->30 ->40 ->50 ->60 ->70 ->END
//reordered : 10 ->70 ->20 ->60 ->30 ->50 ->40 ->END
//  node* temp=headFirst->next;       temp=20
//     headFirst->next=headSecond;   headFirst->next=70
//     headFirst=temp;                headFirst=20;
//     temp=headSecond->next          temp=60
//     headSecond->next=headFirst;   70->next=20
//     headSecond=temp;              headSecond=60
node* LinkedList::Reorder(node* temp){
      node *mid=GetMidNode();
      node *headSecond=IterativeReverse(mid);
      node *headFirst=temp;
      while(headFirst !=NULL && headSecond!=NULL){
         node *temp=headFirst->next;
         headFirst->next=headSecond;
         headFirst=temp;

         temp=headSecond->next;
         headSecond->next=headFirst;
         headSecond=temp;
      }
      // doing next of tail to null
      if(headFirst!=NULL){
        headFirst->next=NULL;
      }
      return head;
}

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


//       prev cur  next 
//      null   |   |
//  orignal     1=>2=>3=>4=>5
///             1<=2<=3<=4<=5
//  reversed    5=>4=>3=>2=>1

// current->next=prev
// prev=current
// current=next;
//next=next->next //check for null pointer

node* LinkedList::IterativeReverse(node *head){
  node *prev=NULL;
  node *current=head;
  node *Next=current->next;

  if(head==NULL){
    return head;
  }

  while(current!=NULL){
    current->next=prev;
    prev=current;
    current=Next;
    if(Next!=NULL){
         Next=Next->next;
    }
  }
  head=prev;
  return head;

}

node* LinkedList::RecursionReverse(node *current){
  if(current->next==NULL){
    head=current;
    return current;
  }
  // in case of using tail just use tail instead of temp without equating it with recursive call
  node *temp=RecursionReverse(current->next);
  temp->next=current;
  current->next=NULL;
  return current;
}

node* LinkedList::GetMidNode(){
  node *fast=head;
  node *slow=head;

  while(fast!=NULL && fast->next!=NULL){
    fast=fast->next->next;
    slow=slow->next;
  }
  return slow;
}
node* LinkedList::getNode(int index){
    node* targetprev=new node();
   targetprev= head;
      for(int i=1; i<index; i++){
        targetprev=targetprev->next;
     
      }
      return targetprev;
}

void LinkedList::display(){

    if(head==NULL){
     cout<<"LinkedList is Empty. Nothing to display :( "<<endl;
     return;
    }

   for(node* temp=head; temp!=NULL; temp=temp->next){
     cout<<temp->val<<" ->";
   }
   cout<<"END\n";
   cout<<endl;

}

// node* LinkedList::createnewNode(int info){
//  node* Node=new node();
//  Node=createnewNode(info);
//  cout<<Node->val;
//  return Node;
// }

 node* LinkedList:: createnewNode(int newinfo){
        node *newNode=new node();
        newNode->val=newinfo;
        newNode->next=NULL;
        return newNode;
    }

void LinkedList::insertFirst(int info ){

       node *temp =new node();
       temp=createnewNode( info);
       if(head==NULL){
          size++;
        tail=head=temp;
        cout<<head->val<<endl;
        return;
       }
       temp->next=head;
       head=temp;
       size++;

}

void LinkedList::insertLast(int info ){
       node* temp=new node();
       temp=createnewNode(info);
       if(head==NULL){
          size++;
        tail=head=temp;
       }
       tail->next=temp;
       tail=temp;
       size++;

}

int LinkedList::deleteBegin(){
       
       if(head==NULL){
           cout<<"LinkedList is Empty. Nothing to delete :( "<<endl;
           return -1;
         }

       node* temp  =new node();
       temp=head;
       int begin=temp->val;
        if(head==tail){
           head=tail=NULL;
         size--;
       delete temp;
       return begin;
        }
        head=head->next;
        size--;
       delete temp;
       return begin;

}

int LinkedList::deleteAtEnd(){
      if(head==NULL){
           cout<<"LinkedList is Empty. Nothing to delete :( "<<endl;
           return -1;
      }
       node* temp;
       temp=tail;
       int begin=temp->val;
        if(head==tail){
           head=tail=NULL;
             size--;
        delete temp;
       return begin;
        }
// node* t;
// for(t=head; t->next->next!=NULL; t=t->next){
     
// }
// tail=t;

   tail=getPrevious(size-2);
       cout<<"tail "<<tail->val<<endl;
   tail->next=NULL;
 
       size--;
       delete temp;
       return begin;
}

node* LinkedList::InsertRecursive(int val,int index,node* current){
  if(index==0){
     node* Node  =new node();
     Node=createnewNode(val);
     Node->next=current;
     return Node;
  }

  current->next=InsertRecursive(val,index-1,current->next);
  return current;
     
}
node* LinkedList::RemoveDuplicates(){
  // for sortted linked List => duplicate is just after the element
  node* temp=head;
  // cannot use for loop instead of while because for loop also iterates when if condition got true and we removed the duplicate element and now at the new element(for loop do temp=temp->next without checking for duplicates)
  while(temp->next!=NULL){
      if(temp->val==temp->next->val){
      temp->next=temp->next->next;
    }
    else{
      temp=temp->next;
    }
  }
 
  tail=temp;
  tail->next=NULL;
  return head;
}
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


int LinkedList::CountCycleLength(node *head){
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
// (first pointer)
//    f---------------------l (length  of cycle times from 2nd element)
//   ---------k-----        |
//    1 => 2 => 3 => 4 =>5  |
//                /  |   |  |
//                |  |   6  | <- s (second pointer)
//                |  8   /
//           K times  \ 7  /
//                \       /
//                 ______

//THOUGHT PROCESS

//  we are using  two pointers approach basically one of the case of fast and slow pointer
// for finding start of the cycle we should make sure f and s meet at start but it is not possible everytime
// let second pointer lie over there(marked)
// make sure when moving ahead one by one both meet at start
// next thing is where i should put my pointer so that both f from start and s to start distance will be k
// since i want to complete the cycle to reach start
// then lets try to move inside the cycle length of cycle times from 1st position (so disatnce upto s from 2nd element is l marked above)
//  distance from start to s is(l-k) (beacuse from f to start distance is k)
// remaining distance in loop from s to start is (l-(l-k)) which is k

// STEPS TO CODE
// find length of the cycle
// move s ahead by length of the cycle times
// move s and f one by one it will meet at start

node* LinkedList::findStartCycle(){
  int length=0;
  node *fast=head;
  node *slow=head;
  while(fast->next!=NULL && fast!= NULL){
    fast=fast->next->next;
    slow=slow->next;
     if(fast==slow){
       length=CountCycleLength(slow);
       break;
    }

  }
  if(length==0){
    return NULL;
  }
  node *f=head;
  node *s=head;
  while(length>0){
    s=s->next;
    length--;
  }
  // keep moving both forward and they will meet at cycle start
  while(f!=s){
    f=f->next;
    s=s->next;
  }
  return s; // return any they both are pointing to the same node
  
}

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
void LinkedList:: BubleSort(){
  BubbleSortHelper(size-1, 0);
}
// node* LinkedList:: Merge(LinkedList l2){
//     LinkedList ans;
//     node* head1=head;
//     node* head2=l2.head;
//     cout<<"Hello world : "<<endl;
//     while(head1!=NULL && head2!=NULL){
//       cout<<"head 1 "<<head1->val<<endl;
//       cout<<"head 2 "<<head2->val<<endl;
//       if(head1->val<head2->val){
//         ans.insertLast(head1->val);
//         head1=head1->next;
//       }
//       else if(head1->val==head2->val){
//         ans.insertLast(head1->val);
//           head1=head1->next;
//            head2=head2->next;
//       }
//       else{
//           ans.insertLast(head2->val);
//         head2=head2->next;
//       }
      
//     }
//     while(head1!=NULL){
//        cout<<"head 1 "<<head1->val<<endl;
//       ans.insertLast(head1->val);
//        head1=head1->next;
//     }
//      while(head2!=NULL){
//       cout<<"head 2 "<<head2->val<<endl;
//       ans.insertLast(head2->val);
//        head2=head2->next;
//     }
//     ans.display();
// //     cout<<"erge"<<endl;
//  return ans.head;

// }
// void LinkedList:: BubleSort(){
//   BubbleSortHelper(size-1, 0);
// }

void LinkedList::BubbleSortHelper(int row,int col){
//   if(row==0){
//      return ;
//   }






//   if(col<row){
//     if(first->val>second->val){

  //   node *first=getPrevious(col);
//   node *second=getPrevious(col+1);
      
//        if(first==head){
//          head=second;
//          first->next=second->next;
//          second->next=first;
      
//        }
//        else if(second==tail){
//         node *prev=getPrevious(col-1);
//         prev->next=second;
//         tail=first;
//         first->next=NULL;
//         second->next=first;

//        }
//        else{
//         node *prev=getPrevious(col-1);
//         prev->next=second;
//         first->next=second->next;
//         second->next=first;
//        }
//   }
//        BubleSortHelper(row, col+1);
      
// }
//   else{
//     BubleSortHelper(row-1,0);
//   }
   
        if (row == 0) {
            return;
        }

        if (col < row) {
            node *first = getPrevious(col);
            node *second = getPrevious(col + 1);

            if (first->val > second->val) {
                // swap
                if (first == head) {
                    head = second;
                    first->next = second->next;
                    second->next = first;
                } else if (second == tail) {
                  cout<<"at end";
                    node *prev = getPrevious(col - 1);
                    prev->next = second;
                    tail = first;
                    first->next = NULL;
                    second->next = first;
                } else {
                    node *prev = getPrevious(col - 1);
                    prev->next = second;
                    first->next = second->next;
                    second->next = first;
                }
            }
            cout<<"row "<<row<<" col"<<col<<endl;
            BubbleSortHelper(row, col + 1);
        } else {
             BubbleSortHelper(row - 1, 0);
        }
}


int main(){
 
  LinkedList l,l2,l1,l3;
  LinkedList ans;
  //  l.InsertRecursive(80,1,l.head);
//   l.insertFirst(10);
//   l.insertLast(20);
//   l.insertFirst(30);
//   l.insertLast(40);
//   l.InsertRecursive(80,1,l.head);
//   l.display();
//   l.deleteBegin();
//   l.display();
//   l.deleteAtEnd();
//   l.display();
//   l.InsertRecursive(80,1,l.head);
//   l.insertLast(20);
//   l.display();
//   l.insertLast(20);
//   l.display();
//   l.RemoveDuplicates();
//   cout<<"Removing";
//   l.display();
 
 l1.insertLast(10);
  l1.insertLast(20);
  l1.insertLast(30);
  l1.insertLast(70);
  l1.display();
  l1.AddatIndex(2,4);
// cout<<l1.getValue(3)<<endl;
//  l2.insertLast(10);
//   l2.insertLast(50);
//   l2.insertLast(60);
//   l2.insertLast(70);
//   l2.display();
// node *head;

//  head=l1.Merge(l2);
//  l1.insertLast(70);
//   l1.insertLast(30);
//   l1.insertLast(20);
//   l1.insertLast(10);
  // l1.display();

//  l2.insertLast(10);
//   l2.insertLast(50);
//   l2.insertLast(60);
//   l2.insertLast(70);
//   l2.display();
// node *head;

//  head=l1.Merge(l2);
//  cout<<"Merged Linked list : "<<endl;
//  for(node *temp=head;temp!= NULL; temp=temp->next){
//   cout<<temp->val<<" => ";
//  }
//  cout<<"NULL "<<endl;
//  LinkedList l4

  // l1.display();

// for(int i=11; i>0; i--){
//   l3.insertLast(i);
// }
// l3.display();
// node *temp=l3.GetMidNode();
// cout<<temp->val<<endl;
// l3.BubleSort();
// l3.RecursionReverse(l3.head);
// l3.IterativeReverse();
  // l3.PartReverse(3,7);

  //  l2.insertLast(10);
  // l2.insertLast(20);
  // l2.insertLast(30);
  // l2.insertLast(40);
  // l2.insertLast(30);
  // l2.insertLast(20);
  // l2.insertLast(10);
  // l2.display();
  // cout<<"pallindrome :"<<l2.Pallindrome(l2.head)<<endl;
  // l3.Reorder(l3.head);
//   l3.ReverseAlternativeKGroup(3);
// l3.display();

  return 0;
}
