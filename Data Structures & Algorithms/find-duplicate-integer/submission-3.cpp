class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int b = 0; b < 32; ++b) {
            int x = 0, y = 0;
            int mask = 1 << b;
            for (int num : nums) {
                if (num & mask) ++x;
            }
            for (int i = 1; i < n; ++i) {
                if (i & mask) ++y;
            }
            if (x > y) res |= mask;
        }
        return res;
    }
};
