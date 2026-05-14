#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void reverseList(Node*& head) {
    // Efficiency/Readability:
    // Storing all nodes in a vector and rebuilding the list?
    // O(N) extra space. Iterative pointer manipulation is O(1) space.
    
    if (!head) return;
    
    vector<Node*> nodes;
    Node* curr = head;
    while (curr) {
        nodes.push_back(curr);
        curr = curr->next;
    }
    
    for (int i = nodes.size() - 1; i > 0; i--) {
        nodes[i]->next = nodes[i-1];
    }
    nodes[0]->next = nullptr;
    head = nodes.back();
}

int main() {
    Node* head = new Node{1, new Node{2, nullptr}};
    reverseList(head);
    cout << head->data << endl;
    return 0;
}
