class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapping;

        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            if (mapping.count(target - nums[i])) {
                if (mapping[target - nums[i]] > i) {
                    ans.push_back(i);
                    ans.push_back(mapping[target - nums[i]]);
                }
                else {
                    ans.push_back(mapping[target - nums[i]]);
                    ans.push_back(i);
                }
            }
            mapping[nums[i]] = i;
        }
        
        return ans;
    }
};
