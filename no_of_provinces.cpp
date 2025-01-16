#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs( int src, unordered_map<int,bool>&visited, vector<vector<int>>& isConnected){
     
        int size = isConnected[src].size();
        
        visited[src] = true;
        for(int col=0; col<size; col++){
            if(src != col && isConnected[src][col] ==1 ){
                if(!visited[col]){
                    dfs(col, visited, isConnected);
                }
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
      
        unordered_map<int,bool>visited;
        int count = 0;
    
        unordered_map<int, list<int>>adjlist;

        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected[i].size(); j++){
                if(isConnected[i][j]==1 && i != j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        for(int i=0; i<isConnected.size(); i++) {
            if(!visited[i]) {
                dfs(i, visited, isConnected);
                count++;
            }
        }
        return count;
        

    }
};