class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alphabet(26, 0);

        for (auto c : s) {
            alphabet[c - 'a']++;
        }

        for (auto c : t) {
            alphabet[c - 'a']--;
        }

        for (int x : alphabet) {
            if (x != 0) return false;
        }

        return true;
    }
};
