# define pii pair<int, int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        unordered_map<int, int> freq;
        for (int& x : nums) {
            freq[x]++;
        }

        for (auto [x, f] : freq) {
            pq.push(make_pair(f, x));
            if (pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }

        return ans;
    }
};
