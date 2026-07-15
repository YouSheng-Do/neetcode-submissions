class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());

        int maxLen = 0;
        
        for (const int& num : uset) {
            if (uset.count(num + 1)) continue;
            int x = num;

            while (uset.count(--x)) {
            }
            maxLen = max(maxLen, num - x);
        }

        return maxLen;
    }
};
