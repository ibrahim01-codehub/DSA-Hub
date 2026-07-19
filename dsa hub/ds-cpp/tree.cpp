// ============================================
// BINARY SEARCH TREE (BST) - a hierarchy of nodes
// Left child < parent < right child. This ordering is what
// makes searching fast, like a family tree that's sorted.
// ============================================
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// ---- Insert a value - O(log n) average, O(n) worst case ----
// We go left if smaller, right if bigger, until we find an empty spot.
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// ---- Search for a value - O(log n) average, O(n) worst case ----
bool search(Node* root, int value) {
    if (root == nullptr) return false;
    if (root->data == value) return true;
    if (value < root->data) return search(root->left, value);
    return search(root->right, value);
}

// ---- Inorder traversal - visits nodes in sorted order - O(n) ----
void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// ---- Height of the tree - O(n) ----
int height(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Inorder (sorted) traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Is 40 in the tree? " << (search(root, 40) ? "Yes" : "No") << endl;
    cout << "Is 99 in the tree? " << (search(root, 99) ? "Yes" : "No") << endl;

    cout << "Tree height: " << height(root) << endl;

    return 0;
}
