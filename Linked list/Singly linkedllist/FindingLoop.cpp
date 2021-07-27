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
    Node *last_node = (*head_ref);
    while(last_node->next!=NULL){
        last_node = last_node->next;
    }
    last_node->next = new_node;
}
void printList(Node *n){
    while(n!=NULL){
        cout<<n->data<<' ';
        n = n->next;
    }
    cout<<endl;
}
int countLoop(Node* loop){
    int cnt=1;
    Node* temp = loop;
    cout<<temp->data<<' ';
    while(temp->next != loop){
        cnt++;
        temp = temp->next;
        cout<<temp->data<<' ';
    }
    cout<<endl;
    return cnt;

}
int countNodesinLoop(Node *list){
    Node* slow_ptr = list;
    Node* fast_ptr = list;
    while(slow_ptr!=NULL&&fast_ptr!=NULL&&fast_ptr->next!=NULL){
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
        if(slow_ptr==fast_ptr){
            return countLoop(slow_ptr);
        }
    }
    return 0;
}

int main(){
    Node *head = NULL;
    push(&head,0);
    append(&head,1);
    append(&head,2);
    append(&head,3);
    head->next->next->next->next = head;
    //printList(head);
    cout<<countNodesinLoop(head)<<endl;

}