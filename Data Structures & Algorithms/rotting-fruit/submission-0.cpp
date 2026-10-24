class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // multi-source bfs
        int count = 0; // count the number of fresh fruit
        queue<pair<int, int>> q; // record current rotten fruits

        int minutes = 0;

        const int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) count++;
            }
        }

        while (!q.empty() && count != 0) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [x, y] = q.front(); q.pop();

                for (auto [dx, dy] : dirs) {
                    int nextX = dx + x;
                    int nextY = dy + y;

                    if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || grid[nextX][nextY] != 1) continue;

                    grid[nextX][nextY] = -1;
                    q.push({nextX, nextY});
                    count--;
                }
            }
            minutes++;
        }

        return (count == 0) ? minutes : -1;
    }
};
