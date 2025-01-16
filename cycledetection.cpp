#include<bits/stdc++.h>
using namespace std;


//in undirected graph
bool iscyclicbfs(int src, unordered_map<int, bool>&visited, unordered_map<int, list<int>>&adj){
    unordered_map<int, int>parent;
    parent[src] = -1;
    visited[src] = true;
    queue<int>q;
    q.push(src);

    while(!q.empty()){
        int frontnode = q.front();
        q.pop();

        for(auto nbr: adj[frontnode]){
            if(visited[nbr] == true && nbr != parent[frontnode]){
                return true;
            }
            else if(!visited[nbr]){
                q.push(nbr);
                visited[nbr] = true;
                parent[nbr] = frontnode;
            }
        }
    }
    return false;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int>> adj;
    for(int i =0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //to handle disconected components;

    unordered_map<int, bool>visited;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = iscyclicbfs(i, visited, adj);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}



bool cycledfs(int src, int parent, unordered_map<int, bool> &visited){
        
    visited[src] = true; //parent = -1 for src
    unordered_map<int, list<int>> adj;
    for(int i =0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(auto nbr: adj[src]){
        if(!visited[nbr]){
            bool ans = cycledfs(nbr, src, visited);
            if(ans = true){
                return true;
            }
        }
        
        else if(visited[nbr] && nbr!=parent){
            return true;
        }
    }
    return false;
}


//in directed graph


 bool cycledirecteddfs(int src, unordered_map<int, bool>&visited, unordered_map<int, bool>&dfsvisited){
        
        visited[src] = true;
        dfsvisited[src] = true;
        
        for(auto nbr: adjlist[src]){
            if(!visited[nbr]){
                bool ans = cycledirecteddfs(0, visited, dfsvisited);
                if(ans == true){
                    return true;
                }
                
                if(visited[nbr] && dfsvisited[nbr]){
                    return true;
                }
            }
        }
        dfsvisited[src] = false;
        return false;
    }