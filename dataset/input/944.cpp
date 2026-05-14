#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node();
    newNode->data = val;
    // Logical Error: Incorrect link order.
    // Setting head to newNode BEFORE linking newNode->next to old head.
    // This loses the rest of the list (memory leak and broken list).
    
    head = newNode;
    newNode->next = head; // Points to itself! Infinite loop / Cycle.
}

void printList(Node* head) {
    int count = 0;
    while (head != nullptr && count < 10) { // Limit for safety
        cout << head->data << " -> ";
        head = head->next;
        count++;
    }
    cout << (count == 10 ? "..." : "NULL") << endl;
}

int main() {
    Node* head = nullptr;
    insertAtHead(head, 10);
    insertAtHead(head, 20); // Creates cycle: 20 -> 20 -> ...
    
    // Expected: 20 -> 10 -> NULL
    // Actual: 20 -> 20 -> ... (Infinite loop)
    printList(head);
    return 0;
}
