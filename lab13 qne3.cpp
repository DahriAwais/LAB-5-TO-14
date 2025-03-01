#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

bool searchNonRecursive(Node* root, int key) {
    while (root != nullptr) {
        if (root->data == key) return true;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return false;
}

bool searchRecursive(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

void inOrderTraversal(Node* root) {
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    int n, value, key;

    cout << "Enter the number of elements in the BST: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "In-Order Traversal of BST: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Enter the integer to search (Non-Recursive): ";
    cin >> key;
    if (searchNonRecursive(root, key)) cout << "Key found (Non-Recursive)\n";
    else cout << "Key not found (Non-Recursive)\n";

    cout << "Enter the integer to search (Recursive): ";
    cin >> key;
    if (searchRecursive(root, key)) cout << "Key found (Recursive)\n";
    else cout << "Key not found (Recursive)\n";

    return 0;
}
