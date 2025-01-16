class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        vector<pair<int, int>>v;
        for(int i=0; i<nums.size(); i++){
            pair<int,int>p=make_pair(nums[i],i);
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        int start=0;
        int end=nums.size()-1;
        while(start<end){
            if(v[start].first+v[end].first==target){
                ans.push_back(v[start].second);
                ans.push_back(v[end].second);
                break;
            }
            if(v[start].first+v[end].first>target){
                end--;
            }
            else{
                start++;
            }
        }
        return ans;
    }
};