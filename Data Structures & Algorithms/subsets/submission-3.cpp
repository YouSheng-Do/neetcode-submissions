class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;

        backtrack(nums, 0, cur, ans);

        return ans;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& cur, vector<vector<int>>& ans) {
        ans.push_back(cur);

        for (int i = start; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            backtrack(nums, i + 1, cur, ans);
            cur.pop_back();
        }
    }
};
