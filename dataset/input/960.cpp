#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool hasCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    Node* slow = head;
    Node* fast = head;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;
        }
    }
    
    return false;
}

int main() {
    Node* head1 = new Node{1, new Node{2, new Node{3, nullptr}}};
    cout << "Cycle 1: " << hasCycle(head1) << endl; // 0
    
    head1->next->next->next = head1; // 3->1
    cout << "Cycle 2: " << hasCycle(head1) << endl; // 1
    
    cout << "Cycle NULL: " << hasCycle(NULL) << endl; // 0
    
    return 0;
}
