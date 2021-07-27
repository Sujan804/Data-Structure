#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
void push(Node **head_ref,int data){
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
}

void PairWiseSwap(Node *head){
    Node *temp = head;
    while(temp!=NULL&&temp->next!=NULL){
        swap(temp->data,temp->next->data);
        temp = temp->next->next;
    }
}
void printList(Node *n){
    while(n!=NULL){
        cout<<n->data<<' ';
        n = n->next;
    }
    cout<<endl;
    return ;
}
int main(){
    Node *head = NULL;
    //push(&head,11);
    for(int i=12;i<=20;i++)
        append(&head,i);
    printList(head);
    PairWiseSwap(head);
    printList(head);

}