class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val_to_index;

        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            int diff = target - val;
            if (val_to_index.count(diff)) {
                return {val_to_index[diff], i};
            }
            val_to_index[val] = i;
        }

        return {};
    }
};
