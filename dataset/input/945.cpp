#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node();
    
    // Semantic Error: Confusion between pointer and value?
    // Or assignment in wrong place.
    
    // Let's use assignment in `next` field.
    // newNode->next = (Node*)val; // Semantic error: int to pointer cast?
    
    // Let's use `head` value (address) as data?
    // newNode->data = (int)head; // Lossy cast on 64-bit
    
    // Let's use assignment in condition logic? No.
    
    // Let's try to assign the pointer ADDRESS to data.
    // And assign DATA to next pointer (unsafe cast).
    
    newNode->data = val;
    // Semantic Error: Assigning value 'val' to the pointer 'next' (reinterpreted).
    // This creates a wild pointer.
    newNode->next = (Node*)(long long)val; // Invalid pointer
    
    head = newNode;
}

void printList(Node* head) {
    if (head != nullptr) {
        cout << head->data << " -> ";
        // Accessing head->next will crash if it's invalid
        // if (head->next != nullptr) cout << head->next->data;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    // head -> {10, (Node*)10}
    insertAtHead(head, 10);
    
    // Crash when accessing next
    // printList(head); 
    return 0;
}
