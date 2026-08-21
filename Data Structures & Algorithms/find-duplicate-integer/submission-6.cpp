class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // bit manipulation
        // if there's only one repeated interger and this value appear only twice
        // we can solve it by ^= x in nums and x in range [1, n]
        // so that the two identical numbers cancel out each other 
        // so the result woulde left the only repeated interger.
        // However, the only repeated interger may appear more than once.
        // Consider manipulate bit by bit
        // count how many numbers have 1-bit on bit[i]
        // if count of nums < count of [1, n], nums must lack x in [1, n] has 1-bit on bit[i]
        // if count of nums > count of [1, n], nums must contain x has 1-bit on bit[i] and x appear more than once.

        int res = 0;
        const int n = nums.size() - 1;
        for(int bit = 0; bit < 32; ++bit) {
            int mask = 1 << bit; // ..000010000..
            int count_nums = 0, count_range = 0;

            for (int x : nums) {
                if (mask & x) count_nums++;
            }
            for (int x = 1; x <= n; ++x) {
                if (mask & x) count_range++;
            }

            if (count_nums > count_range) res |= mask;
        }

        return res;
    }
};