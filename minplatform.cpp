#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int>& arr, vector<int>& dep) {
        
        vector<pair<int, int>>v;
        for(int i=0; i< arr.size(); i++){
            pair<int, int>p = make_pair(arr[i], dep[i]);
            v.push_back(p);
        }
        
        sort(v.begin(), v.end());
        int count=1;//assuming 1st rain entered
        
        priority_queue<int, vector<int>, greater<int>>pq;
        pq.push(v[0].second);//departure of 1st train;
        
        for(int i=1; i<v.size(); i++){
            if(v[i].first>pq.top()){
                pq.pop();
                pq.push(v[i].second);
            }
            else{
                count++;
                pq.push(v[i].second);
            }
        }
        return count;
}
