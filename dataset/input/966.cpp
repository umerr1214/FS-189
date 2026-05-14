#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Iterative approach for O(N) time and O(1) space (robust against stack overflow)
Node* mergeLists(Node* head1, Node* head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;
    
    Node dummy; // Stack-allocated dummy node to simplify head logic
    Node* tail = &dummy;
    
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    
    if (head1 != nullptr) {
        tail->next = head1;
    } else {
        tail->next = head2;
    }
    
    return dummy.next;
}

int main() {
    Node* l1 = new Node{1, new Node{3, nullptr}};
    Node* l2 = new Node{2, new Node{4, nullptr}};
    
    Node* merged = mergeLists(l1, l2);
    
    cout << "Merged: ";
    while (merged != nullptr) {
        cout << merged->data << " ";
        merged = merged->next;
    }
    cout << endl;
    
    return 0;
}
