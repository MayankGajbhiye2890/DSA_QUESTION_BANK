#include<bits/stdc++.h>
using namespace std;


template <typename T>
class BinaryTreeNode 
{
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) 
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() 
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

bool isValidBST2(BinaryTreeNode<int>* root, int &curr) {
    if (root == NULL)
        return true;  // An empty tree is a valid BST

    // Check if the left subtree is a valid BST
    bool leftAns = isValidBST2(root->left, curr);
    if (!leftAns)
        return false;

    // Compare the current node's value with the previous node's value (curr)
    if (root->data <= curr)  // If current node's value is not greater, it's not a valid BST
        return false;

    // Update curr to the current node's value
    curr = root->data;

    // Check if the right subtree is a valid BST
    bool rightAns = isValidBST2(root->right, curr);
    if (!rightAns)
        return false;

    return true;
}

 bool isValidBST4(BinaryTreeNode<int>* root, int low, int high){
    if(root==NULL)
        return true;
    
    if((root->data > low && root->data < high)){
        bool leftAns = isValidBST4(root->left, low, root->data);
        bool rightAns = isValidBST4(root->right, root->data, high);
        return leftAns && rightAns;
    }
    else
        return false;
}

bool validateBST(BinaryTreeNode<int>* root) 
{
   int curr = -1;
   //return isValidBST2(root, curr);
   return isValidBST4(root, INT_MIN, INT_MAX);
}