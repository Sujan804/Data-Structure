#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
};
void append(Node **head_ref, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    Node *last_node = (*head_ref);
    while(last_node->next!=NULL){
        last_node = last_node->next;
    }
    last_node->next = new_node;
}
void push(Node **head_ref, int data){
    Node* new_node= new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
}
void deleteNode(Node** head_ref, int key){
    Node* temp =  *head_ref;
    Node* prev = NULL;
    if(temp!=NULL&&temp->data==key){
        *head_ref = temp->next;
        delete temp;
        return;
    }
    while(temp!=NULL&&temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL){
        return;
    }
    prev->next = temp->next;
    delete temp;
}
void deleteNodeByPos(Node** head_ref, int pos){
    if(*head_ref == NULL){
        return;
    }
    Node* temp = *head_ref;
    if(pos==0){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for(int i=0;i<pos-1&&temp!=NULL;i++){
        temp = temp->next;
    }
    if(temp==NULL || temp->next==NULL){
        return;
    }
   Node* Next = temp->next->next;
   free(temp->next);
   temp->next = Next;
   return;
   
}
void printList(Node *n){
    while(n!=NULL){
        cout<<n->data<<' ';
        n = n->next;
    }
    cout<<endl;
}
int main(){
    Node* head = NULL;
    push(&head,10);
    append(&head,11);
    append(&head,12);
    append(&head,13);
    printList(head);
    deleteNodeByPos(&head,0);
    printList(head);
    
}