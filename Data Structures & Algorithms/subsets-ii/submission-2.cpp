class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        vector<int> cur;

        backtrack(cur, nums, 0, ans);

        return ans;
    }

    void backtrack(vector<int>& cur, vector<int>& nums, int start, vector<vector<int>>& ans) {
        ans.push_back(cur);

        // pick same val at same level only once
        for (int i = start; i < nums.size(); ++i) {
            if (i != start && nums[i] == nums[i - 1]) continue;
            cur.push_back(nums[i]);
            backtrack(cur, nums, i + 1, ans);
            cur.pop_back();
        }
    }
};
