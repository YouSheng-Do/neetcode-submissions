class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // [-2, -2, -1, -1, 2, 3] target = 1
        //           ^   ^  ^   

        // sort to make sure that same numbers are adjacent
        
        // Time : O(n^2)
        // Spcace : O(n)

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            // duplicate case
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                // duplicate case
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    ++j;
                    continue;
                }
                int target = -nums[i];
                int sum = nums[j] + nums[k];
                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (sum > target) {
                    k--;
                }
                else {
                    j++;
                }

                // duplicate case
                while (k > j + 1 && nums[k] == nums[k + 1]) {
                    k--;
                }
            }
        }

        return ans;
    }
};
