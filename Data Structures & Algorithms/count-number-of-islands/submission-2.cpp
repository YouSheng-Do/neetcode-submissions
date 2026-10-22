class Solution {
public:
    int m, n;
    vector<pair<int, int>> dirs;
    int numIslands(vector<vector<char>>& grid) {
        // dfs version
        dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int count = 0;

        m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') continue;

                dfs(grid, i, j);
                count++;
            }
        }

        return count;
    }
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') return;

        grid[i][j] = '0';
        for (auto [dx, dy] : dirs) {
            int newX = i + dx;
            int newY = j + dy;
            dfs(grid, newX, newY);
        }
    }
};
