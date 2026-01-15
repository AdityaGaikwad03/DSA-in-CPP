#include <iostream>
using namespace std;

// Define the structure for a BST node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the BST
Node* insert(Node* root, int val) {
    // If tree is empty, create a new node
    if (root == nullptr) {
        return new Node(val);
    }

    // Insert into left or right subtree based on value
    if (val < root->data) {
        root->left = insert(root->left, val);
    } 
    else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    // If val == root->data, we skip insertion (no duplicates in BST)
    
    return root; // Return unchanged root pointer
}

// Inorder traversal to verify insertion
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
int main() {
    Node* root = nullptr;

    // Insert values into BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;
    cout << "Preorder traversal of BST: "; 
    preorder(root);
    cout << endl;
    cout << "Postorder traversal of BST: ";
    postorder(root);
    cout << endl;
    

    return 0;
}