class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;

        int maxLen = 0;
        for (int& num : nums) {
            uset.insert(num);
        }
        for (const int& num : uset) {
            if (uset.count(num + 1)) continue;
            int len = 1;
            int x = num;

            while (uset.count(x - 1)) {
                x--;
                len++;
            }
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};
