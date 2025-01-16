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