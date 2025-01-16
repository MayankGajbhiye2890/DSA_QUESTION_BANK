class Solution {
public:
    //infinite transactions with transaction fees
     int solve(vector<int>&prices, int i, bool buy, int&fees){
        if(i>=prices.size())return 0;
        int profit=0;
        if(buy){
            int buyITprofit= -prices[i] + solve(prices,i+1, 0, fees);//sell-buy-fees
            int skipprofit=solve(prices,i+1,1,fees);
            profit= max(buyITprofit, skipprofit); 
        }
        else{
            int sellITprofit = prices[i]+solve(prices, i+1, 1, fees)-fees;
            int skipprofit=solve(prices,i+1,0,fees);
            profit= max(sellITprofit, skipprofit); 
        }
        return profit;
    } 
    int solvedp(vector<int>&prices, int i, bool buy, int&fees, vector<vector<int>>&dp){
        if(i>=prices.size())return 0;
        int profit=0;
        if(dp[i][buy]!= -1) return dp[i][buy];
        if(buy){
            int buyITprofit= -prices[i] + solvedp(prices,i+1, 0, fees, dp);//sell-buy-fees
            int skipprofit=solvedp(prices,i+1,1,fees, dp);
            profit= max(buyITprofit, skipprofit); 
        }
        else{
            int sellITprofit = prices[i]+solvedp(prices, i+1, 1, fees, dp)-fees;
            int skipprofit=solvedp(prices,i+1,0,fees, dp);
            profit= max(sellITprofit, skipprofit); 
        }
        dp[i][buy]=profit;
        return dp[i][buy];
    } 

    int maxProfit(vector<int>& prices, int fee) {
        int n= prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        //return solve(prices,0,1,fee);
        return solvedp(prices,0,1,fee, dp);
    }
};