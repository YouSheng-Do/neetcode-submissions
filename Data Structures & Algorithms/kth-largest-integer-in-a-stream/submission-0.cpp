class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (const int& x : nums) {
            minHeap.push(x);
            if (minHeap.size() > k) minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
};
