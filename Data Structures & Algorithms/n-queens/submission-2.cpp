class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        unordered_set<int> vertical;
        unordered_set<int> diff;
        unordered_set<int> sum;
        vector<string> board;

        solve(ans, 0, vertical, diff, sum, board, n);

        return ans;
    }

    void solve (vector<vector<string>>& ans, int i, unordered_set<int>& vertical, unordered_set<int>& diff, unordered_set<int>& sum, vector<string>& board, const int n) {
        if (i == n) {
            ans.push_back(board);
            return;
        }
        string s(n, '.');

        for (int j = 0; j < n; ++j) {
            // put "Q" at board[i][j]
            if (!check_vertical(j, vertical) && !check_diagonal(i, j, diff, sum)) {
                s[j] = 'Q';
                board.push_back(s);
                vertical.insert(j);
                diff.insert(i - j);
                sum.insert(i + j);
                solve(ans, i + 1, vertical, diff, sum, board, n);
                s[j] = '.';
                board.pop_back();
                vertical.erase(j);
                diff.erase(i - j);
                sum.erase(i + j);
            }
        }
    }

    // check vertical
    bool check_vertical(int j, const unordered_set<int>& vertical) {
        return vertical.count(j);
    }

    // check diagonal
    bool check_diagonal(int i, int j, const unordered_set<int>& diff, unordered_set<int>& sum) {
        return diff.count(i - j) || sum.count(i + j);
    }
};
