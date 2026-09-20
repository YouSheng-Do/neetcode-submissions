class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort
        sort(candidates.begin(), candidates.end());

        // [2, 2, 2, 2]
        // [true, true, true, true]
        // [false, true, true, true]
        // [false, false, true, true]
        // [false, false, false, true]
        // [false, false, false, false]
        // backtracking

        vector<vector<int>> ans;
        vector<int> cur;

        backtrack(cur, 0, candidates, false, target, ans);

        return ans;
    }
    void backtrack(vector<int>& cur, int i, const vector<int>& nums, bool pickPrev, int target, vector<vector<int>>& ans) {
        // if (target == 0) ans.push_back(cur); return;
        // if i out of the boundary => return
        // if nums[i] > target => return

        // pick this index

        // without this index
        // if (!pickPrev || candidates[i] != cnadidates[i - 1])
        if (target == 0) {
            if (i < nums.size() && nums[i] == nums[i - 1])
        return;
            ans.push_back(cur);
            return;
        }

        if (i >= nums.size() || nums[i] > target) return;

        // pick
        cur.push_back(nums[i]);
        backtrack(cur, i + 1, nums, true, target - nums[i], ans);
        cur.pop_back();
        
        // without pick
        if (!pickPrev || nums[i] != nums[i - 1]) {
            backtrack(cur, i + 1, nums, false, target, ans);
        }

    }
};
