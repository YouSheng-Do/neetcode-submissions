class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> anagrams;

        for (auto s : strs) {
            vector<int> freq(26, 0);
            for (auto c : s) {
                freq[c - 'a']++;
            }
            string key;
            for (int i = 0; i < 26; ++i) {
                key += '#';
                key += freq[i];
            }
            anagrams[key].push_back(s);
        }

        for (auto [_, v] : anagrams) {
            ans.push_back(v);
        }

        return ans;
    }
};
