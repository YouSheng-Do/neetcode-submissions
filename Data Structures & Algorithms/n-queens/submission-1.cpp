class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        unordered_set<int> vertical;
        vector<pair<int, int>> indices;
        vector<string> board;

        solve(ans, 0, vertical, indices, board, n);

        return ans;
    }

    void solve (vector<vector<string>>& ans, int i, unordered_set<int>& vertical, vector<pair<int, int>>& indices, vector<string>& board, const int n) {
        if (i == n) {
            ans.push_back(board);
            return;
        }
        string s(n, '.');

        for (int j = 0; j < n; ++j) {
            // put "Q" at board[i][j]
            if (!check_vertical(j, vertical) && !check_diagonal(i, j, indices)) {
                s[j] = 'Q';
                board.push_back(s);
                vertical.insert(j);
                indices.push_back({i, j});
                solve(ans, i + 1, vertical, indices, board, n);
                s[j] = '.';
                board.pop_back();
                vertical.erase(j);
                indices.pop_back();
            }
        }
    }

    // check vertical
    bool check_vertical(int j, const unordered_set<int>& vertical) {
        return vertical.count(j);
    }

    // check diagonal
    bool check_diagonal(int i, int j, const vector<pair<int, int>>& indices) {
        for (auto [x, y] : indices) {
            if (abs(x - i) == abs(y - j)) return true;
        }

        return false;
    }
};
