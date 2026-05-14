#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    
    while (current != nullptr) {
        // Semantic Error: Assigning value to pointer or vice versa?
        
        // Let's try:
        // current->next = (Node*)prev->data; // Invalid cast/access
        
        // Let's use assignment in condition.
        // if (current = prev) ... 
        
        // Let's swap data instead of pointers?
        // No, that's valid logic (though inefficient).
        
        // Let's use address of pointer vs pointer?
        // current->next = &prev; // Type error: Node** to Node*
        
        // Let's use integer assignment to pointer.
        // current->next = 0; // Valid (NULL).
        
        // Let's use bitwise XOR to swap pointers (XOR linked list style) but without support?
        // current = (Node*)((uintptr_t)prev ^ (uintptr_t)current->next);
        
        // Let's use:
        Node* next = current->next;
        // current->next = *prev; // Error: cant dereference NULL
        
        // Semantic error: Using `head` as a next pointer for *every* node?
        // current->next = head; // Makes circular list immediately?
        
        // Let's try:
        // prev = &current; // Error Node** vs Node*
        
        // Let's try:
        // Assigning the `next` pointer to the `data` field (type mismatch/semantic nonsense).
        // current->data = (int)prev; // Cast pointer to int. Losing precision.
        
        // Let's go with:
        current->next = (Node*)((long long)prev + 1); // Semantic garbage: pointer arithmetic + 1 byte?
        
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    Node* head = new Node{1, nullptr};
    // Crash dereferencing garbage pointer
    reverseList(head);
    return 0;
}
