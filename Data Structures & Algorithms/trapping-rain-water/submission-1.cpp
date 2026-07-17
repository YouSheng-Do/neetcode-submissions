class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = height[0], rightMax = height[n - 1];

        int l = 0, r = n - 1;

        int maxArea = 0;
        while (l < r) {
            // move the bar with lower boundary
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);
            if (leftMax <= rightMax) {
                maxArea += leftMax - height[l];
                ++l;
            }
            else {
                maxArea += rightMax - height[r];
                --r;
            }
        }

        return maxArea;
    }
};
