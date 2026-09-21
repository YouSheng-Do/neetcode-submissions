class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // brute force
        set<vector<int>> ans;

        vector<int> cur;
        sort(nums.begin(), nums.end());
        
        backtrack(nums, cur, 0, ans);

        return vector<vector<int>>(ans.begin(), ans.end());
    }

    void backtrack(vector<int>& nums, vector<int>& cur, int idx, set<vector<int>>& ans) {
        ans.insert(cur);

        for (int i = idx; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            backtrack(nums, cur, i + 1, ans);
            cur.pop_back();
        }
    }
};
