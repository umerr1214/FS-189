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
        next = current->next;  // Store next node
        current->next = prev;  // Reverse current node's pointer
        prev = current;        // Move pointers one position ahead
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
    printList(head);
    
    reverseList(head);
    printList(head); // 3 -> 2 -> 1 -> NULL
    
    // Cleanup (simplified)
    while(head) {
        Node* t = head;
        head = head->next;
        delete t;
    }
    
    return 0;
}
