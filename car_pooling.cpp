#include <bits/stdc++.h>
using namespace std;

//MAP METHOD
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int>mp;
        for(auto i: trips){
            int cap = i[0];
            int start = i[1];
            int end = i[2];

            mp[start] += cap;
            mp[end] -= cap;
        }

        int sum =0;
        for(auto it: mp){
            sum+= it.second; // at any point of time of the sum exceeds capacity return false
            if(sum > capacity){
                return false;
            }
        }
        return true;
    }
};

//ARRAY METHOD
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       vector<int>mp(1001, 0);
       for(auto v: trips){
            int start = v[1];
            int end = v[2];
            mp[start] += v[0];
            mp[end] -= v[0];
       }
       int sum = capacity;
       for(int i=0; i<1001; i++){
            if(sum>=0){
                sum -= mp[i];
            }
       }
       return sum>=0;

    }
};
