// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void buildtree(Node*root){
        int data;
        cin>>data;
        if(data == -1){
            return;
        }
        root = new Node(data);
        cout<<"left value: "<<data<<endl;
        buildtree(root->left);
        cout<<"right value: "<<data<<endl;
        buildtree(root->right);
}
//TOP VIEW
vector<int> topView(Node *root)
{
    vector<int>ans;
    if(root == NULL){
        return ans;
    }
    map<int, int>topnode;
    queue<pair<Node*, int>>q;
    q.push(make_pair(root, 0));
    
    while(!q.empty()){
        pair<Node*, int>temp = q.front();
        q.pop();
        Node* frontnode = temp.first;
        int hd = temp.second;
        //mapping one to one
        // id one value present fro horizontal dist do nothing
        if(topnode.find(hd) == topnode.end()){
            topnode[hd] = frontnode->data;
        }
        if(frontnode->left){
            q.push(make_pair(frontnode->left, hd-1));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right, hd+1));
        }
    }
    
    for(auto i: topnode){
        ans.push_back(i.second);
    }
    return ans;
}
    


//BOUNDRY TRAVERSAL
    void traverseleaf(Node*root, vector<int>&ans){
        if(!root) return;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        traverseleaf(root->left, ans);
        traverseleaf(root->right, ans);
    }
    
    void traverse_left(Node* root, vector<int>&ans){
        if(!root || (root->left==NULL && root->right==NULL)) return;
        ans.push_back(root->data);
        if(root->left){
            traverse_left(root->left,ans);
        }
        else{
            traverse_left(root->right, ans);
        }
    }
    
    void traverseright(Node* root, vector<int>&ans){
        if(!root || (root->left==NULL && root->right==NULL)) return;  
        if(root->right){
            traverseright(root->right, ans);
        }
        else{
            traverseright(root->left, ans);
        }
        ans.push_back(root->data);
    }

    vector <int> boundary(Node *root)
    {
        vector<int>ans;  //TC(O(N)), SC(O(N))
        if(!root) return ans;
        
        ans.push_back(root->data);
        //left traversal
        traverse_left(root->left, ans);
        traverseleaf(root->left, ans);
        traverseleaf(root->right, ans);
        traverseright(root->right, ans);
        return ans;
    }

//BOTTOM VIEW
void traversebottom(Node* root, vector<int>& ans) {
    if (!root) return;
    queue<pair<Node*, int>> q;
   
    map<int, int> mp; 
    q.push(make_pair(root, 0));
    
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        
        Node* frontnode = top.first;
        int hd = top.second;
        
       
        mp[hd] = frontnode->data;
        
       
        if (frontnode->left) {
            q.push(make_pair(frontnode->left, hd - 1));
        }
        
       
        if (frontnode->right) {
            q.push(make_pair(frontnode->right, hd + 1));
        }
    }
    
    for (auto i : mp) {
        ans.push_back(i.second);
    }
}
vector<int> bottomView(Node* root) {
    vector<int> ans;
    traversebottom(root, ans);
    return ans;
}




//LEFT VIEW
void solve(Node* root, vector<int>&ans, int level){
        if(!root) return;
        
        //new level entered
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        //left call righ se upr
        solve(root->left, ans, level+1);
        solve(root->right, ans, level+1);
    }
    vector<int> leftView(Node *root) {
       vector<int>ans;
       if(!root) return ans;
       solve(root, ans, 0);
       return ans;
    }



//RIGHT VIEW
    void solve(Node* root, vector<int>&ans, int level){
        if(!root) return;
        
        //new level entered
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        //right call left se upr
        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
    }
    vector<int> rightView(Node *root)
    {
       vector<int>ans;
       if(!root) return ans;
       solve(root, ans, 0);
       return ans;
    }

vector <int> zigZagTraversal(Node* root)
    {
    	vector<int>result;
    	if(root==NULL){
    	    return result;
    	}
    	queue<Node*>q;
    	q.push(root);
    	
    	bool lefttoright = true;
    	
    	while(!q.empty()){
    	    //proccess every level
    	    int size = q.size();
    	    vector<int>ans(size);
    	    
    	    for(int i=0; i<size; i++){
        	    Node*frontnode = q.front();
        	    q.pop();
        	   
        	    int index = lefttoright ? i: size-i-1;
        	    ans[index] = frontnode->data;
        	    
        	    if(frontnode->left){
        	        q.push(frontnode->left);
        	    }
        	    if(frontnode->right){
        	        q.push(frontnode->right);
        	    }
    	    }
    	    
    	    //change direction
    	    lefttoright = !lefttoright;
    	    for(auto i: ans){
    	       result.push_back(i); 
    	    }
    	}
    	return result;
    }


void levelordertraversal(Node*root){
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            Node*temp = q.front();
            q.pop();
            
            if(temp=NULL){
                cout<<endl;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                cout<<temp->data<<" ";
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                     q.push(temp->right); 
                }
            }
        }
    }



int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";

    return 0;
}