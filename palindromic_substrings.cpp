#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int expand(string &s, int i, int j){
        int count = 0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int count=0;
        int n = s.length();
        for(int i=0; i<n; i++){
            count = count + expand(s, i, i+1) + expand(s,i,i);
        }
        return count;

    }
};