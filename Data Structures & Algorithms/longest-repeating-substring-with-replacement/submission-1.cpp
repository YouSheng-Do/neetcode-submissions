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
        int maxFreq = 0;
        while (j < s.size()) {
            freq[s[j]]++;
            maxFreq = max(maxFreq, freq[s[j]]);

            // move the window if it's not valid
            if ((j - i + 1) - maxFreq > k) {
                freq[s[i]]--;
                ++i;
            }

            maxLen = max(maxLen, j - i + 1);
            ++j;
        }

        return maxLen;
    }
};
