class Solution {
public:
    int findMin(vector<int>& nums) {
        // find the minimum => seperate to two part
        // binary search
        // [............             ,min, ..........]
        // l                  m                      r
        // if min is in (m, r]: <=> nums[m] > nums[r]
        //    l = m + 1
        // [........ ,min,                 ..........]
        // l                  m                      r
        // if min is in [l, m]: <=> nums[m] < nums[r]
        //    r = m

        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[r]) r = m;
            else l = m + 1;
        }

        return nums[r];
    }
};
