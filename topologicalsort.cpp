#include <bits/stdc++.h> 
using namespace std;


//bfs algo
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>>adj;

    for(int i = 0; i< e; i++){
        int x = edges[i][0];
        int y = edges[i][1];
        adj[x].push_back(y);
    }

    vector<int>indegree(v);
    for(auto i: adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }

    //push elements with 0 indegree

    queue<int>q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int>ans;
    while(!q.empty()){
        int fnode = q.front();
        q.pop();
        ans.push_back(fnode);

        for(auto nbr: adj[fnode]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }

    }

    return ans;
}

//dfs

#include <bits/stdc++.h> 
using namespace std;

void toposortdfs(int i, unordered_map<int, bool>&visited, stack<int>&st, unordered_map<int, list<int>>&adj){
    visited[i] = true;
    for(auto nbr: adj[i]){
        if(!visited[nbr]){
            toposortdfs(nbr, visited, st, adj);
        }
    }
    st.push(i);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int>>adj;

    for(int i = 0; i< e; i++){
        int x = edges[i][0];
        int y = edges[i][1];
        adj[x].push_back(y);
    }

    vector<int>ans;
    stack<int>st;
    unordered_map<int, bool>visited; // canalso use vector<bool>visited;
    for(int i =0; i<v; i++){
        if(!visited[i]){
            toposortdfs(i, visited, st, adj);
        }
    }
    
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}