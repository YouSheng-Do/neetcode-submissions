class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows, cols;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // reverse traversing the grid
        // start from the coast, dfs/bfs to neighbor grids that is equal or higher

        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> toPacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> toAtlantic(rows, vector<bool>(cols, false));

        // from top-left coast

        for (int r = 0; r < rows; ++r) {
            dfs(r, 0, heights, toPacific);
        }

        for (int c = 0; c < cols; ++c) {
            dfs(0, c, heights, toPacific);
        }

        // from bottom-right coast

        for (int r = 0; r < rows; ++r) {
            dfs(r, cols - 1, heights, toAtlantic);
        }

        for (int c = 0; c < cols; ++c) {
            dfs(rows - 1, c, heights, toAtlantic);
        }


        vector<vector<int>> ans;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (toPacific[r][c] && toAtlantic[r][c]) ans.push_back({r, c});
            }
        }

        return ans;
    }
    void dfs(int x, int y, vector<vector<int>>& heights, vector<vector<bool>>& toOcean) {
        if (toOcean[x][y]) return;

        toOcean[x][y] = true;

        for (auto [dx, dy] : dirs) {
            int nextX = x + dx;
            int nextY = y + dy;
            if (nextX < 0 || nextX >= rows || nextY < 0 || nextY >= cols || heights[nextX][nextY] < heights[x][y]) continue;

            dfs(nextX, nextY, heights, toOcean);
        }
    }
};
