#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeFromPrePost(vector<int>& preorder, vector<int>& postorder, int& preIndex, int postStart, int postEnd, unordered_map<int, int>& postIndexMap) {
    if (preIndex >= preorder.size() || postStart > postEnd)
        return nullptr;
    
    int element = preorder[preIndex++];
    TreeNode* root = new TreeNode(element);
    

    if (postStart == postEnd)
        return root;
    

    int leftSubtreeRootIndex = postIndexMap[preorder[preIndex]];
    

    root->left = buildTreeFromPrePost(preorder, postorder, preIndex, postStart, leftSubtreeRootIndex, postIndexMap);
    root->right = buildTreeFromPrePost(preorder, postorder, preIndex, leftSubtreeRootIndex + 1, postEnd - 1, postIndexMap);
    
    return root;
}

TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    unordered_map<int, int> postIndexMap;
    int preIndex = 0;
    for (int i = 0; i < postorder.size(); ++i) {
        postIndexMap[postorder[i]] = i;
    }
    
    return buildTreeFromPrePost(preorder, postorder, preIndex, 0, postorder.size() - 1, postIndexMap);
}

void printInorder(TreeNode* root) {
    if (root == nullptr)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
    
    TreeNode* root = constructFromPrePost(preorder, postorder);
    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // Function to search for a number in the postorder array
    int search(vector<int>& postorder,int start,int end,int num)
    {
        for(int i=start;i<=end;i++)
        {
            if(postorder[i] == num)
            {
                return i;
            }
        }

        return -1;
    }
    // Variable to keep track of the index in the preorder array
    int preindex = 0;
    TreeNode* solve(vector<int>&preorder,vector<int>&postorder,int start,int end)
    {
        // Base case: empty subtree
        if(start > end || preindex >= preorder.size())
            return nullptr;

        // Root value for the current subtree
        int num = preorder[preindex];
        preindex++;

        TreeNode*root = new TreeNode(num);

        // Leaf node or end of current subtree
        if(preindex >= preorder.size() || start == end)
            return root;

        // The index of the next root value in the postorder array
        int postindex = search(postorder,start,end,preorder[preindex]);
        
        //Recursive call for left and right subtree
        root->left = solve(preorder,postorder,start,postindex);
        // end - 1 because the root node is taken out
        root->right = solve(preorder,postorder,postindex + 1,end - 1);

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        return solve(preorder,postorder,0,preorder.size()-1);
    }
};
