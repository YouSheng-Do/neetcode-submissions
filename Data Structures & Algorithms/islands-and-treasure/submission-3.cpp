class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int m, n;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        // multi-source bfs
        
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    q.push(make_pair(i, j));
                }
            }
        }

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (auto [dx, dy] : dirs) {
                int nextX = x + dx;
                int nextY = y + dy;
                
                if (nextX < 0 || nextY < 0 || nextX >= m || nextY >= n || grid[nextX][nextY] == -1) continue;

                if (grid[nextX][nextY] != INT_MAX) continue;
                q.push(make_pair(nextX, nextY));
                grid[nextX][nextY] = grid[x][y] + 1;
            }
        }
    }
};
