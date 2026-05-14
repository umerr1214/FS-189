#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtHead(Node*& head, int val) {
    // Efficiency/Readability:
    // Copying the entire linked list to a vector, inserting at front, then rebuilding the list?
    // Very inefficient O(N) space and time for an O(1) operation.
    
    vector<int> vals;
    vals.push_back(val);
    
    Node* curr = head;
    while (curr != nullptr) {
        vals.push_back(curr->data);
        Node* temp = curr;
        curr = curr->next;
        delete temp; // Free old nodes
    }
    
    // Rebuild list
    head = nullptr;
    // We need to insert from back to front to maintain order if using insertAtHead logic, 
    // or just build normally.
    // Vectors are [val, old1, old2...]
    
    for (int i = vals.size() - 1; i >= 0; i--) {
        Node* newNode = new Node();
        newNode->data = vals[i];
        newNode->next = head;
        head = newNode;
    }
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    printList(head); // 20 -> 10 -> NULL
    return 0;
}
