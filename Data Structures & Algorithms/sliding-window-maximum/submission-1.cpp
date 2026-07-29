class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<pair<int, int>> mono_q;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            while (!mono_q.empty() && (num > mono_q.front().first || mono_q.front().second <= i - k)) {
                mono_q.pop_front();
            }
            while (!mono_q.empty() && num > mono_q.back().first) {
                mono_q.pop_back();
            }
            mono_q.push_back(make_pair(num, i));
            if (i >= k - 1) {
                ans.push_back(mono_q.front().first);
                // cout << mono_q.front().first << endl;
            }
        }
        
        return ans;
    }
};
