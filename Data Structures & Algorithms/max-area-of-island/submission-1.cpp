class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // bfs
        int maxArea = 0;

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        const int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;

                int area = 0;
                queue<pair<int, int>> q;
                
                q.push({i, j});
                grid[i][j] = 0;
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    area++;
                    for (auto [dx, dy] : dirs) {
                        int nextX = x + dx;
                        int nextY = y + dy;
                        if (nextX < 0 || nextY < 0 || nextX >= m || nextY >= n || grid[nextX][nextY] == 0) continue;
                        
                        q.push({nextX, nextY});
                        grid[nextX][nextY] = 0;
                    }   
                }
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
