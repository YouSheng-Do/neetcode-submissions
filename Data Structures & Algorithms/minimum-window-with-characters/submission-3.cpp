class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        // s = "OUZODYXAZVXYZ", t = "XYZ"
        //                ^ *

        // check freq t and s

        unordered_map<char, int> freq_t, window;

        for (char c : t) {
            freq_t[c]++;
        }

        int match = 0; // match == freq_t.size()

        int l = 0, r = 0;
        int minIndex = -1;
        int minLen = INT_MAX;

        while (r < s.size()) {
            char c = s[r];
            window[c]++;
            if (freq_t.count(c) && window[c] == freq_t[c]) match++;
            while (match == freq_t.size()) {
                // cout << s.substr(l, r - l + 1) << endl;
                if (r - l + 1< minLen) {
                    minLen = r - l + 1;
                    minIndex = l;
                }
                window[s[l]]--;
                if (freq_t.count(s[l]) && window[s[l]] == freq_t[s[l]] - 1) match--;
                ++l;
            }
            // cout << s.substr(l, r - l + 1) << endl;
            ++r;
        }

        return minIndex != -1 ? s.substr(minIndex, minLen) : "";
    }
};
