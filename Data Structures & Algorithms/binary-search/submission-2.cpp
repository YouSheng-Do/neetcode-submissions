class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size() - 1, target);
    }
    int binary_search(vector<int>& nums, int l, int r, int target) {
        if (l > r) return -1;
        int m = l + (r - l) / 2;
        if (nums[m] == target) return m;
        if (nums[m] > target) return binary_search(nums, l, m - 1, target);
        return binary_search(nums, m + 1, r, target);
    }
};
