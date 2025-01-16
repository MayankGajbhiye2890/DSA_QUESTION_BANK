#include<bits/stdc++.h>
using namespace std;

//YHI HAI ACTIVITY SELECTION PROBLEM
class Solution {   
    static bool cmp(pair<int, int>a, pair<int, int>b){
        return a.second<b.second;
    }
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int> start, vector<int> end) {
       vector<pair<int, int>>v;
       
       for(int i=0; i<start.size(); i++){
           pair<int, int>p = make_pair(start[i], end[i]);
           v.push_back(p);
       }
       
       sort(v.begin(), v.end(), cmp);
       
       int count = 1;
       int ans_end = v[0].second;
       
       for(int i = 1; i<v.size(); i++){
           if(v[i].first > ans_end){
               count++;
               ans_end = v[i].second;
           }
       }
       return count;
    }
};

