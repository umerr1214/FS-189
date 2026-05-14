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
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;
        }
    }
    return false
} // Syntax Error: Missing semicolon

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, nullptr}}};
    head->next->next->next = head; // Create cycle: 3 -> 1
    
    if (hasCycle(head)) cout << "Cycle detected" << endl;
    else cout << "No cycle" << endl;
    
    // Cleanup tricky with cycle, just exit
    return 0;
}
