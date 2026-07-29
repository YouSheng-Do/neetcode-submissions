class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> maxHeap;
        vector<int> ans;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            maxHeap.push(make_pair(nums[i], i));
            if (i >= k - 1) {
                while (maxHeap.top().second <= i - k) maxHeap.pop();
                ans.push_back(maxHeap.top().first);
            }
        }

        return ans;
    }
};
