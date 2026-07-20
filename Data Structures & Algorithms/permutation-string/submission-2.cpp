class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // s1 = "abc", s2 = "lecabee"
        //                    ^ *
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> freq1; // O(26)
        unordered_map<char, int> freq2; // O(26)


        int i = 0, j = s1.size() - 1;

        for(int k = i; k <= j; ++k) {
            freq1[s1[k]]++;
            freq2[s2[k]]++;
        }

        int match = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (freq1[c] == freq2[c]) match++;
        }

        while (j < s2.size()) {
            if (i != 0) {
                char prev = s2[i - 1], cur = s2[j];
                if (prev != cur) {
                    freq2[prev]--;
                    freq2[cur]++;
                    if (freq2[prev] == freq1[prev]) match++;
                    else if (freq2[prev] == freq1[prev] - 1) match--;
                    if (freq2[cur] == freq1[cur]) match++;
                    else if (freq2[cur] == freq1[cur] + 1) match--;
                }
            }
            if (match == 26) return true;
            ++i; ++j;
        }

        return false;
    }
};
