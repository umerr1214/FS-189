#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* mergeLists(Node* head1, Node* head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;
    
    // Logical Error: Incorrect comparison operator (> instead of <)
    // Merges in descending order? No, merging sorted lists requires picking smaller element.
    // If we pick larger element first, we break the sorted order or lose elements?
    // Let's see recursion:
    // merge(1, 2) -> 1 > 2 False. Else: head2 (2) -> next = merge(1, 4).
    // merge(1, 4) -> 1 > 4 False. Else: head2 (4) -> next = merge(1, NULL).
    // merge(1, NULL) -> returns 1.
    // Result: 2 -> 4 -> 1 -> 3.
    // Order is messed up.
    
    if (head1->data > head2->data) { 
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
    // Actual with error (>): 2 4 1 3 (approx, recursion logic is complex with wrong comparison)
    // Actually:
    // m(1, 2). 1>2 False. 2->next = m(1, 4). Return 2.
    // m(1, 4). 1>4 False. 4->next = m(1, NULL). Return 4.
    // m(1, NULL). Returns 1.
    // List: 2 -> 4 -> 1 -> 3 -> NULL.
    
    Node* merged = mergeLists(l1, l2);
    
    while (merged != nullptr) {
        cout << merged->data << " ";
        merged = merged->next;
    }
    cout << endl;
    return 0;
}
