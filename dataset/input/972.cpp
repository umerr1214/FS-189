#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Iterative approach to avoid stack overflow on skewed trees
Node* insertBST(Node* root, int val) {
    Node* newNode = new Node{val, nullptr, nullptr};
    
    if (root == nullptr) {
        return newNode;
    }
    
    Node* current = root;
    Node* parent = nullptr;
    
    while (current != nullptr) {
        parent = current;
        if (val < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    if (val < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
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

// Helper to delete tree
void deleteTree(Node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    Node* root = nullptr;
    root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 70);
    insertBST(root, 60);
    insertBST(root, 80);
    
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    
    deleteTree(root);
    return 0;
}
