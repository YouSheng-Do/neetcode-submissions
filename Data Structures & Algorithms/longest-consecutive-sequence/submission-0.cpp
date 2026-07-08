class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;

        int maxLen = 0;
        for (int& num : nums) {
            uset.insert(num);
        }
        for (int& num : nums) {
            int len = 1;
            int x = num;
            if (uset.count(num + 1)) continue;
            
            while (uset.count(x - 1)) {
                x--;
                len++;
            }
            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};
