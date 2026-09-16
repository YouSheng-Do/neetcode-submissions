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
        // minHeap.size() <= maxHeap.size()
        if (minHeap.size() > maxHeap.size()) {
            auto top = minHeap.top(); minHeap.pop();
            maxHeap.push(top);
        }

        // check that if we have to swap or not
        if (!minHeap.empty() && minHeap.top() < maxHeap.top()) {
            auto minimum = minHeap.top(); minHeap.pop();
            maxHeap.push(minimum);
            auto maximum = maxHeap.top(); maxHeap.pop();
            minHeap.push(maximum);
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) 
            return (double) (minHeap.top() + maxHeap.top()) / 2.0;
        return (double) maxHeap.top();
    }
};
