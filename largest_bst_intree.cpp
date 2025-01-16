#include<bits/stdc++.h>
using namespace std;

class info {
public:
    int maxi;
    int mini;
    bool isbst;
    int size;
};

info solve(TreeNode* root, int &ans) {
    // Base case: if the node is null, return default info
    if (root == NULL) {
        return {INT_MIN, INT_MAX, true, 0};
    }

    // Recursively solve for left and right subtrees
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    // Create a new info for the current node
    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);  // Calculate the maximum value in this subtree
    currNode.mini = min(root->data, left.mini);   // Calculate the minimum value in this subtree

    // Check if the current subtree is a BST
    if (left.isbst && right.isbst && (root->data > left.maxi && root->data < right.mini)) {
        currNode.isbst = true;
    } else {
        currNode.isbst = false;
    }

    // If it's a valid BST, update the answer with the size of the current BST
    if (currNode.isbst) {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

int largestBST(TreeNode* root) {
    int maxSize = 0;
    solve(root, maxSize);  
    return maxSize;       
}
