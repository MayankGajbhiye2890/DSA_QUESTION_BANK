#include <bits/stdc++.h>
using namespace std;


//FIND ALL PALINDROMES IN A STRING
void findpalindromes(string s, int l, int r, vector<string>&palindromes){
    while(l>=0 && r<s.length() && s[l]==s[r]){
        palindromes.push_back(s.substr(l, r-l +1));
        l--;
        r++;
    }
}
vector<string> findpalindrome(string &s){
    vector<string>palindromes;
    for(int i=0; i<s.length();  i++){
        findpalindromes(s, i, i, palindromes);
        findpalindromes(s, i, i+1, palindromes);
    }
    return palindromes;
}
int main() {
    string s = "ababa";
    vector<string> result = findpalindrome(s);

    for (const string &palindrome : result) {
        cout << palindrome << endl;
    }

    return 0;
}

//LONGEST COMMON SUBSEQUENCE
class Solution {
public:

    int recursive(string a, string b, int i, int j){
        if(i== a.length()){
            return 0;
        }
        if(j == b.length()){
            return 0;
        }
        int ans=0;
        if(a[i]==b[j]){
            ans = 1+ recursive(a,b,i+1,j+1);
        }
        else{
            ans = 0+max(recursive(a,b,i,j+1), recursive(a,b,i+1, j));
        }
        return ans;
    }
    
     
    int memo(string &a, string &b, int i, int j, vector<vector<int>>&dp){
        if(i== a.length()){
            return 0;
        }
        if(j == b.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(a[i]==b[j]){
            ans = 1+ memo(a,b,i+1,j+1, dp);
        }
        else{
            ans = 0+max(memo(a,b,i,j+1, dp), memo(a,b,i+1, j,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        vector<vector<int>>dp(text1.length(), vector<int>(text2.length(), -1));
        // return recursive(text1, text2, i, j);/
        // return memo(text1, text2, i, j, dp);
    }
}; 