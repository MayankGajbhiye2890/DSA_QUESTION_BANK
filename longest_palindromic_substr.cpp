class Solution {
public:
    int longestcommonsubseq(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
        if(i>=s1.length()) return 0;
        if(j>=s2.length()) return 0;
        int ans=0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i]==s2[j]){
            ans += 1+ longestcommonsubseq(i+1, j+1, s1, s2, dp);
        }
        else{
            ans+= 0 + max(longestcommonsubseq(i+1, j, s1, s2, dp), 
            longestcommonsubseq(i, j+1, s1, s2, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        string revstr = s;
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        reverse(revstr.begin(), revstr.end());
        int i=0;
        int j=0;
        return longestcommonsubseq(i, j, s, revstr, dp) ;
    }
};
