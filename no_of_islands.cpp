#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!='1'){//edge cases, to consider region around the grid 
            return;
        }
        //if(grid[i][j]== '-1') return;
        grid[i][j] = 'M';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0; i<grid.size(); i++){ 
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j]=='1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    
};