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

class LinkedList{

    private: 
    Node* head;
    Node* end;

    public:

    LinkedList(){
        head = nullptr;
        end = head;
    }

    void append(Node* n){
        if (!head) {
            head = n;
            end = head;
        }
        else{
            end->next = n;
            end = end->next;
        }
    }

    Node* find(Node* n){ // for finding a node in the list with the same value as n, NOT finding n itself in the list
        if (head->val == n->val) return head;
        else if (end->val == n->val) return end;

        Node* current = head->next;
        while (current){
            if (current->val == n->val) return current;
            current = current->next;
        }
        return nullptr;
    }

    void remove(Node* n){
        Node* previous = head;
        Node* current = head->next;
        while (current && current != n) {
            previous = previous->next;
            current = current->next;
        }
        if (current) {
            previous->next = current->next;
            delete current;
        }
    }

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

Node* mergeLists(Node* list1, Node* list2){

    if (list1 && !list2) return list1;
    else if (!list1 && list2) return list2;
    else if (!list1 && !list2) return nullptr;

    Node* start = new Node();
    Node* current = start;

    while (list1 && list2){
        if (list1->val < list2->val){
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    if (list1) current->next = list1;
    else if (list2) current->next = list2;

    Node* output = start->next;
    delete start;

    return output;
}

bool detectCycle(Node* list){
    if (!list) return false;

    Node* p1 = list;
    Node* p2 = list;

    while (true){
        if (!p1->next || !p2->next || !p2->next->next) return false;
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2) return true;
    }

}

int main(int argc,char **argv) {

    /*
    // 1 find middle of linked list
    Node* head1 = new Node(1);
    head1->next = new Node(4);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(5);
    head1->next->next->next->next = new Node(6);
    //cout << findMiddle(head1)->val << endl;

    Node* head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(4);
    head2->next->next->next = new Node(5);
    head2->next->next->next->next = new Node(7);

    // 2 reverse linked list (modify input, singly linked list)
    //// DRAW OUT TO UNDERSTAND BETTER
    printList(head1);
    printList(head2);*/

    //printList(mergeLists(head1, head2));

    Node* head = new Node(1);
    head->next = head;

    cout << detectCycle(head) << endl;



    return 0;

}