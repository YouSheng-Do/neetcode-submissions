class Solution {
public:
    int characterReplacement(string s, int k) {
        // s = "XYYXAB", k = 2
        //         ^
        //            ^
        // X : 1
        // Y : 1
        // A : 1
        // B : 1

        unordered_map<char, int> freq;
        int i = 0, j = 0, maxLen = 1;
        while (j < s.size()) {
            // move j
            freq[s[j]]++;
            int major = 0;
            for (auto [_, f] : freq) {
                major = max(major, f);
            }

            while (k < (j - i + 1) - major) {
                // move i
                freq[s[i]]--;
                ++i;
                for (auto [_, f] : freq) {
                    major = max(major, f);
                }
            }

            maxLen = max(maxLen, j - i + 1);
            ++j;
        }

        return maxLen;
    }
};
