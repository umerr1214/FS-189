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
    
    if (val < root->data) {
        // Semantic Error: Assigning integer value to pointer?
        // root->left = val; // Invalid conversion int to Node*
        
        // Let's use assignment in condition.
        // if (val = root->data) // Sets val to root->data, returns true (non-zero).
        
        // Let's confuse left and right pointers semantically?
        // root->left = insertBST(root->right, val); // Logic error really.
        
        // Let's try to assign the address of a local variable?
        // Node temp = {val, nullptr, nullptr};
        // root->left = &temp; // Dangling pointer. Semantic/Life-time error.
        
        // Let's stick to assignment in condition.
        if (root->data = val) { // Modifies the tree node value to the inserted value!
             // Then recursively inserts?
             root->left = insertBST(root->left, val);
        }
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
    // Insert 30. 30 < 50.
    // if (root->data = 30). root->data becomes 30.
    // Recurse left with 30.
    // Tree root is now 30. Left child 30.
    // Insert 20. 20 < 30. root(30)->data becomes 20.
    // Recurse left.
    // The existing values in the path are overwritten by the new value being inserted.
    
    insertBST(root, 30);
    
    inorder(root);
    cout << endl;
    return 0;
}
