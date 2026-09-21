class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // use bit mask instead of unordered_set
        vector<vector<int>> ans;
        vector<int> cur;
        int mask = (1 << nums.size()) - 1; // 1111111...

        backtrack(cur, mask, nums, ans);

        return ans;
    }
    void backtrack(vector<int>& cur, int mask, vector<int>& nums, vector<vector<int>>& ans) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }

        // bit mask
        for (int i = 0; i < nums.size(); ++i) {
            if (mask & (1 << i)) {
                cur.push_back(nums[i]);
                backtrack(cur, mask & (~(1 << i)), nums, ans);
                cur.pop_back();
            }
        }
    }
};
