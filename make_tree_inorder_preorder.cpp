
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* buildTreeFromInorderAndPreorder2(vector<int> &inorder, vector<int> &preorder, int &size, int &preIndex, int inorderStart, int inorderEnd, unordered_map<int,int>& inorderMapping){
    if(preIndex >= size || inorderStart > inorderEnd)
        return NULL;

    int  element = preorder[preIndex];
    TreeNode*root = new TreeNode(element);

    int inIndex = inorderMapping[element];

    preIndex++;

    // left before right as in postorder => NLR => and we move from leftmost element towards right => N->L->R
    root->left = buildTreeFromInorderAndPreorder2(inorder, preorder, size, preIndex, inorderStart, inIndex-1, inorderMapping);
    root->right = buildTreeFromInorderAndPreorder2(inorder, preorder, size, preIndex, inIndex+1, inorderEnd, inorderMapping);

    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>inordermapping;
        int size = preorder.size();
        int preindex = 0;
        int inorderstart = 0;
        int inorderend = size-1;

        for (int i = 0; i < inorder.size(); i++) {
            inordermapping[inorder[i]] = i;
        }
        TreeNode * root = buildTreeFromInorderAndPreorder2(inorder, preorder, size, preindex, inorderstart, inorderend, inordermapping);
        return root;

    }
};