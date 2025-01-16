#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:

    Node* dfs(Node* node, unordered_map<Node*, Node*>& nodeMap) {
        vector<Node*>neighbour;
        Node * clone = new Node(node->val);
        nodeMap[node] = clone;
        for(auto i: node->neighbors){
            if(nodeMap.find(i)!=nodeMap.end()){
                neighbour.push_back(nodeMap[i]);
            }
            else{
                neighbour.push_back(dfs(i,nodeMap));
            }
        }
        clone->neighbors = neighbour;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*, Node*> nodeMap;
        if(node->neighbors.size()==0){
            Node * clone = new Node(node->val);
            return clone;
        }
        return dfs(node, nodeMap);
    }        
};