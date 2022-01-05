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
     void RemoveDup_Unsortted(){
        node *temp=head;
        node *prev=head;
        node *current=head->next;
        while(temp->next!=NULL){

            if(temp->info==current->info){
                if(current->next==NULL){
                temp=temp->next;
                if(temp){
                current=temp->next;
                }
                prev->next=NULL;
                prev=temp;
                }
                else{
                    current=current->next;
                     prev->next=current;
                }
            }
            else if(current->next==NULL){
                temp=temp->next;
                current=temp->next;
                prev=temp;
            }
            else if(current->info!=temp->info){
                prev=current;
                current=current->next;
            }
       }

    }
    void duplicate2apraoch(){
        node *temp=head;
        node *temp2=NULL;
        node *temp1=NULL;
        while(temp!=NULL && temp->next!=NULL){
            temp1=temp;
            while(temp1->next!=NULL ){
                if(temp1->next->info==temp->info){
                 temp1->next=temp1->next->next;

                }
                else{
                     temp1=temp1->next;
                }

            }
            temp=temp->next;
        }

    }
    void RemoveDuplicatesSortted(){
        node *temp=head;
         node *current=head->next;
        while(temp->next!=NULL){
          if(current->info==temp->info){
              node *del=current;
              if(current->next==NULL){ // handling the case when duplicate is at the end of the linked list
                temp->next=NULL;
                current=NULL;
              }
              else{
              current=current->next; // moving current 1node ahead skipping in between duplicated node
              temp->next=current;
              }
              delete(del);

          }
          else{
              temp=temp->next; // moving temp ahead when no duplicates of node exsist
              current=temp->next; // current having the value next to temp
              temp->next=current;
          }
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

};
int main(){
     singlyLinkedList l1,l2,l3;
     int n,in, choice,i;
     node *newnode;

    char ch='y';
    while(ch=='y'||ch=='Y')
    {
        cout<<"MENU....\n";
        cout<<"0.Create new LInklist"<<endl;
        cout<<"1. Remove Duplicates from sortted array "<<endl;
        cout<<"2. Remove Duplicates from unsortted array "<<endl;
        cout<<"3. Remove Duplicates from unsortted array SECOND APPROACH "<<endl;
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

            case 1: cout<<"Orignal linked list : "<<endl;
                     l1.display();
                     l1.RemoveDuplicatesSortted();
                     cout<<"After removal ";
                     l1.display();
                     break;
            case 2: cout<<"Orignal linked list : "<<endl;
                     l1.display();
                     l1.RemoveDup_Unsortted();
                     cout<<"After removal ";
                     l1.display();
                     break;
            case 3: cout<<"Orignal linked list : "<<endl;
                     l1.display();
                     l1.duplicate2apraoch();
                     cout<<"After removal ";
                     l1.display();
                     break;
            case 4:  l1.display();
                     break;
            default: cout<<"You entered a wrong choice !! "<<endl;
    }
     cout<<"Do you want to continue\n";
        cin>>ch;
        cout<<endl;
    }
    return 0;
    }
