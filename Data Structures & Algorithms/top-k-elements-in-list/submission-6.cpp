class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int& num : nums) {
            freqMap[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& [num, f] : freqMap) {
            bucket[f].push_back(num);
        }

        vector<int> ans;

        for (int i = bucket.size() - 1; i >= 0; --i) {
            for (int& x : bucket[i]) {
                ans.push_back(x);
                if (ans.size() == k) return ans;
            }
        }

        return {};
    }
};
