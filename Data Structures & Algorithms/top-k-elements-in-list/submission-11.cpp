#define pii pair<int, int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pii, vector<pii>, greater<pii>> topK;

        for (int x : nums) {
            freq[x]++;
        }

        for (auto [x, f] : freq) {
            topK.push(make_pair(f, x));
            if (topK.size() > k) topK.pop();
        }

        vector<int> ans;

        while (!topK.empty()) {
            auto [_, x] = topK.top(); topK.pop();
            ans.push_back(x);
        }

        return ans;
    }
};
