class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int i = mid / n;
            int j = mid % n;
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) r = mid - 1;
            else l = mid + 1;
        }

        return false;
    }
};
