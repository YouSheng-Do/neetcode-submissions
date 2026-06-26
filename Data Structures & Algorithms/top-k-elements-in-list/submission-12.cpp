class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        for (auto [x, f] : freq) {
            buckets[f].push_back(x);
        }

        vector<int> ans;
        for (int i = n; i >= 0; --i) {
            for (int x : buckets[i]) ans.push_back(x);
            if (ans.size() == k) return ans;
        }

        return ans;
    }
};
