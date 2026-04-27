class Solution {
public:
    struct ArrHash {
        size_t operator()(const array<int, 26>& arr) const {
            size_t h = 0;
            for (int x : arr) {
                h = h * 131u + std::hash<int>()(x);
            }
            return h;
        }
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<array<int, 26>, vector<string>, ArrHash> mapping;

        for (const string& str : strs) {
            array<int, 26> arr{};
            for (char c : str) {
                arr[c - 'a']++;
            }
            
            mapping[arr].push_back(str);
        }

        vector<vector<string>> ans;

        for (auto& [_, vec] : mapping) {
            ans.push_back(vec);
        }

        return ans;
    }
};
