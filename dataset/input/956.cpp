#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool hasCycle(Node* head) {
    if (head == nullptr) return false;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        // Logical Error: fast moves at same speed as slow.
        // They will never meet unless they start at same (which they do) 
        // but loop condition prevents immediate check? No.
        // If they move same speed, they stay same distance apart (0).
        // `if (slow == fast)` will be true immediately?
        // Wait, loop body executes move first.
        // slow = next. fast = next.
        // slow == fast is true. Returns true.
        // So it says EVERYTHING has a cycle?
        // Yes, if list has at least one node, it returns true immediately.
        
        fast = fast->next; // Should be fast->next->next
        
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    Node* head = new Node{1, new Node{2, nullptr}};
    // Expected: False (No cycle)
    // Actual: True (slow=2, fast=2, match)
    if (hasCycle(head)) cout << "Cycle detected" << endl;
    else cout << "No cycle" << endl;
    return 0;
}
