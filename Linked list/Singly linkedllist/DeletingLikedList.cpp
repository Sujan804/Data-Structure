#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;

};
void push(Node** head_ref,int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    *head_ref = new_node;

}
void deleteList(Node** head_ref){
    Node* current = *head_ref;
    Node* Next = NULL;
    while(current!=NULL){
        Next = current->next;
        free(current);
        current = Next;
    }
    *head_ref = NULL;
    cout<<"List is deleted!"<<endl;
    return;
}                            
void printList(Node* n){
    while(n!=NULL){
        cout<<n->data<<' ';
        n= n->next;
    }
    cout<<endl;
}
int main(){
    Node* head = NULL;
    push(&head,10);
    push(&head,11);
    push(&head,12);
    printList(head);
    deleteList(&head);
    printList(head);

}