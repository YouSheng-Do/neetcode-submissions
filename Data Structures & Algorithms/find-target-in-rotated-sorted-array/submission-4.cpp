class Solution {
public:
    int search(vector<int>& nums, int target) {
        // two binary search

        // First binary search
        // find minimum element to known the rotation steps = k (we assum right rotation, so 0 <= k < n). n is the nums size
        // if k is in (m, r] <=> nums[m] > nums[r] => l = m + 1;
        // if k is in [l, m] <=> nums[m] < nums[r] => r = m;

        // Second binary search
        // The minimum index k divides nums into two sorted subarrays:
        // [0, k - 1] and [k, n - 1].
        //
        // If target is in [nums[k], nums[n - 1]],
        // search [k, n - 1].
        // Otherwise, search [0, k - 1].

        int k = minSearch(nums);
        int l = 0, r = nums.size() - 1;

        return (nums[k] <= target && target <= nums[r]) ? 
                 binarySearch(nums, target, k, r):
                 binarySearch(nums, target, l, k - 1);

    }
    int minSearch(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) l = m + 1;
            else r = m;
        }

        return r;
    }
    int binarySearch(vector<int>& nums, int target, int l, int r) {

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            if (nums[m] > target) r = m - 1;
            else l = m + 1;
        }

        return -1;
    }
};
