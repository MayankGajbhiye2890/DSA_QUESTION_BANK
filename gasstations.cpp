#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int idx = 0;
        int diff=0;
        int fuel =0;
        int total_diff=0;
        for(int i=0; i<gas.size(); i++){
            diff=gas[i]-cost[i];
            fuel += diff;
            total_diff += diff;
            if(fuel<0){
                fuel=0;
                idx=i+1;
            }
        }
        if(total_diff<0){
            return -1;
        }
        return idx;
    }
};