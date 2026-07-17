class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;

        int i = 0, j = 0;
        int n = s.size();
        int longest = 0;
        while (j < n) {
            if (freq.count(s[j])) {
                while (s[i] != s[j]) {
                    freq[s[i]]--;
                    if (freq[s[i]] == 0) freq.erase(s[i]);
                    ++i;
                }
                ++i;
            }
            else {
                freq[s[j]]++;
            }
            longest = max(longest, j - i + 1);
            ++j;
        }

        return longest;
    }
};
