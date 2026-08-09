class Solution {
public:
    int findMin(vector<int> &nums) {
        // l, m, r

        // l < m && m < r => r = m - 1

        // l < m && m > r => l = m + 1

        // l > m && m < r => r = m - 1

        // l > m && m > r => it won't happen

        // end condition:
        // if (nums[(m-1+n)%n] > nums[m]) return nums[m];
        
        const int n = nums.size();
        if (n == 1) return nums[0];
        int l = 0, r = n - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[(m-1+n)%n] > nums[m]) return nums[m];
            if (nums[m] > nums[r]) l = m + 1;
            else r = m - 1;
        }

        return -1;
    }
};
