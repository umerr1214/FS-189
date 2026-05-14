#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void reverseList(Node*& head) {
    // Robustness: What if list has loop? Infinite loop.
    // What if head is NULL? Handled by loop condition?
    // while(current != nullptr) works for NULL head.
    
    // Robustness Issue: Stack overflow if implemented recursively?
    // But this is iterative.
    // Let's make it recursive without base case check?
    
    // Or let's assume we don't check for NULL head if we access head->next before loop?
    
    Node* current = head->next; // Crash if head is NULL
    Node* prev = head;
    prev->next = nullptr;
    
    while (current != nullptr) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    Node* head = nullptr;
    // Crash
    // reverseList(head);
    return 0;
}
