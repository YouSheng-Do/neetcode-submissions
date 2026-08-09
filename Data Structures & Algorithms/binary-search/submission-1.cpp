class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (target < nums[0]) return -1;
        int l = 0, r = nums.size();
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) return m;
            if (nums[m] > target) {
                r = m;
            }
            else {
                l = m;
            }
        }

        return nums[l] == target ? l : -1;
    }
};
