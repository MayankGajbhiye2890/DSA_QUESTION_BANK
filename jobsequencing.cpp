//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job {
    int id;       // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is over before or on deadline
};


// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int deadline; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution {
  public:
    // Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a, Job b) {
        return a.profit > b.profit; // Sort in descending order of profit
    }

    vector<int> JobScheduling(Job arr[], int n) {
        // Sort jobs based on descending profit
        sort(arr, arr + n, cmp);
        
        // Find the maximum deadline
        int maxiDeadline = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxiDeadline = max(maxiDeadline, arr[i].deadline);
        }
        
        vector<int> schedule(maxiDeadline + 1, -1); // Schedule array
        int count = 0;
        int maxprofit = 0;
        
        for (int i = 0; i < n; i++) {
            int currprofit = arr[i].profit;
            int currjobid = arr[i].id;
            int currdeadline = arr[i].deadline;
            
            for (int k = currdeadline; k > 0; k--) {
                if (schedule[k] == -1) { // If slot is empty
                    schedule[k] = currjobid;
                    maxprofit += currprofit;
                    count++;
                    break;
                }
            }
        }
        
        vector<int> ans;
        ans.push_back(count);      
        ans.push_back(maxprofit); 
        return ans;
    }
};
