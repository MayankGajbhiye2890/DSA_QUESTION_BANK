#include <iostream>
using namespace std;

// Structure for a binary tree node
struct Node {
    int data;
    Node* left, * right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

// Function to find the k-th ancestor of a given node
Node* kthAncestor(Node* root, int node, int& k) {
    if (root == nullptr) {
        return nullptr;
    }

    // If the current node is the target node
    if (root->data == node) {
        return root;
    }

    // Recur for the left and right subtrees
    Node* left = kthAncestor(root->left, node, k);
    Node* right = kthAncestor(root->right, node, k);

    // If the node is found in either the left or right subtree
    if (left != nullptr || right != nullptr) {
        k--;  // Decrease k as we move up towards the ancestor

        // If k becomes 0, this is the k-th ancestor
        if (k == 0) {
            cout << "K-th ancestor is: " << root->data << endl;
            return nullptr;  // Return null to stop further backtracking
        }

        // Return the current node to its parent call
        return root;
    }

    return nullptr;  // If the node isn't found in this subtree
}

// Function to find and print the k-th ancestor of a given node
void findKthAncestor(Node* root, int node, int k) {
    Node* ancestor = kthAncestor(root, node, k);

    // If no ancestor was found, print a message
    if (k > 0) {
        cout << "No k-th ancestor found for node " << node << endl;
    }
}

int main() {
    // Creating a binary tree for demonstration
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);

    // Example: Find 2nd ancestor of node 8
    int node = 8, k = 2;
    findKthAncestor(root, node, k);

    return 0;
}
