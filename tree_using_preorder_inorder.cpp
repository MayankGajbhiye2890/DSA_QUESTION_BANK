
#include <bits/stdc++.h>
using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
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

    
Node* solve(vector<int> &inorder, vector<int> &preorder, int inorderindex, int inorderend, int &preorderindex, int n, map<int, int> &inordermapping) {
        if (inorderindex > inorderend || preorderindex >= n) {
            return NULL;
        }
        int data = preorder[preorderindex++];
        Node* root = new Node(data);
        
        int pos = inordermapping[data];
        
        // Recursively build the left and right subtrees
        root->left = solve(inorder, preorder, inorderindex, pos - 1, preorderindex, n, inordermapping);
        root->right = solve(inorder, preorder, pos + 1, inorderend, preorderindex, n, inordermapping);
        
        return root;
    }
    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        int n = inorder.size();
        int preorderindex = 0;
        map<int, int> inordermapping;
        
        for (int i = 0; i < n; i++) {
            inordermapping[inorder[i]] = i;
        }
        
        return solve(inorder, preorder, 0, n - 1, preorderindex, n, inordermapping);
    }
};

