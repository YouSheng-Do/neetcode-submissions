class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows, cols;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};

        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> toPacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> toAtlantic(rows, vector<bool>(cols, false));

        vector<pair<int, int>> pacificStarts;
        vector<pair<int, int>> atlanticStarts;

        for (int r = 0; r < rows; ++r) {
            pacificStarts.push_back({r, 0});
            atlanticStarts.push_back({r, cols - 1});
        }

        for (int c = 0; c < cols; ++c) {
            pacificStarts.push_back({0, c});
            atlanticStarts.push_back({rows - 1, c});
        }

        bfs(pacificStarts, heights, toPacific);
        bfs(atlanticStarts, heights, toAtlantic);

        vector<vector<int>> ans;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (toPacific[r][c] && toAtlantic[r][c]) {
                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }

    void bfs(
        const vector<pair<int, int>>& starts,
        const vector<vector<int>>& heights,
        vector<vector<bool>>& toOcean
    ) {
        queue<pair<int, int>> q;

        for (auto [r, c] : starts) {
            if (toOcean[r][c]) continue;  // 避免角落重複加入
            toOcean[r][c] = true;
            q.push({r, c});
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dirs) {
                int nextX = x + dx;
                int nextY = y + dy;

                if (nextX < 0 || nextX >= rows ||
                    nextY < 0 || nextY >= cols ||
                    toOcean[nextX][nextY] ||
                    heights[nextX][nextY] < heights[x][y]) {
                    continue;
                }

                toOcean[nextX][nextY] = true;
                q.push({nextX, nextY});
            }
        }
    }
};