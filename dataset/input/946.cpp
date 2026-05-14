#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtHead(Node*& head, int val) {
    // Robustness Issue: new can fail (std::bad_alloc), but here we don't catch it (standard).
    // More importantly: memory leak if we lose the head? No.
    
    // What if we don't handle the case where head is already NULL properly?
    // Logic `newNode->next = head` works for NULL too.
    
    // Robustness: Creating node on stack instead of heap?
    // Node newNode; // Local object
    // newNode.data = val;
    // newNode.next = head;
    // head = &newNode; 
    // // Function returns, newNode is destroyed. head points to dangling memory.
    
    Node newNode; // Stack allocation
    newNode.data = val;
    newNode.next = head;
    head = &newNode; // Dangling pointer after return
}

void printList(Node* head) {
    // Accessing dangling pointer
    // Undefined behavior (might print garbage or crash)
    /*
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    */
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    insertAtHead(head, 10);
    // head is now invalid
    return 0;
}
