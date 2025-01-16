//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        
        for(int i=0; i<arr.size(); i++){
            pq.push(arr[i]);
        }
        
        long long cost =0;
        
        while(pq.size() > 1){
            long long first = pq.top();
            pq.pop();
            
            long long second = pq.top();
            pq.pop();
            
            long long mergedcost = first + second;
            cost += mergedcost;
            
            pq.push(mergedcost);
            
        }
        return cost;
    }
    
};
