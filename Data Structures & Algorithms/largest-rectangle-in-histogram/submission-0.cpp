class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // brute force method:
        // for each bar heights[i], find the max width that extend from both left and right side
        // scan from left to right, so for the case heights[i] == heights[i - 1], skip
        // O(n^2)

        // monotonic stack
        // find left and right boundary for heights[i]
        // simplify by merge and find left boundary
        // increasing stack

        stack<pair<int, int>> mono_st; // pair = (height, left_boundary)
        int maxArea = 0;
        const int n = heights.size();
        for (int i = 0; i < n; ++i) {
            int left_boundary = i;
            int cur_h = heights[i];
            while (!mono_st.empty() && cur_h < mono_st.top().first) {
                auto [h, l] = mono_st.top(); mono_st.pop();
                maxArea = max(maxArea, (i - l) * h);
                left_boundary = l;
            }
            if (!mono_st.empty() && cur_h == mono_st.top().first) continue;
            
            mono_st.push({cur_h, left_boundary});
        }

        while (!mono_st.empty()) {
            auto [h, l] = mono_st.top(); mono_st.pop();
            maxArea = max(maxArea, (n - l) * h);
        }

        return maxArea;
    }
};
