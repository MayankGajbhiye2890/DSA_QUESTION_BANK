#include<bits/stdc++.h>
using namespace std;

//BUY SELL STOCKS 1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=0;
        int l=0, r=1;
        while (r < n) {
            if (prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                maxprofit = max(maxprofit, profit);
            } else {
                l = r;
            }
            r++;
        }
        return maxprofit;
    }
};

//BUY SELL STOCKS 2
class Solution {
public:

    int profitrec(vector<int>&prices, int i, bool buy){
       if(i>=prices.size()) return 0;
       int profit = 0;
       if(buy){
         int buyprofit = profitrec(prices, i+1, 0)- prices[i] ;
         int skip = profitrec(prices, i+1, 1);
         profit = max(buyprofit, skip); 
       }
       else{
         int sellprofit = profitrec(prices, i+1, 1) + prices[i];
         int skip = profitrec(prices, i+1, 0);
         profit = max(sellprofit, skip);
       }
       return profit;
    } 



    int solvedp(vector<int>&prices,int i, bool buy, vector<vector<int>>&dp){
        if(i>=prices.size())return 0;
        int profit=0;
        if(dp[i][buy]!= -1) return dp[i][buy];
        if(buy){
            int buyITprofit= -prices[i] + solvedp(prices,i+1, 0, dp);
            int skipprofit=solvedp(prices,i+1,1,dp);
            profit= max(buyITprofit, skipprofit); 
        }
        else{
            int sellITprofit = prices[i]+solvedp(prices, i+1, 1, dp);
            int skipprofit=solvedp(prices,i+1,0, dp);
            profit= max(sellITprofit, skipprofit); 
        }
        dp[i][buy]=profit;
        return dp[i][buy];
    }



    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        // return solvedp(prices,0, true, dp);
        return profitrec(prices,0, true);
    }
};


//BUY AND SELL3
class Solution {
public:
    int solve(vector<int>&prices, int i, bool buy, int limit){
        if(i>=prices.size() || limit==0 )return 0;
        int profit=0;
        if(buy){
            int buyITprofit= -prices[i] + solve(prices,i+1, 0, limit);
            int skipprofit=solve(prices,i+1,1, limit);
            profit= max(buyITprofit, skipprofit); 
        }
        else{
            int sellITprofit = prices[i]+solve(prices, i+1, 1, limit-1);
            int skipprofit=solve(prices,i+1,0,limit);
            profit= max(sellITprofit, skipprofit); 
        }
        return profit;
    } 


    int solvedp(vector<int>&prices, int i, bool buy, int limit, vector<vector<vector<int>>>&dp){
        if(i>=prices.size() || limit==0 )return 0;
        int profit=0;
        if(dp[i][buy][limit] !=-1) return dp[i][buy][limit];
        if(buy){
            int buyITprofit= -prices[i] + solvedp(prices,i+1, 0, limit, dp);
            int skipprofit=solvedp(prices,i+1,1, limit, dp);
            profit= max(buyITprofit, skipprofit); 
        }
        else{
            int sellITprofit = prices[i]+solvedp(prices, i+1, 1, limit-1, dp);
            int skipprofit=solvedp(prices,i+1,0,limit, dp);
            profit= max(sellITprofit, skipprofit); 
        }
        dp[i][buy][limit]=profit;
        return dp[i][buy][limit];
    }


    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(2, vector<int>(3,-1))); //2= buy or sell, 3=limits(0,1,2)
        //return solve(prices,0,1,2);
        return solvedp(prices,0,1,2,dp);
    }
};

//BUY SELL 4
class Solution {
public:
    // 1 buy sell pair is 1 transaction
    // atmost k transactions
    int solve(vector<int>&prices, int i, bool buy, int limit){
        if(i>=prices.size() || limit==0 )return 0;
        int profit=0;
        if(buy){
            int buyITprofit= -prices[i] + solve(prices,i+1, 0, limit);
            int skipprofit=solve(prices,i+1,1, limit);
            profit= max(buyITprofit, skipprofit); 
        }
        else{
            int sellITprofit = prices[i]+solve(prices, i+1, 1, limit-1);
            int skipprofit=solve(prices,i+1,0,limit);
            profit= max(sellITprofit, skipprofit); 
        }
        return profit;
    } 

    int solvedp(vector<int>&prices, int i, bool buy, int limit, vector<vector<vector<int>>>&dp){
        if(i>=prices.size() || limit==0 )return 0;
        int profit=0;
        if(dp[i][buy][limit] !=-1) return dp[i][buy][limit];
        if(buy){
            int buyITprofit= -prices[i] + solvedp(prices,i+1, 0, limit, dp);
            int skipprofit=solvedp(prices,i+1,1, limit, dp);
            profit= max(buyITprofit, skipprofit); 
        }
        else{
            int sellITprofit = prices[i]+solvedp(prices, i+1, 1, limit-1, dp);
            int skipprofit=solvedp(prices,i+1,0,limit, dp);
            profit= max(sellITprofit, skipprofit); 
        }
        dp[i][buy][limit]=profit;
        return dp[i][buy][limit];
    }



    int maxProfit(int k, vector<int>& prices) {
        //return solve(prices,0,1,k);
        vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1,-1)));
        return solvedp(prices,0,1,k,dp);
    }
};