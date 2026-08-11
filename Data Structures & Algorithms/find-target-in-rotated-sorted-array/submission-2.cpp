class Solution {
public:
    int search(vector<int>& nums, int target) {
        // two binary search

        // First binary search
        // find minimum element to known the rotation steps = k (we assum right rotation, so 0 <= k < n). n is the nums size
        // if k is in (m, r] <=> nums[m] > nums[r] => l = m + 1;
        // if k is in [l, m] <=> nums[m] < nums[r] => r = m;

        // Second binary search
        // int l = 0, r = nums.size() - 1;
        // every term, we have to get index of m
        // the index after rotation is (m + k) % n
        // if (nums[m] == target) return true;
        // if (nums[m] > target) r = m - 1;
        // else l = m + 1;
        // when l > r, that means no answer => return -1;

        int k = minSearch(nums);

        return binarySearch(nums, k, target);

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
    int binarySearch(vector<int>& nums, int k, int target) {
        const int n = nums.size();
        int l = 0, r = n - 1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            int rotated = (m+k)%n;
            if (nums[rotated] == target) return rotated;
            if (nums[rotated] > target) r = m - 1;
            else l = m + 1;
        }

        return -1;
    }
};
