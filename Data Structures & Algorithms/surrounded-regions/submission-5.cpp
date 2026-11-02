class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // multi-source bfs
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        unordered_set<int> visited;

        queue<pair<int, int>> q;

        const int ROWS = board.size(), COLS = board[0].size();

        auto encode = [=](int x, int y) {
            return x * COLS + y;
        };

        for (int r = 0; r < ROWS; ++r) {
            if (board[r][0] == 'O') {
                visited.insert(encode(r, 0));
                q.push({r, 0});
            }
            if (board[r][COLS - 1] == 'O') {
                visited.insert(encode(r, COLS - 1));
                q.push({r, COLS - 1});
            }
        }

        for (int c = 1; c < COLS - 1; ++c) {
            if (board[0][c] == 'O') {
                visited.insert(encode(0, c));
                q.push({0, c});
            }
            if (board[ROWS - 1][c] == 'O') {
                visited.insert(encode(ROWS - 1, c));
                q.push({ROWS - 1, c});
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            for (auto [dx, dy] : dirs) {
                int nextX = x + dx;
                int nextY = y + dy;

                if (nextX < 0 || nextX >= ROWS || nextY < 0 || nextY >= COLS || board[nextX][nextY] == 'X' || visited.count(encode(nextX, nextY))) continue;

                visited.insert(encode(nextX, nextY));
                q.push({nextX, nextY});
            }
        }

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (board[r][c] == 'X') continue;
                if (visited.count(encode(r, c))) continue;
                board[r][c] = 'X';
            }
        }
    }
};
