class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // generate new subset from previous
        // avoid duplicate
        vector<vector<int>> ans = {{}};

        sort(nums.begin(), nums.end());

        vector<int> temp;
        int sz;

        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                temp.clear();
                sz = ans.size();
            }
            temp.push_back(nums[i]);
            for (int j = 0; j < sz; ++j) {
                vector<int> new_subset = ans[j];
                new_subset.insert(new_subset.end(), temp.begin(), temp.end());
                ans.push_back(new_subset);
            }
        }

        return ans;
    }
};
