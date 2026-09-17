class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};

        // for loop num in nums
        // for every subset has been recorded
        // add nums[i] and add it into ans

        for (int& num : nums) {
            int sz = ans.size();
            for (int i = 0; i < sz; ++i) {
                vector<int> subset = ans[i];
                subset.push_back(num);
                ans.push_back(subset);
            }
        }

        return ans;
    }
};
