class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> cur;

        generate(nums, 0, target, cur, ans);

        return ans;
    }
    void generate(vector<int>& nums, int i, int target, vector<int>& cur, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        if (i >= nums.size() || target < nums[i]) return;

        // add nums[i]
        cur.push_back(nums[i]);
        generate(nums, i, target - nums[i], cur, ans);
        cur.pop_back();

        // skip nums[i]
        generate(nums, i + 1, target, cur, ans);
    }
};
