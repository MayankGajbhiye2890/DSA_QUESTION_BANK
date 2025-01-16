#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<string>&wordDict, string&s){
        for(auto i: wordDict){
            if(s==i) return true;
        }
        return false;
    }
    int solve(string&s, vector<string>&wordDict, int start){
        if(start == s.size()) return true;
        string word= ""; 
        bool flag=false;
        for(int i = start; i<=s.size(); i++){
            word += s[i];
            if(check(wordDict, word)){
                flag = flag || solve(s, wordDict, i+1);
            }
        }
        return flag;
    }

    int solvedp(string& s, vector<string>& wordDict, int start, vector<int>& dp) {
    if (start == s.size()) return true;
    if (dp[start] != -1) return dp[start];
    
    string word = "";
    bool flag = false;
    
    for (int i = start; i < s.size(); i++) {
        word += s[i];
        if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
            flag = flag || solvedp(s, wordDict, i + 1, dp);
        }
    }
    
    dp[start] = flag;
    return dp[start];
}


    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+10, -1);
        //return solve(s, wordDict, 0);
        return solvedp(s, wordDict, 0, dp);
    }
};


//WORD BREAK USING stack

class Solution {
public:
    unordered_set<string> st;
    bool solverec(int idx, int n, string &s){
        if(idx == n){
            return true;
        }

        if(st.find(s) != st.end()){
            return true;
        }

        for(int l=1; l<n; l++){
            string temp = s.substr(idx,l);
            if(st.find(temp) != st.end() && solverec(idx+l,n,s)){
                return true;
            }
        }

        return false;
    }
    bool solvemem(int idx, int n, string &s,vector<int> &dp){
        if(idx == n){
            return true;
        }

        if(dp[idx] != -1){
            return dp[idx];
        }

        if(st.find(s) != st.end()){
            return true;
        }

        for(int l=1; l<n; l++){
            string temp = s.substr(idx,l);
            if(st.find(temp) != st.end() && solvemem(idx+l,n,s,dp)){
                return dp[idx] = true;
            }
        }

        return dp[idx]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        for(string word: wordDict){
            st.insert(word);
        }    

        // return solverec(0,n,s);
        return solvemem(0,n,s,dp);
    }
};
