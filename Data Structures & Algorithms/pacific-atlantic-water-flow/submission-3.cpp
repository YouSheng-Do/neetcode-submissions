class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows, cols;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // reverse traversing the grid
        // start from the coast, traverse to neighbor grids that is equal or higher
        // bfs

        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> toPacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> toAtlantic(rows, vector<bool>(cols, false));

        // from top-left coast

        for (int r = 0; r < rows; ++r) {
            bfs(r, 0, heights, toPacific);
        }

        for (int c = 0; c < cols; ++c) {
            bfs(0, c, heights, toPacific);
        }

        // from bottom-right coast

        for (int r = 0; r < rows; ++r) {
            bfs(r, cols - 1, heights, toAtlantic);
        }

        for (int c = 0; c < cols; ++c) {
            bfs(rows - 1, c, heights, toAtlantic);
        }


        vector<vector<int>> ans;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (toPacific[r][c] && toAtlantic[r][c]) ans.push_back({r, c});
            }
        }

        return ans;
    }
    void bfs(int x, int y, const vector<vector<int>>& heights, vector<vector<bool>>& toOcean) {
        if (toOcean[x][y]) return;
        
        queue<pair<int, int>> q;

        q.push({x, y});
        toOcean[x][y] = true;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (auto [dx, dy] : dirs) {
                int nextX = x + dx;
                int nextY = y + dy;

                if (nextX < 0 || nextX >= rows || nextY < 0 || nextY >= cols || toOcean[nextX][nextY] || heights[nextX][nextY] < heights[x][y]) continue;
                q.push({nextX, nextY});
                toOcean[nextX][nextY] = true;
            }
        }
    }
};
