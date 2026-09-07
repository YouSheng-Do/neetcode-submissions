class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> maxHeap;

        for (int& stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            // pop two heaviest stones
            auto stone1 = maxHeap.top(); maxHeap.pop();
            auto stone2 = maxHeap.top(); maxHeap.pop();

            if (stone1 != stone2) maxHeap.push(abs(stone1 - stone2));
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
