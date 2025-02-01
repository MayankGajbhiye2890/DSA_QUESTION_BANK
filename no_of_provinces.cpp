class Solution {
public:

    void dfs( int src, unordered_map<int,bool>&visited, unordered_map<int, list<int>>&adjlist){
        visited[src] = true;
        for(auto nbr: adjlist[src]){
            if(!visited[nbr]){
                dfs(nbr, visited, adjlist);
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
                dfs(i, visited, adjlist);
                count++;
            }
        }
        return count;
        

    }
};
