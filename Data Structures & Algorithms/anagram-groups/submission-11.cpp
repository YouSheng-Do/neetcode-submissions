class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string& s : strs) {
            vector<int> freq(26, 0);
            for (char c : s) {
                freq[c - 'a']++;
            }

            string key = "";
            for (int f : freq) {
                key += "#";
                key += f;
            }

            groups[key].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto [_, v] : groups) {
            ans.push_back(v);
        }

        return ans;
    }
};
