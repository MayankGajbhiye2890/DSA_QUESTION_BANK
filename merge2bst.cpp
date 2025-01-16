#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

//APPROACH ONE
void inorder(TreeNode *root, vector<int> &in) {
    if (!root) return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}


vector<int> mergedarrays(vector<int> &a, vector<int> &b) {
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            ans[k++] = a[i++];
        } 
        else {
            ans[k++] = b[j++];
        }
    }
    while (i < a.size()) {
        ans[k++] = a[i++];
    }
    while (j < b.size()) {
        ans[k++] = b[j++];
    }
    return ans;
}


TreeNode *inorderbst(int s, int e, vector<int> &in) {
    if (s > e) return NULL;

    int mid = s + (e - s) / 2;
    TreeNode *root = new TreeNode(in[mid]);
    root->left = inorderbst(s, mid - 1, in);
    root->right = inorderbst(mid + 1, e, in);
    return root;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {
    // Perform in-order traversals of the input BSTs
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // Merge the two sorted in-order traversals
    vector<int> mergedArray = mergedarrays(bst1, bst2);

    // Build a balanced BST from the merged array
    TreeNode *mergedBST = inorderbst(0, mergedArray.size() - 1, mergedArray);

    // Get the in-order traversal of the merged BST
    vector<int> mergedInorder;
    inorder(mergedBST, mergedInorder);
    return mergedInorder;
}



//APPROACH 2: DONO BST KO LINKEDLIST BANAKR FIR MERGE KRDO JIS SE SPACE COMPLEXITY IMPROVE HO JAYEGI FIR SORTED LL TO BST

void inorder(TreeNode *root, vector<int> &in) {
    if (!root) return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

// Merging two sorted vectors
vector<int> mergedarrays(vector<int> &a, vector<int> &b) {
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            ans[k++] = a[i++];
        } else {
            ans[k++] = b[j++];
        }
    }
    while (i < a.size()) {
        ans[k++] = a[i++];
    }
    while (j < b.size()) {
        ans[k++] = b[j++];
    }
    return ans;
}

// Convert a BST to sorted doubly linked list
void convertIntoSortedDll(TreeNode *root, TreeNode* &head){
    if(!root) return;
    convertIntoSortedDll(root->right, head);
    root->right = head;
    if(head != NULL) {
        head->left = root;
    }
    head = root;
    convertIntoSortedDll(root->left, head);
}

// Build balanced BST from sorted array
TreeNode *inorderbst(int s, int e, vector<int> &in) {
    if (s > e) return NULL;
    int mid = s + (e - s) / 2;
    TreeNode *root = new TreeNode(in[mid]);
    root->left = inorderbst(s, mid - 1, in);
    root->right = inorderbst(mid + 1, e, in);
    return root;
}

// Merge two sorted DLLs into one sorted DLL
TreeNode* MERGEDLL(TreeNode* h1, TreeNode* h2){
    TreeNode *head = NULL, *tail = NULL;
    while(h1 != NULL && h2 != NULL){
        if(h1->data < h2->data){
            if(head == NULL){
                head = tail = h1;
                h1 = h1->right;
            } else {
                tail->right = h1;
                h1->left = tail;
                tail = h1;
                h1 = h1->right;
            }
        } else {
            if(head == NULL){
                head = tail = h2;
                h2 = h2->right;
            } else {
                tail->right = h2;
                h2->left = tail;
                tail = h2;
                h2 = h2->right;
            }
        }
    }
    while(h1 != NULL){
        tail->right = h1;
        h1->left = tail;
        tail = h1;
        h1 = h1->right;
    }
    while(h2 != NULL){
        tail->right = h2;
        h2->left = tail;
        tail = h2;
        h2 = h2->right;
    }
    return head;
}

// Count nodes in a DLL
int countnodes(TreeNode *head){
    int cnt = 0;
    TreeNode *temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

// Convert sorted DLL to balanced BST
TreeNode *sortedlltobst(TreeNode *&head, int n) {
    if (n <= 0 || head == NULL) return NULL;
    TreeNode *left = sortedlltobst(head, n / 2);
    TreeNode *root = head;
    root->left = left;
    head = head->right;
    root->right = sortedlltobst(head, n - n / 2 - 1);
    return root;
}

// Main function to merge two BSTs
vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {
    TreeNode *head1 = NULL, *head2 = NULL;
    convertIntoSortedDll(root1, head1);
    head1->left = NULL;

    convertIntoSortedDll(root2, head2);
    head2->left = NULL;

    // Merge sorted DLLs
    TreeNode *head = MERGEDLL(head1, head2);

    // Convert merged DLL to balanced BST
    TreeNode *ansTree = sortedlltobst(head, countnodes(head));

    // Return inorder traversal of merged BST
    vector<int> ans;
    inorder(ansTree, ans);
    return ans;
}
