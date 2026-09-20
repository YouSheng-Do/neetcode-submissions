class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // [0, 1, 2, 3...]
        // [0, 2, 1, 3...]
        vector<vector<int>> ans;
        vector<int> cur;

        unordered_set<int> used;

        backtrack(nums, used, cur, ans);

        return ans;
    }
    void backtrack(vector<int>& nums, unordered_set<int>& used, vector<int>& cur, vector<vector<int>>& ans) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used.count(nums[i])) continue;
            cur.push_back(nums[i]);
            used.insert(nums[i]);
            backtrack(nums, used, cur, ans);
            used.erase(nums[i]);
            cur.pop_back();
        }
    }
};
