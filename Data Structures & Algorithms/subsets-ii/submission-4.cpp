class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        vector<int> cur;

        backtrack(cur, nums, 0, ans);

        return ans;
    }

    void backtrack(vector<int>& cur, vector<int>& nums, int i, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(cur);
            return;
        }

        // pick 
        cur.push_back(nums[i]);
        backtrack(cur, nums, i + 1, ans);
        cur.pop_back();
        
        ++i;
        while (i < nums.size() && nums[i] == nums[i - 1]) ++i;

        // not pick
        backtrack(cur, nums, i, ans);
    }
};
