#include<bits/stdc++.h>
using namespace std;    
    
class Solution {
public:    
     int solve(int i, int j, string s1, string s2){
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(s1[i] == s2[j]) return 0+ solve(i-1, j-1, s1,s2);
        return 1+ min( solve(i, j-1, s1, s2), min(solve(i-1, j, s1,s2), solve(i-1, j-1, s1, s2)));
    }
    int solve(int i, int j, string s1, string s2){
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(s1[i] == s2[j]) return 0+ solve(i-1, j-1, s1,s2);
        return 1+ min( solve(i, j-1, s1, s2), min(solve(i-1, j, s1,s2), solve(i-1, j-1, s1, s2)));
    }

    int solvedp(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {       
        if (i < 0) return j + 1; 
        if (j < 0) return i + 1; 
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j]) return dp[i][j] = solvedp(i - 1, j - 1, s1, s2, dp);
        return dp[i][j] = 1 + min(solvedp(i - 1, j, s1, s2, dp), // delete
                                  min(solvedp(i, j - 1, s1, s2, dp), // insert
                                      solvedp(i - 1, j - 1, s1, s2, dp))); // replace
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();     
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solvedp(n - 1, m - 1, word1, word2, dp);
    }
};