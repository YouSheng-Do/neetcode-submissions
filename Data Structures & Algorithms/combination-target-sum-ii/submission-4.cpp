class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort
        sort(candidates.begin(), candidates.end());

        // backtracking
        vector<vector<int>> ans;
        vector<int> cur;

        backtrack(cur, 0, candidates, target, ans);

        return ans;
    }
    void backtrack(vector<int>& cur, int start, const vector<int>& nums, int target, vector<vector<int>>& ans) {
        // if (target == 0) ans.push_back(cur); return;
        // if i out of the boundary => return
        // if nums[i] > target => return

        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicates at the same recursion level
            if (i > start && nums[i] == nums[i - 1]) continue;
            if (nums[i] > target) return;

            // pick nums[i]
            cur.push_back(nums[i]);
            backtrack(cur, i + 1, nums, target - nums[i], ans);
            cur.pop_back();
        }

    }
};
