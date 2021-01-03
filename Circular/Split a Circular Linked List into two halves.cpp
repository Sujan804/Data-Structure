#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
};
void splitList(Node *head, Node **head1_ref,
                           Node **head2_ref)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;

    if(head == NULL)
        return;

    /* If there are odd nodes in the circular list then
       fast_ptr->next becomes head and for even nodes
       fast_ptr->next->next becomes head */
    while(fast_ptr->next != head &&
          fast_ptr->next->next != head)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    /* If there are even elements in list
       then move fast_ptr */
    if(fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;

    /* Set the head pointer of first half */
    *head1_ref = head;

    /* Set the head pointer of second half */
    if(head->next != head)
        *head2_ref = slow_ptr->next;

    /* Make second half circular */
    fast_ptr->next = slow_ptr->next;

    /* Make first half circular */
    slow_ptr->next = head;
}
void push(Node **head_ref, int data){
    Node *ptr = new Node();
    Node *temp = *head_ref;
    ptr->data = data;
    ptr->next = *head_ref;
    if(*head_ref != NULL){

        while(temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr;

    }
    else{
        ptr->next = ptr;
    }
    *head_ref = ptr;
}
void printList(Node *head){
    Node *temp = head;
    if(head != NULL){
        cout<<endl;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp != head);
    }


}
int main(){
    int list_size,i;
    Node *head = NULL;
    Node *head1 = NULL;
    Node *head2 = NULL;

    push(&head, 23);
    push(&head, 24);
    push(&head, 25);
    push(&head, 26);
    push(&head, 27);

    printList(head);

     splitList(head, &head1, &head2);

    cout << "\nFirst Circular Linked List";
    printList(head1);

    cout << "\nSecond Circular Linked List";
    printList(head2);
    return 0;

}
