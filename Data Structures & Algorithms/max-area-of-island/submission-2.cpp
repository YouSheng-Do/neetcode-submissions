class Solution {
public:
    vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // dfs
        int maxArea = 0;

        m = grid.size(), n = grid[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;

                int area = 0;
                dfs(grid, i, j, area);

                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int& area) {
        area++;
        grid[i][j] = 0;

        for (auto [dx, dy] : dirs) {
            int nextX = i + dx;
            int nextY = j + dy;
            if (nextX < 0 || nextY < 0 || nextX >= m || nextY >= n || grid[nextX][nextY] == 0) continue;
            dfs(grid, nextX, nextY, area);
        }
    }
};
