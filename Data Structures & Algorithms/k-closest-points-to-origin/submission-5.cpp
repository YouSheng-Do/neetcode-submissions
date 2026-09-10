class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // quick select
        // every term
        // pick one pivot and partition points into two kinds
        // points closer than pivot, partition to left part
        // points farther than pivot, partition to right part

        // so we know the correct pos of pivot in points
        // if pos == k, return the left part
        // else if pos < k, select new pivot in right part
        // else, select new pivot in left part

        // T(n) = T(n/2) + T(n/4) + T(n/8)....
        //      = O(n)

        int l = 0, r = points.size() - 1;
        int pos = points.size();

        while (pos != k) {
            pos = partition(points, l, r);
            // cout << pos << endl;
            if (pos > k) r = pos - 1;
            else l = pos + 1;
        }

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
private:
    int partition(vector<vector<int>>& points, int l, int r) {
        // return the correct pos for pivot
        int pivotIdx = r;
        int count = 0;

        long long dis = euclidean(points[pivotIdx]);
        for (int i = l; i < r; ++i) {
            // if euclidean(i) < euclidean(pivot), swap to front
            if (euclidean(points[i]) < dis) {
                swap(points[i], points[l + count]);
                count++;
            }
        }
        swap(points[pivotIdx], points[l + count]);

        return l + count;
    }
    long long euclidean(vector<int>& p) {
        return p[0] * p[0] + p[1] * p[1];
    }
};
