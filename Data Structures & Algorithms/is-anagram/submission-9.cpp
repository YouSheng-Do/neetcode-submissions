class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> diff;

        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); ++i) {
            diff[s[i]]++;
            diff[t[i]]--;
        }

        for (auto [_, v] : diff) {
            if (v != 0) return false;
        }

        return true;
    }
};
