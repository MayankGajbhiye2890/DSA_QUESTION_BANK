#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        vector<int>tempinterval=intervals[0];
        for(auto ch: intervals){
            if(ch[0] <= tempinterval[1]){
                tempinterval[1] = max(ch[1], tempinterval[1]);
            }
            else{
                ans.push_back(tempinterval);
                tempinterval = ch;
            }
        }
        ans.push_back(tempinterval);
        return ans;
    }
};


//INSERT AND MERGE INTERVALS
void merge(vector<int>&intervals, vector<int>&newinterval){
    vector<int>res;
    int n = intervals.size();
    while(i<n && intervals[i][1]<newinterval[0]){
        res.push_back(intervals[i]);
        i++;
    }
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);
    while (i < n) {
        res.push_back(intervals[i]);
        i++;
    }

    return res;
}
