class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // check every pos is 1 or not
        // use bfs to expand the island and mark island to 0
        // count the number of islands

        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int count = 0;
        const int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') continue;
                
                // bfs
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = '0';
                while(!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for (auto [dx, dy] : dirs) {
                        int newX = x + dx, newY = y + dy;
                        if (newX < 0 || newY < 0 || newX >= m || newY >= n) continue;
                        if (grid[newX][newY] == '1') {
                            q.push({newX, newY});
                            grid[newX][newY] = '0';
                        }
                    }
                }

                count++;
            }
        }

        return count;
    }
};
