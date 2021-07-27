#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
};
void append(Node** head_ref, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    Node* last_node = *head_ref;
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
void deleteDuplicate(Node* start)
{
    Node *ptr1, *ptr2, *dup;
    ptr1 = start;
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->data == ptr2->next->data) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
int main(){
    Node* head = NULL;
    int n;
    cout<<"Enter the range:"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        append(&head,i);
    }
    for(int i=1;i<=n;i++){
        if(!(i&1))append(&head,i);
    }
    printList(head);
    deleteDuplicate(head);
    printList(head);

}