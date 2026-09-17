class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        
        // bit mask
        int n = nums.size();

        for (int i = 0; i < (1 << n); ++i) {
            vector<int> subset;
            for (int bit = 0; bit < n; ++bit) {
                if ((1 << bit) & i) {
                    subset.push_back(nums[bit]);
                }
            }
            ans.push_back(subset);
        }

        return ans;
    }
};
