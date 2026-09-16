class MedianFinder {
public:
    priority_queue<int> maxHeap; // smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap; // larger half
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // add number to larger half
        // if (minHeap.size() > maxHeap.size()) 
        // pop from minHeap and add it to maxHeap
        minHeap.push(num);

        // maintain size
        // minHeap.size() == maxHeap.size()
        // or minHeap.size() + 1 == maxHeap.size()
        if (minHeap.size() > maxHeap.size()) {
            auto top = minHeap.top(); minHeap.pop();
            maxHeap.push(top);
        }

        // maintain ordering
        // maxHeap.top() <= minHeap.top()
        if (!minHeap.empty() && minHeap.top() < maxHeap.top()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) 
            return ((double)minHeap.top() + maxHeap.top()) / 2.0;
        return (double) maxHeap.top();
    }
};
