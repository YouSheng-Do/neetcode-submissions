class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;

        int i = 0, j = 0;
        int n = s.size();
        int longest = 0;
        while (j < n) {
            if (charIndex.count(s[j]) && charIndex[s[j]] >= i) {
                i = charIndex[s[j]] + 1;
            }
            charIndex[s[j]] = j;
            longest = max(longest, j - i + 1);
            ++j;
        }

        return longest;
    }
};
