#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int sr, int sc, int color, int oldcolor, map<pair<int, int>, bool>&visited, vector<vector<int>>&arr){
        visited[{sr,sc}] = true;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        arr[sr][sc] = color;

        for(int i=0; i<4; i++){
            int newx = sr+dx[i];
            int newy = sc+dy[i];

            if(newx >=0 && newx<arr.size() && newy>=0 && newy<arr[0].size() && !visited[{newx,newy}] && arr[newx][newy] == oldcolor){
                dfs(newx, newy, color, oldcolor, visited, arr);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        map<pair<int, int>, bool>visited;
        int oldcolor = image[sr][sc];
        dfs(sr, sc, color, oldcolor, visited, image);
        return image;
    }
};