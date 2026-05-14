#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool hasCycle(Node* head) {
    // Robustness Issue: No NULL check at start (though while loop handles it).
    // BUT, accessing slow->next without check? 
    // fast->next->next handles fast->next check.
    // slow is behind fast, so if fast is safe, slow is safe?
    // Not necessarily? slow = slow->next. If head is valid, slow becomes head->next.
    // If head->next is NULL? fast becomes NULL. Loop doesn't run. Safe.
    
    // Let's modify logic to be unsafe.
    
    Node* slow = head;
    Node* fast = head->next; // Crash if head is NULL
    
    while (fast != nullptr && fast->next != nullptr) {
        if (slow == fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

int main() {
    Node* head = nullptr;
    // Crash
    // hasCycle(head);
    return 0;
}
