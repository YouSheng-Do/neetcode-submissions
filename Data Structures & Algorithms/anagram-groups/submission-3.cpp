class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mapping;

        for (string& str : strs) {
            vector<int> arr(26, 0);
            for (char& c : str) {
                arr[c - 'a']++;
            }
            string key;
            for (int i = 0; i < 26; ++i) {
                key += to_string(arr[i]);
                key += '#';
            }
            mapping[key].push_back(str);
        }

        vector<vector<string>> ans;

        for (auto [_, vec] : mapping) {
            ans.push_back(vec);
        }

        return ans;
    }
};
