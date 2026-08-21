class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // traverse the vector
        // val = abs(nums[i])
        // check that if nums[val] < 0 or not
        // if (nums[val] < 0) return val;
        // else mark nums[val] = -nums[val];
        // Time complexity : O(n)
        // Space complexity : O(1)
        for (int x : nums) {
            int abs_x = abs(x);
            if (nums[abs_x] < 0) return abs_x;
            nums[abs_x] = -nums[abs_x];
        }

        return -1;
    }
};
