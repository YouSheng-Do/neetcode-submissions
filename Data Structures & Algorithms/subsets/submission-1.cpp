class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        generate(nums, 0, cur, ans);

        return ans;
    }
    void generate(vector<int>& nums, int i, vector<int>& cur, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        generate(nums, i + 1, cur, ans);
        cur.pop_back();
        generate(nums, i + 1, cur, ans);
    }
};
