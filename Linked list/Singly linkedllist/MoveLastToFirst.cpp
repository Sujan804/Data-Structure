#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
void append(Node **head_ref,int data){
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next =NULL;
    if(*head_ref==NULL){
        *head_ref = new_node;
        return;
    }
    Node *last_node = *head_ref ;
    while(last_node->next!=NULL){
        last_node = last_node->next;
    }
    last_node->next = new_node;
}
void moveLast(Node **head_ref){
    Node *last_node = (*head_ref);
    Node *prev_node = (*head_ref);
    if(*head_ref==NULL || (*head_ref)->next==NULL)
        return;
    while(last_node->next!=NULL){
        prev_node = last_node;
        last_node = last_node->next;
    }
    Node *temp_node = last_node;
    prev_node->next = NULL;
    free(last_node);
    temp_node->next = (*head_ref);
    *head_ref = temp_node;
    return;
}
void printList(Node *n){
    while(n!=NULL){
        cout<<n->data<<' ';
        n = n->next;
    }
    cout<<endl;
    return;
}
int main(){
    Node *head  = NULL;
    for(int i=11;i<=20;i++)
        append(&head,i);
    printList(head);
    moveLast(&head);
    printList(head);
}