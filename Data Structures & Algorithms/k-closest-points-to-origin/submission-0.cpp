#define pii pair<int,int>

class Solution {
public:
    struct cmp {
        bool operator()(pii& coord1, pii& coord2) {
            auto [x1, y1] = coord1;
            auto [x2, y2] = coord2;
            return x1 * x1 + y1 * y1 < x2 * x2 + y2 * y2;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // k closest points
        priority_queue<pii, vector<pii>, cmp> maxHeap;

        for (auto& p : points) {
            maxHeap.push(make_pair(p[0], p[1]));
            if (maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> ans;

        while (!maxHeap.empty()) {
            auto [x, y] = maxHeap.top(); maxHeap.pop();

            ans.push_back({x, y});
        }

        return ans;
    }
};
