//for arrays

class Solution {
public:
    void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans) {
        if(index == nums.size()) {
            ans.push_back(nums); 
            return; 
        }
        for(int i = index;i<nums.size();i++) {
            swap(nums[index], nums[i]); 
            recurPermute(index+1, nums, ans); 
            swap(nums[index], nums[i]); //swapping again because we want original string when we are backtracking 
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};

//for strings

#include <bits/stdc++.h>
using namespace std;

void recurPermute(int index, string &s, vector<string> &ans) {
    
    if (index == s.size()) {
        ans.push_back(s);
        return;
    }
    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);
        recurPermute(index + 1, s, ans);
        swap(s[index], s[i]);
    }
}

vector<string> findPermutation(string &s) {

    vector<string> ans;
    recurPermute(0, s, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s = "ABC";
    vector<string> res = findPermutation(s);
    for(auto x: res) {
        cout << x << " ";
    }
    return 0;
}
