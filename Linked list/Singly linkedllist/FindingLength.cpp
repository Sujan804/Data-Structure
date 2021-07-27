#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    
};
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
void push(Node** head_ref,int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void printList(Node* n){
    while(n!=NULL){
        cout<<n->data<<' ';
        n = n->next;
    }
    cout<<endl;
}
int length(Node* n){
    int cnt(0);
    while(n!=0){
        cnt++;
        n = n->next;
    }
    return cnt;
}
int getCount(Node* n){
    if(n==NULL){
        return 0;
    }else{
        return 1 + getCount(n->next);  
    }
}
bool search(Node* n, int key){
    while(n!=NULL){
        if(n->data == key){
            return true;
        }
        n = n->next;
    }
    return false;
}
bool recursiveSearch(Node *n,int key){
    if(n==NULL){
        return false;
    }else{
       if(n->data==key){
           return true;
       }
       recursiveSearch(n->next,key);
    }
}
///Getting Nth Node
int getNth(Node* n , int index){
    int cnt(0);
    while(n!=NULL){
        if(cnt==index){
            return n->data;
        }
        cnt++;
        n = n->next;
    }
    assert(0);
}
int getNthR(Node* head, int index){
    if(head==NULL){
        return -1;
    }
    if(index==0){
        return head->data;
    }
    getNthR(head->next,index-1);
}
void printNthFromLast(Node* head, int n)
{
    int len = 0, i;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    if (len < n)
        return;
 
    temp = head;
    for (i = 1; i < len - n + 1; i++)
        temp = temp->next;
    cout << temp->data; 
    return;
}
void getNthFromLR(Node* n,int index){
    static int i=0;
    if(n==NULL){
        return ;
    }
    getNthFromLR(n->next, index);
    if(++i==index){
        cout<<n->data<<endl;
    }
}
void printMiddle(Node* head){
    Node* slow_ptr = head;
    Node* fast_ptr = head;
    if(head!=NULL){
        while(fast_ptr!=NULL && fast_ptr->next!=NULL){
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        cout<<"The middle element is "<<slow_ptr->data<<endl;
    }
   
}
void printMiddleCount(Node* head){
    int cnt(0);
    Node* middle = head;
    while(head!=NULL){
        if(cnt&1)
            middle = middle->next;
        head = head->next;
        cnt++;

    }
    if(middle!=NULL)
        cout<<"Middle element is :"<<middle->data<<" according to account"<<endl;
}
// bool detectLoop(Node* head){
//     unordered_set<Node*> s;
//     while (head!=NULL)
//     {
//         if(s.find(head)!=s.end())
//             return true;
//         s.insert(head);
//         head = head->next;
//     }
//     return false;
    
// }
int main(){
    Node* head = NULL;
    push(&head,56);
    push(&head,57);
    push(&head,58);
    push(&head,10);
    append(&head,11);
    append(&head,12);
    append(&head,13);
    //head->next->next->next->next = head;
    printList(head);
    cout<<length(head)<<endl;
    cout<<getCount(head)<<endl;
    //cout<<search(head,57)? "Found !":"Not Found !"<<endl;
    if(recursiveSearch(head,57)){
        cout<<"Found !"<<endl;
    }else{
        cout<<"Not Found !"<<endl;
    }
    cout<<getNth(head,2)<<endl;
    cout<<getNthR(head,2)<<endl;
    printNthFromLast(head,1);
    printMiddle(head);
    printMiddleCount(head);
    // if(detectLoop(head))
    //     cout<<"Loop found!"<<endl;
    // else
    //     cout<<"Loop not found!"<<endl;

}