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


//3 sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Step 1: Sort the array
    
        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
    
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;
    
            while (left < right) {
                int sum = nums[left] + nums[right];
    
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
    
                    // Skip duplicates for the second and third elements
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum < target) {
                    left++; // Move the left pointer to increase the sum
                } else {
                    right--; // Move the right pointer to decrease the sum
                }
            }
        }
        return result;
    }
};
