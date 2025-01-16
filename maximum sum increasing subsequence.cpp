//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution{		
	public:
    
    int recursive(int nums[], int curr, int prev, int n, vector<vector<int>>&dp){
        if(curr>= n){
            return 0;
        }
        int i=0;
        int sum= 0;
        int include = 0;
        
        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        if(prev == -1 || nums[curr]>nums[prev]){
            include = nums[curr] + recursive(nums, curr+1, curr,n, dp);
        }
        int exclude= 0+recursive(nums,curr+1, prev,n,dp);
        dp[curr][prev+1]= max(include, exclude);
        return dp[curr][prev+1];
    }
    
	int maxSumIS(int arr[], int n)  
	{  
	    //int n=arr.size();
	    vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
	    return recursive(arr, 0, -1, n, dp);
	}  
};


int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];
	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";   
        cout << "~" << "\n";
    }
    return 0;
}


// } Driver Code Ends