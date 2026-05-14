#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insertBST(Node* root, int val) {
    // Robustness Issue: Recursion depth.
    // If we insert sorted data (1, 2, 3, 4...), the tree becomes a linked list (skewed).
    // For large N, this causes Stack Overflow.
    // Iterative insertion is preferred for robustness against skewed trees.
    
    // Also, `new` can fail (std::bad_alloc), but that's standard.
    // Let's focus on the skewed tree stack overflow.
    
    if (root == nullptr) {
        return new Node{val, nullptr, nullptr};
    }
    
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

int main() {
    Node* root = nullptr;
    // Skewed tree creation
    for(int i=0; i<50000; i++) { // Might crash on small stack
        // root = insertBST(root, i);
    }
    return 0;
}
