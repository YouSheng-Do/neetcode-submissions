class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // use nums to record those seen numbers
        // record x in nums[x], mark nums[x] = 0
        // keep checking all the number

        int idx = 0;
        for (int x : nums) {
            idx = abs(x) - 1;
            if (nums[idx] < 0) return abs(x);
            nums[idx] *= -1;
        }

        return -1;
    }
};
