#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insertBST(Node* root, int val) {
    if (root == nullptr) {
        return new Node{val, nullptr, nullptr};
    }
    
    // Logical Error: Incorrect comparison logic (swapped < and >)
    // Inserts smaller values to the RIGHT and larger to the LEFT.
    // This creates a "Reverse BST" but violates standard BST property.
    
    if (val > root->data) { // Should be < for standard BST
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
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
    insertBST(root, 70);
    
    // Expected Inorder (Standard BST): 30 50 70
    // Actual Inorder (Reverse BST logic): 70 50 30
    // Logic: 30 < 50. 30 > 50 is false. Goes to else (right).
    // 70 > 50. True. Goes to left.
    // Tree: 50 -> left: 70, right: 30.
    // Inorder: left (70) -> root (50) -> right (30).
    
    inorder(root);
    cout << endl;
    return 0;
}
