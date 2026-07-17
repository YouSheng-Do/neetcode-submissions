class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        vector<int> prefixMax(n, 0), suffixMax(n, 0);

        for (int i = 1; i < n; ++i) {
            prefixMax[i] = max(prefixMax[i - 1], height[i - 1]);
        }
        for (int i = n - 2; i >= 0; --i) {
            suffixMax[i] = max(suffixMax[i + 1], height[i + 1]);
        }

        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int h = min(prefixMax[i], suffixMax[i]);
            if (h > height[i]) maxArea += h - height[i];
        }

        return maxArea;
    }
};
