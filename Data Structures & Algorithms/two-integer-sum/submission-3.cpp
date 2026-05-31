class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mapping; // val -> index
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (mapping.count(diff)) return {mapping[diff], i};
            mapping[nums[i]] = i;
        }
        return ans;
    }
};
