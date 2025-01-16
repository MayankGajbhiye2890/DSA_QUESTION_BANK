#include<bits/stdc++.h>
using namespace std;

int rotton_oranges(vector<vector<int>>grid){
    int ans=0;
        queue<pair<pair<int, int>, int>>q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    pair<int, int> p = make_pair(i, j);
                    q.push({p,0}); //

                }
            }
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int x = top.first.first;
            int y = top.first.second;
            int time = top.second;

            int dirx[] = {-1,0, 1, 0};
            int diry[]= {0, 1, 0, -1};

            for(int i =0; i<4; i++){
                int newx = x+dirx[i];
                int newy = y+diry[i];

                if(newx>=0 && newx<grid.size() && newy>=0 && newy<grid[0].size() && grid[newx][newy]==1 && grid[newx][newy]!=2){


                    pair<int, int>newcoordinates = make_pair(newx, newy);
                    ans = max(ans, time+1);
                    q.push({newcoordinates, time+1});
                    grid[newx][newy] = 2;


                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return ans;
}