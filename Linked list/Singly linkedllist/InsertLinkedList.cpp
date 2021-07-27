#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
};
void push(Node **head_ref, int data){
    Node* new_node= new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
}
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
void insertAfter(Node* prev_node, int data){
    if(prev_node==NULL){
        cout<<"Previous node can't be NULL"<<endl;
        return;
    }
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;

}
void printList(Node *n){
    while(n!=NULL){
        cout<<n->data<<' ';
        n = n->next;
    }
    cout<<endl;
}
int main(){
    Node *head = NULL;
    push(&head,11);
    printList(head);
    push(&head,12);
    printList(head);
    append(&head,13);
    printList(head);
    insertAfter(head->next,14);
    printList(head);

}