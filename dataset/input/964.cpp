#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* mergeLists(Node* head1, Node* head2) {
    // Robustness Issue: Recursion depth.
    // Merging two long lists recursively can cause Stack Overflow.
    // Iterative approach is preferred for robustness.
    
    // Also, if lists have cycles, infinite recursion.
    // But typically assumes acyclic.
    
    // The main robustness issue with recursion on linked lists is stack depth O(N).
    
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;
    
    if (head1->data < head2->data) {
        head1->next = mergeLists(head1->next, head2);
        return head1;
    } else {
        head2->next = mergeLists(head1, head2->next);
        return head2;
    }
}

int main() {
    // Creating long list to trigger stack overflow would be robustness test, 
    // but for simple test case it works.
    Node* l1 = new Node{1, nullptr};
    Node* l2 = new Node{2, nullptr};
    mergeLists(l1, l2);
    return 0;
}
