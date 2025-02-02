#include <bits/stdc++.h> 
using namespace std;

//frog jump
int solve(int n, vector<int> &heights, vector<int>&dp){
    if(n==0) return 0;
    int right = INT_MAX;
    if(dp[n] != -1) return dp[n];
    int left = solve(n-1, heights, dp) + abs(heights[n]-heights[n-1]);
    if(n>1){
        right = solve(n-2, heights, dp) + abs(heights[n] - heights[n-2]);
    }
    return dp[n] = min(right, left);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1, -1);
    return solve(n-1, heights, dp);
}

//climbing stairs
int climbStairs(int n) {
        //dp aproach
      if(n<=0) return 0;
      else if(n<=1) return 1;
      else{
          vector<int>stairs(n+1);
          stairs[0]=1;
          stairs[1]=1;
          for(int i=2; i<=n; i++){
              stairs[i]=stairs[i-2] + stairs[i-1];
          }
          return stairs[n];
      }      
  }


class Solution {
public:
    int climbStairs(int n) {
      //dp aproach
      int prev1 = 1;
      int prev2 = 1;
    
        for (int i = 2; i <= n; i++) {
          int curr = prev1 + prev2;
          prev2 = prev1;
          prev1 = curr;
      }
      return prev1;
    }
};
