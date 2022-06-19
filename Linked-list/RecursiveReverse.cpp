# include <iostream>
using namespace std;

// Note copy the LinkedList and node class to run

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
// In case using tail

node* LinkedList::RecursionReverse(node *current){
  if(current->next==NULL){
    head=current;
    return current;
  }

  RecursionReverse(current->next);
  tail->next=current;
  current->next=NULL;
  return current;
}
