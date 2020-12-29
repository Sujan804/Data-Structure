#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
};
void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void deleteNode(Node** head_ref, int key){
    Node* temp = *head_ref;
    Node* prev = NULL;
    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        delete temp;
        return;
    }
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"Key not found !"<<endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
    return;


}
void deletelist(Node** head_ref){
    Node* current = *head_ref;
    Node* next = NULL;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
    cout<<"List is deleted"<<endl;
}
void printlist(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;

}
void length(Node* head){
    int cnt =0;
    while(head != NULL){
        cnt++;
        head = head->next;
    }
    cout<<"Length of the link list is: " <<cnt<<endl;

}
void Search(Node* head,int key){
    Node* current = head;
    bool res = false;
    while(current != NULL){
        if(current->data == key){
            res = true;
            break;
        }
        current = current->next;
    }
    res? cout<<"YES"<<endl: cout<<"NO"<<endl;
    return;


}
int getNth(Node* head , int index){
    Node* current = head;
    int cnt = 1;
    while(current != NULL){
        if(cnt==index){
            cout<<current->data<<endl;
            return current->data;
            break;
        }
        cnt++;
        current = current->next;
    }
    assert(0);

}
int main(){
    Node* head = NULL;
    push(&head,12);
    push(&head,34);
    push(&head,45);
    getNth(head,1);
    printlist(head);
    length(head);
    Search(head,45);
    Search(head,44);
    deleteNode(&head,12);
    deleteNode(&head,120);
    printlist(head);
    length(head);
    deletelist(&head);
    printlist(head);
    length(head);

}
