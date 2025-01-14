#include <iostream>

using namespace std;

struct Node{

    int val;
    Node* next;
    Node* prev;

    Node(){ val = 0; next = nullptr; prev = nullptr; }
    Node(int v){ val = v; next = nullptr; prev = nullptr; }
    Node(int v, Node* n){ val = v; next = n; prev = nullptr; }
    Node(int v, Node* n, Node* p){ val = v; next = n; prev = p; }

};

void printList(Node* list){
    Node* current = list;
    while (current){
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

Node* findMiddle(Node* list){
    Node* middle = list;
    Node* end = list;
    while (end && end->next){
        middle = middle->next;
        end = end->next->next;
    }
    return middle;
}

Node* reverseList(Node* list){ // singly linked implementation

    if (!list) return nullptr;

    Node* p = nullptr;
    Node* c = list;
    Node* n = nullptr;

    while (c){
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }


    return p;

}

int main(int argc,char **argv) {

    // 1 find middle of linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << findMiddle(head)->val << endl;

    // 2 reverse linked list (modify input, singly linked list)
    //// DRAW OUT TO UNDERSTAND BETTER
    printList(head);
    printList(reverseList(head));
    //printList(head);
    


    return 0;

}