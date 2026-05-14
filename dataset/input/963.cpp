#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* mergeLists(Node* head1, Node* head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;
    
    // Semantic Error: Returning the address of a local variable?
    // Or treating int as Node*?
    
    // Let's use assignment in condition.
    // if (head1 = head2) -> Sets head1 to head2. Returns true (if head2 not null).
    
    // Let's use bitwise.
    
    // Let's try:
    // head1->next = (Node*)(head1->data + head2->data); // Semantic nonsense
    
    // Let's use assignment in condition.
    if (head1->data = head2->data) { // Sets head1->data to head2->data. Modifies list!
        head1->next = mergeLists(head1->next, head2);
        return head1;
    } else {
        head2->next = mergeLists(head1, head2->next);
        return head2;
    }
}

int main() {
    Node* l1 = new Node{1, new Node{3, nullptr}};
    Node* l2 = new Node{2, new Node{4, nullptr}};
    
    // Expected: 1 2 3 4
    // Actual: 
    // m(1, 2). 1=2 -> head1->data becomes 2. True. 
    // head1->next = m(3, 2). Return head1 (node 2).
    // m(3, 2). 3=2 -> head1->data becomes 2. True.
    // head1->next = m(NULL, 2). Return head1 (node 2).
    // m(NULL, 2). Returns 2.
    // List: 2 -> 2 -> 2 -> 4 -> NULL?
    // l1(2) -> l1_next(2) -> l2(2) -> l2_next(4).
    
    Node* merged = mergeLists(l1, l2);
    
    while (merged != nullptr) {
        cout << merged->data << " ";
        merged = merged->next;
    }
    cout << endl;
    return 0;
}
