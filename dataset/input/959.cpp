#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool hasCycle(Node* head) {
    // Efficiency/Readability:
    // Storing all visited nodes in a vector to check for cycle?
    // O(N) space. Floyd's algorithm is O(1) space.
    // Searching vector linearly is O(N) per step -> O(N^2) time.
    
    vector<Node*> visited;
    Node* curr = head;
    while (curr != nullptr) {
        for (Node* node : visited) {
            if (node == curr) return true;
        }
        visited.push_back(curr);
        curr = curr->next;
    }
    return false;
}

int main() {
    Node* head = new Node{1, new Node{2, nullptr}};
    head->next->next = head;
    cout << hasCycle(head) << endl;
    return 0;
}
