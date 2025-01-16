#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find the predecessor and successor
void findPredecessorSuccessor(TreeNode* root, int key, TreeNode*& predecessor, TreeNode*& successor) {
    while (root != NULL) {
        if (root->val == key) {
            // Find predecessor: Max in the left subtree
            if (root->left != NULL) {
                TreeNode* temp = root->left;
                while (temp->right != NULL) {
                    temp = temp->right;
                }
                predecessor = temp;
            }

            // Find successor: Min in the right subtree
            if (root->right != NULL) {
                TreeNode* temp = root->right;
                while (temp->left != NULL) {
                    temp = temp->left;
                }
                successor = temp;
            }
            return;
        }

        // Move left if the key is smaller
        if (key < root->val) {
            successor = root;  // Current node could be a successor
            root = root->left;
        } else {
            predecessor = root;  // Current node could be a predecessor
            root = root->right;
        }
    }
}

int main() {
    // Example BST
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    int key = 10;
    TreeNode* predecessor = NULL;
    TreeNode* successor = NULL;

    findPredecessorSuccessor(root, key, predecessor, successor);

    cout << "Key: " << key << endl;
    if (predecessor != NULL) {
        cout << "Predecessor: " << predecessor->val << endl;
    } else {
        cout << "Predecessor: None" << endl;
    }

    if (successor != NULL) {
        cout << "Successor: " << successor->val << endl;
    } else {
        cout << "Successor: None" << endl;
    }

    return 0;
}





//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
   
        if (root == nullptr) return;

        // If the root's data matches the key
        if (root->key == key) {
            // Predecessor: Find the rightmost node in the left subtree
            if (root->left != nullptr) {
                Node* temp = root->left;
                while (temp->right) temp = temp->right;
                pre = temp;
            }
    
            // Successor: Find the leftmost node in the right subtree
            if (root->right != nullptr) {
                Node* temp = root->right;
                while (temp->left) temp = temp->left;
                suc = temp;
            }
            return;
        }
    
        // If the key is smaller than root's data, move to the left subtree
        if (key < root->key) {
            suc = root; // Update successor to current node
            findPreSuc(root->left, pre, suc, key);
        }
        // If the key is greater than root's data, move to the right subtree
        else {
            pre = root; // Update predecessor to current node
            findPreSuc(root->right, pre, suc, key);
        }
        
    }
};

//{ Driver Code Starts.

Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}
// Driver program to test above functions
int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        Node *pre=NULL,*succ=NULL;
        Solution ob;
        ob.findPreSuc(root,pre,succ,k);
        (pre!=NULL)?cout<<pre->key:cout<<-1;
        cout<<" ";
        (succ!=NULL)?cout<<succ->key:cout<<-1;
        cout<<endl;
        // inOrderTraversal(root);
   
cout << "~" << "\n";
}
   return 0;
}
// } Driver Code Ends