#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//3d dp as r,c, and k are changing
    int N;
    vector<pair<int, int>>directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};


    double solve(int r, int c, int k, vector<vector<vector<double>>>&dp){
        if(r<0 || c<0 || r>=N || c>=N){
            return 0;
        }
        if(k==0){
            return 1;
        }
        if(dp[r][c][k] != -1) return dp[r][c][k];
        double ans =0;
        for(auto dir: directions){
            int new_r = r + dir.first;
            int new_c = c + dir.second;
            ans += solve(new_r, new_c, k-1, dp);
        }
        dp[r][c][k] = double(ans)/8.0;
        return dp[r][c][k];
    }

    
    double knightProbability(int n, int k, int row, int column) {
        N=n;
        vector<vector<vector<double>>>dp(n+1, vector<vector<double>>(n+1, vector<double>(k+1, -1)));
        return solve(row, column, k, dp);
    }
};