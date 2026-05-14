#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* mergeLists(Node* head1, Node* head2) {
    // Efficiency/Readability:
    // Dumping both lists into a vector, sorting vector, recreating list?
    // O(N) space, O(N log N) time.
    // Merging should be O(N) time, O(1) space (iterative).
    
    vector<int> vals;
    while(head1) { vals.push_back(head1->data); head1 = head1->next; }
    while(head2) { vals.push_back(head2->data); head2 = head2->next; }
    
    sort(vals.begin(), vals.end());
    
    if (vals.empty()) return nullptr;
    
    Node* newHead = new Node{vals[0], nullptr};
    Node* curr = newHead;
    for (size_t i = 1; i < vals.size(); i++) {
        curr->next = new Node{vals[i], nullptr};
        curr = curr->next;
    }
    return newHead;
}

int main() {
    Node* l1 = new Node{1, new Node{3, nullptr}};
    Node* l2 = new Node{2, new Node{4, nullptr}};
    Node* res = mergeLists(l1, l2);
    while (res) { cout << res->data << " "; res = res->next; }
    return 0;
}
