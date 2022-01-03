# include <iostream>
using namespace std;
struct node{
    int info;
    node *next;
};
class singlyLinkedList{
    public:
    node *head;
    singlyLinkedList(){
        head=NULL;
    }
    node* createnewNode(int newinfo){
        node *newNode=new node();
        newNode->info=newinfo;
        newNode->next=NULL;
        return newNode;
    }
    void createNewList(node *newNode){
       newNode->next=head;
       head=newNode;
    }
    void addatEnd(node *newnode){
        node *temp=NULL;
        if(head==NULL){
            head=newnode;
        }
        else{
        for(temp=head; temp->next!=NULL; temp=temp->next){

        }
        temp->next=newnode;
        }
      
    }
    void addAtBeg(node *newnode){
        if(head==NULL)
        {
            head=NULL;
        }
        else{
           newnode->next=head;
           head=newnode;
        }
    }
    void display(){
        node *temp=NULL;
        if(head==NULL){
            cout<<"YOUR LINKED LIST IS EMPTY"<<endl;
        }
        else{
           cout<<"SINGLY LINKED LIST : "<<endl;
           for(temp=head; temp!=NULL; temp=temp->next){
            cout<<temp->info<<"  ";
        }
        cout<<endl;
        }
      
    }
    int length(){
        int count=0;
        node *temp=NULL;
        if(head==NULL){
            return 0;
        }
        else{
            for(temp=head; temp!=NULL; temp=temp->next){
                count++;
            }
            return count;
        }

    }
    void AddAti(node *newNode, int i){
        int count =0;
        if(i<=0 || i>length()){
            cout<<"You enetered a wrong position"<<endl;
            return;
        }
        else{
             if(head==NULL || i==1){
                newNode->next=head;
               head=newNode;
        }
        else{
            node *temp=NULL;
             count++;
             for(temp=head; temp!=NULL; temp=temp->next)
             {
                 if(count==i-1){
                     newNode->next=temp->next;
                     temp->next=newNode;
                     return;
                 }
             }

        }
        }
    }
    void addAfter(node *newnode, int after){
        node *temp=NULL;
        if(head==NULL ){
            cout<<"Your Linked list is empty"<<endl;
        }
        else{
         for(temp=head; temp!=NULL; temp=temp->next){
            if(temp->info==after){
                newnode->next=temp->next;
                temp->next=newnode;
                return;
            }
            cout<<"SORRY!! node "<<after<<" is not present in the linked list"<<endl;
        }
        }
       
    }
    void addBefore(node *newnode , int before){
        node *temp=NULL;
        if(head==NULL){
            cout<<"Your Linked list is empty "<<endl;
            return;
        }
        else if(before==head->info){
            newnode->next=head;
            head=newnode;
            return;
        }
        else{
          for (temp=head; temp->next!=NULL; temp=temp->next)
          {
              if(temp->next->info==before){
                  newnode->next=temp->next;
                  temp->next=newnode;
                  return;
              }
          }
           cout<<"SORRY!! node "<<before<<" is not present in the linked list"<<endl;
          
        }
    }

    void search(int searchingNode){
        int count =0;
        node *temp=NULL;
        if(head==NULL){
            cout<<"Your Linked list is empty "<<endl;
            return;
        }
        else{
           for(temp=head; temp!=NULL; temp=temp->next){
            count++;
            if(temp->info==searchingNode){
              cout<<"Node having info:"<<searchingNode<<" is "<<count<<" th node"<<endl;
              return;
            }
        }
       cout<<"SORRY!! node "<<searchingNode<<" is not present in the linked list"<<endl; 
        }
       
    }

