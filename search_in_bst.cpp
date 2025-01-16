#include<bits/stdc++.h>
using namespace std;

/* https://www.naukri.com/code360/problems/search-in-bst_1402878?leftPanelTabValue=PROBLEM */
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left, *right;s
    BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
    BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
    BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
};


bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root==NULL) return false;
    
    //if(root=data == x) return true;
    if(root->data == x){
        return true;
    }
    
    if(root->data > x){
        return searchInBST(root->left, x);
    }
    if(root->data < x){
        return searchInBST(root->right, x);
    }
    //return false;
}