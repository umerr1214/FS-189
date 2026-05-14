#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* mergeLists(Node* head1, Node* head2) {
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
    Node* l1 = new Node{1, new Node{3, nullptr}};
    Node* l2 = new Node{2, new Node{4, nullptr}};
    
    Node* merged = mergeLists(l1, l2) // Syntax Error: Missing semicolon
    
    while (merged != nullptr) {
        cout << merged->data << " ";
        merged = merged->next;
    }
    cout << endl;
    return 0;
}
