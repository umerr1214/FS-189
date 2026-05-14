#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        
        // Semantic Error: Comparing data instead of pointers?
        // if (slow->data == fast->data)
        // This is valid C++ but semantically wrong for cycle detection (duplicate values != cycle).
        
        // Let's use assignment in condition.
        // if (slow = fast) -> always true if not null.
        
        // Let's use bitwise XOR comparison of pointers?
        // if (!(slow ^ fast)) // Error: invalid operands.
        
        // Let's use comparison of data values.
        if (slow->data == fast->data) { // Semantic: Checking value equality, not reference equality
             return true;
        }
    }
    return false;
}

int main() {
    // List: 1 -> 2 -> 1 -> NULL
    // No cycle.
    // slow=2, fast=1. match? No.
    // slow=1, fast=NULL. Loop ends.
    
    // List: 1 -> 1 -> NULL
    // slow=1 (2nd), fast=NULL. 
    
    // List: 1 -> 2 -> 3 -> 2 -> NULL
    // slow=2, fast=3.
    // slow=3, fast=NULL.
    
    // We need a case where values match but nodes are different.
    // 1 -> 2 -> 3 -> 4 -> 2 -> NULL (No cycle)
    // s=2, f=3
    // s=3, f=2
    // s=4, f=NULL
    
    // 1 -> 2 -> 1 -> 2 -> NULL
    // s=2, f=1
    // s=1, f=NULL
    
    // 1 -> 2 -> 2 -> NULL
    // s=2, f=NULL.
    
    // 1 -> 2 -> 3 -> 2 -> 3 -> NULL
    // s=2, f=3
    // s=3, f=3 -> MATCH! Returns true.
    // But no cycle.
    
    Node* head = new Node{1, new Node{2, new Node{3, new Node{2, new Node{3, nullptr}}}}};
    if (hasCycle(head)) cout << "Cycle detected" << endl;
    else cout << "No cycle" << endl;
    
    return 0;
}
