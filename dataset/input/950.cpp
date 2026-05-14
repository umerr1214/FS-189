#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        // prev = current; // Logical Error: Forgot to advance prev
        current = next;
    }
    head = prev;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, nullptr}}};
    // Expected: 3 -> 2 -> 1 -> NULL
    // Actual: NULL (because prev stays nullptr, so head becomes nullptr)
    // Or maybe list is broken.
    // 1st iter: curr=1. next=2. 1->next=NULL. prev=NULL. curr=2.
    // 2nd iter: curr=2. next=3. 2->next=NULL. prev=NULL. curr=3.
    // 3rd iter: curr=3. next=NULL. 3->next=NULL. prev=NULL. curr=NULL.
    // head = prev (NULL).
    // List is lost, head is NULL.
    
    reverseList(head);
    printList(head);
    return 0;
}