    int deleteAtEnd(){
        node *temp=NULL;
        node *del;
        int d;
         if(head==NULL){
            cout<<"Your Linked list is empty "<<endl;
            return -1;
        }
        else if(length()==1){
             del=head;
             head=NULL;
        }
        else{
         for(temp=head; temp->next->next!=NULL; temp=temp->next ){
         }
         del=temp->next;
         temp->next=NULL;
        
        }
             d=del->info;
             delete(del);
             return d;
        
    }
    int deleteBegin(){
        node *temp=NULL;
        node *del;
        int d;
         if(head==NULL){
            cout<<"Your Linked list is empty "<<endl;
            return -1;
        }
        else if(length()==1){
             del=head;
             head=NULL;
        }
        else{
            del=head;
            head=head->next;
            
        }
        d=del->info;
        delete(del);
        return d;
    }
    int deleteAtI(int i){
        int count=0;
        node *temp=NULL;
        node *del;
        int d;
        if(i>1 && i<=length()){
           if(head==NULL){
            cout<<"Your Linked list is empty "<<endl;
            return -1;
        }
        else if( i==1){
             del=head;
             head=head->next;
        }
        else{
            count++;
            for(temp=head; temp->next!=NULL; temp=temp->next){
                if(i==count-1){
                    del=temp->next;
                    temp=temp->next;
                }
            }
        }
        d=del->info;
        delete(del);
        return d;
        }
         
    }
       
    
};
int main(){
     singlyLinkedList l1,l2;
     int n,in, choice,i;
     node *newnode;
    
    char ch='y';
    while(ch=='y'||ch=='Y')
    {
        cout<<"MENU....\n";
        cout<<"0.Create new LInklist"<<endl;
        cout<<"1.ADD at END\n";
        cout<<"2.ADD after given NODE\n";
        cout<<"3.ADD before given NODE\n";
        cout<<"4.DELETION at End\n";
        cout<<"5.Count Total number of NODES\n";
        cout<<"6.Display\n";
        cout<<"7.ADD at beginning\n";
        cout<<"8.ADD at ith position\n";
        cout<<"9.Remove from Beginning\n";
        cout<<"10.Remove from ith position\n";
        cout<<"11.Search for an element x\n";
        cout<<"12.Concatenate\n";
        cout<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case 0:   cout<<"Enter the no nodes you want in  linked list : ";
                      cin>>n;
                      for(int i=n; i>0; i--){
                      cout<<"Enter the info part of node "<<i<<" : ";
                      cin>>in;
                      newnode=l1.createnewNode(in);
                      l1.createNewList(newnode);
                      }
                      l1.display();
                      break;
            case 1:  cout<<"Enter the info part of the node : ";
                     cin>>in;
                     newnode=l1.createnewNode(in);
                     l1.addatEnd(newnode);
                     l1.display();
                     break;
            case 2:  cout<<"Enter the info part of the node : ";
                     cin>>in; 
                     newnode=l1.createnewNode(in);
                     cout<<"Enter the info part of the node after which you want to add : ";
                     cin>>i;
                     l1.addAfter(newnode,i);
                     l1.display();
                     break;
            case 3:  cout<<"Enter the info part of the node : ";
                     cin>>in; 
                     newnode=l1.createnewNode(in);
                     cout<<"Enter the info part of the node before which you want to add : ";
                     cin>>i;
                     l1.addBefore(newnode,i);
                     l1.display();
                     break;
            case 4:  i=l1.deleteAtEnd();
                     if(i!=-1){
                         cout<<i<<" has been deleted"<<endl;
                         l1.display();
                     }
                     break;
                    
            case 5:  i=l1.length();
                     cout<<"Total no of nodes in the Linked-List is : "<<i<<endl;
                     break;

            case 6:  l1.display();
                     break;
            case 7:  cout<<"Enter the info part of the node : ";
                     cin>>in;
                     newnode=l1.createnewNode(in);
                     l1.addAtBeg(newnode);
                     l1.display();
                     break;
            case 8: cout<<"Enter the info part of the node : ";
                     cin>>in;
                     newnode=l1.createnewNode(in);
                     cout<<"Enter the position at which you want to add : ";
                     cin>>i;
                     l1.AddAti(newnode,i);
                     l1.display();
                     break;
            case 9:  i=l1.deleteBegin();
                     if(i!=-1){
                         cout<<i<<" has been deleted"<<endl;
                         l1.display();
                     }
                     break;
            case 10: cout<<"Enter the position of node to be deleted ";
                     cin>>i;
                     in=l1.deleteAtI(i);
                     if(i!=-1){
                         cout<<in<<" has been deleted"<<endl;
                         l1.display();
                     }
                     break;
            case 11: cout<<"Enter the info part of the node : ";
                     cin>>in;
                     l1.search(in);
                     break;
        } 
         cout<<"Do you want to continue\n";
        cin>>ch;
        cout<<endl;
        }
        return 0;
}