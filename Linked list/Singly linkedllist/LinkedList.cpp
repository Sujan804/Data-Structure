#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
};
void printList(Node* n){
    while(n!=NULL){
        cout<<n->data<<endl;
        n = n->next;
    }

}
int main(){
    Node* head = NULL;
    Node* first = NULL;
    Node* second = NULL;
    head = new Node();
    first = new Node();
    second = new Node();
    head->next = first;
    first->next = second;
    second->next = NULL;

    head->data = 1;
    first->data = 2;
    second->data = 3;
    printList(head);
}