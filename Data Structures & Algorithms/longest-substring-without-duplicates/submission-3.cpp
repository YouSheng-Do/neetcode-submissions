class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mapping;
        int ans = 0;

        int i = 0, j = 0;
        while (j < s.size()) {
            if (mapping.count(s[j]) && mapping[s[j]] >= i) {
                i = mapping[s[j]] + 1;
            }
            mapping[s[j]] = j;
            ans = max(j - i + 1, ans);
            ++j;
        }

        return ans;
    }
};
