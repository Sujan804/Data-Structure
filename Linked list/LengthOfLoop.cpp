#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    int flag;
};
void push(struct Node** head_ref,int new_data){
    struct Node* new_node = new Node;
    new_node->data = new_data;
    new_node->flag = 0;
    new_node->next = *head_ref;
    *head_ref = new_node;

}
bool detectLoop( struct Node* h){
    while(h != NULL){
        if(h->flag==1){
            return true;
        }
        h->flag = 1;
        h = h->next;


    }
    return false;
}
int lenOfLoop(struct Node* h){
    int cnt = 0;
    while(h!= NULL){
        if(h->flag==1){
            return cnt;
        }
        cnt++;
        h->flag ==1;
        h = h->next;
    }
}
void print(struct Node* head){
    while(head != NULL){
        cout<<head->data<<endl;
        head = head->next;
    }
}
int main(){
   /* struct Node* head = NULL;
    push(&head,12);
    push(&head,13);
    push(&head,14);
    push(&head,15);
    push(&head,12);*/
    struct Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    /* Create a loop for testing */
    head->next->next->next->next = head;
    cout<<lenOfLoop(head)<<endl;
    //print(head);
    if(detectLoop(head)){
        cout<<"Find Loop"<<endl;
    }
    else
        cout<<"Don't find"<<endl;



}
