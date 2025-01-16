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
    TreeNode * solve(vector<int>& inorder, vector<int>& postorder, int inorderstart, int inorderend, int &postorderindex, 
    map<int, int>&inordermapping){
        if(inorderstart > inorderend || postorderindex<0){
            return NULL;
        }
        int data = postorder[postorderindex--];
        TreeNode * root = new TreeNode(data);

        int pos = inordermapping[data];

        root->right = solve(inorder, postorder, pos+1, inorderend, postorderindex, inordermapping);
        root->left = solve(inorder, postorder, inorderstart, pos-1, postorderindex, inordermapping);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int, int>inordermapping;
        for(int i=0; i<n; i++){
            inordermapping[inorder[i]] = i;
        }
        int postorderindex = n-1;
        return solve(inorder, postorder, 0, n-1, postorderindex, inordermapping);
    }
};