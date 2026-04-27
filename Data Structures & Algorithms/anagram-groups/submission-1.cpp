class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapping;

        for (string& str : strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            mapping[copy].push_back(str);
        }

        vector<vector<string>> ans;

        for (auto [_, vec] : mapping) {
            ans.push_back(vec);
        }

        return ans;
    }
};
