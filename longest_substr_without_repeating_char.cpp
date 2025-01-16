#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char>ans;
        int p1=0, p2=0, maxlength=0;
        int n = s.size();
        
        while(p2<n){
            auto i = find(ans.begin(), ans.end(), s[p2]);
            if(i==ans.end()){
                ans.push_back(s[p2]);
                maxlength = max(maxlength, p2 - p1 + 1);
                p2++;
            }
            else{
                ans.erase(ans.begin());
                p1++;
            }
        }
        return maxlength;
    }
};