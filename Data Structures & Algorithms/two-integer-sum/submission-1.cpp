class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapping; // [key, value] = nums[i], i

        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            int left = target - nums[i];
            if (mapping.count(left)) {
                ans.push_back(mapping[left]);
                ans.push_back(i);
                return ans;
            }
            mapping[nums[i]] = i;
        }

        return ans;
    }
};
