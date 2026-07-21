class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        // s = "OUZODYXAZVXYZ", t = "XYZ"
        //                ^ *

        // check freq t and s

        unordered_map<char, int> freq_t, freq_s;

        for (int i = 0; i < t.size(); ++i) {
            freq_t[t[i]]++;
            freq_s[s[i]]++;
        }

        int match = 0; // match == 52
        for (int i = 0; i < 26; ++i) {
            if (freq_t['a' + i] <= freq_s['a' + i]) match++;
            if (freq_t['A' + i] <= freq_s['A' + i]) match++;
        }

        int l = 0, r = t.size();
        int minIndex = match == 52 ? 0 : -1;
        int minLen = match == 52 ? t.size() : s.size() + 1;

        while (r <= s.size()) {
            // cout << s.substr(l, r - l) << endl;
            // cout << match << endl;
            if (match == 52) {
                while (freq_s[s[l]] - 1 >= freq_t[s[l]]) {
                    // cout << freq_s[s[l]] << " " << freq_t[s[l]] << endl;
                    freq_s[s[l]]--;
                    ++l;
                } 
                if (r - l < minLen) {
                    minLen = min(minLen, r - l);
                    minIndex = l;
                }
                // cout << s.substr(l, r - l) << endl;
                // cout << match << endl;
            }
            if (r == s.size()) break;
            if (minIndex != -1) {
                if (freq_s[s[l]] == freq_t[s[l]]) {
                    match--;
                }
                freq_s[s[l]]--;
                ++l;
            }

            if (freq_s[s[r]] == freq_t[s[r]] - 1) {
                match++;
            }
            freq_s[s[r]]++;
            ++r;
        }

        return minIndex != -1 ? s.substr(minIndex, minLen) : "";
    }
};
