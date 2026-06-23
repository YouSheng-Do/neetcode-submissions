class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val_to_index;

        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            if (val_to_index.count(target - val)) {
                return {val_to_index[target - val], i};
            }
            val_to_index[nums[i]] = i;
        }

        return {};
    }
};
