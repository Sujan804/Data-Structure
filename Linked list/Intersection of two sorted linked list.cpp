#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
};
void push(Node **head_ref,int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;

}
void printList(Node *head){
    while(head!=NULL){
        cout<<head->data<<endl;
        head = head->next;

    }
    return;
}
Node* sortedIntersect(Node* a , Node* b){
    Node dummy ;
    Node* tail = &dummy;
    dummy.next = NULL;
    while(a != NULL && b != NULL){
        if(a->data == b->data){
                push(&tail->next,a->data);
                tail = tail->next;
                a = a->next;
                b = b->next;
        }
        else if(a->data < b->data)
            a = a->next;
        else
            b = b->next;
    }
    return dummy.next;
}


int main(){
    Node* a = NULL;
    Node* b = NULL;
    Node* intersect = NULL;
    push(&a, 6);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);

    /* Let us create the second sorted linked list
   Created linked list will be 2->4->6->8 */
    push(&b, 8);
    push(&b, 6);
    push(&b, 4);
    push(&b, 2);

    /* Find the intersection two linked lists */
    intersect = sortedIntersect(a, b);

    printf("\n Linked list containing common items of a & b \n");
    printList(intersect);

    getchar();
}
