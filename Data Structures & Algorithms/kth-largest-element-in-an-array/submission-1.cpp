class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // O(nlogk)
        priority_queue<int, vector<int>, greater<int>> topK; // minHeap
        for (int& x : nums) {
            topK.push(x);
            while (topK.size() > k) topK.pop();
        }

        return topK.top();
    }
};
