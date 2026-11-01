class Solution {
public:
    int rows, cols;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        // start from edge
        // record all the cells with 'O' that connect to edge
        // traverse all the 2d grid
        // if a cell with 'O' hasn't been recorded, mark it to 'X'
        rows = board.size();
        cols = board[0].size();

        unordered_set<int> visited;

        for (int r = 0; r < rows; ++r) {
            if (board[r][0] == 'O')
                dfs(r, 0, board, visited);
            if (board[r][cols - 1] == 'O')
                dfs(r, cols - 1, board, visited);
        }
        
        for (int c = 0; c < cols; ++c) {
            if (board[0][c] == 'O')
                dfs(0, c, board, visited);
            if (board[rows - 1][c] == 'O')
                dfs(rows - 1, c, board, visited);
        }

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == 'O' && !visited.count(encode(r, c))) board[r][c] = 'X';
            }
        }
    }

    void dfs(int x, int y, vector<vector<char>>& board, unordered_set<int>& visited) {
        int enc = encode(x, y);
        if (visited.count(enc)) return;

        visited.insert(enc);

        for (auto [dx, dy] : dirs) {
            int nextX = x + dx;
            int nextY = y + dy;
            if (nextX < 0 || nextX >= rows || nextY < 0 || nextY >= cols || board[nextX][nextY] == 'X') continue;
            dfs(nextX, nextY, board, visited);
        }
    }
    int encode(int x, int y) { return x * cols + y; }
};
