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
void append(Node **head_ref, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    if(*head_ref==NULL){
        *head_ref = new_node;
        return;
    }
    Node *last_node = (*head_ref);
    while(last_node->next!=NULL){
        last_node = last_node->next;
    }
    last_node->next = new_node;
}
void printList(Node* n){
    while(n!=NULL){
        cout<<n->data<<' ';
        n = n->next;
    }
    cout<<endl;
}
void deleteDuplicate(Node* head){
    Node* current = head;
    Node* next_next;
    if(current==NULL){
        return ;
    }
    while(current->next!=NULL){
        if(current->data==current->next->data){
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }else{
            current = current->next;
        }
    }
}
int main(){
    Node* head = NULL;
    int n;
    cout<<"Enter the range:"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        append(&head,i);
        if(i&1)append(&head,i);
    }
    printList(head);
    deleteDuplicate(head);
    printList(head);
    return 0;

}