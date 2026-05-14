#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insertBST(Node* root, int val) {
    // Efficiency/Readability:
    // Flattening the tree to a vector, adding the value, sorting, and rebuilding the tree?
    // O(N) space and O(N) time (to rebuild perfectly balanced tree maybe? or just simple insert).
    // Just simple insert is O(H). Rebuilding is O(N).
    // This is vastly inefficient for a simple insert.
    
    vector<int> vals;
    if (root) {
        // Collect all existing (inefficient traversal just to insert one)
        // Let's assume we implement a collector.
    }
    vals.push_back(val);
    
    // Sort and rebuild... (omitted full logic for brevity but the idea stands)
    // Actually, let's just do a naive rebuild.
    
    // For simplicity, let's just stick to the "allocate new vector every time" anti-pattern?
    // Or just a very verbose iterative implementation with redundant checks.
    
    if (root == nullptr) return new Node{val, nullptr, nullptr};
    
    Node* curr = root;
    while (true) {
        if (val < curr->data) {
            if (curr->left == nullptr) {
                curr->left = new Node{val, nullptr, nullptr};
                break;
            }
            curr = curr->left;
        } else {
            if (curr->right == nullptr) {
                curr->right = new Node{val, nullptr, nullptr};
                break;
            }
            curr = curr->right;
        }
        
        // Redundant / Dead code
        vector<int> temp; // Allocating vector in loop for no reason
        temp.push_back(val);
    }
    return root;
}

void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insertBST(root, 50);
    insertBST(root, 30);
    inorder(root);
    return 0;
}
