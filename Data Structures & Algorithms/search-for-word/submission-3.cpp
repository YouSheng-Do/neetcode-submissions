class Solution {
public:
    int m, n;
    bool exist(vector<vector<char>>& board, string word) {
        // dfs + in-place replacement
        m = board.size();
        n = board[0].size();

        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, 0, i, j, dirs)) {
                    return true;
                }
            }
        }

        return false;
    }
    bool dfs(vector<vector<char>>& board, const string& word, int idx, int i, int j, const vector<vector<int>>& dirs) {
        if (idx == word.size()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n) return false;

        if (board[i][j] == word[idx]) {
            // mark board[i][j] as used
            auto c = board[i][j];
            board[i][j] = '#';
            for (auto dir : dirs) {
                if (dfs(board, word, idx + 1, i + dir[0], j + dir[1], dirs)) 
                return true;
            }
            board[i][j] = c;
        }

        return false;
    }
};
