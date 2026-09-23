class Solution {
public:
    int m, n;
    bool exist(vector<vector<char>>& board, string word) {
        // dfs
        m = board.size();
        n = board[0].size();

        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        unordered_set<int> used;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, 0, i, j, used, dirs)) {
                    // cout << i << " " << j << endl;
                    return true;
                }
            }
        }

        return false;
    }
    bool dfs(vector<vector<char>>& board, const string& word, int idx, int i, int j, unordered_set<int>& used, const vector<vector<int>>& dirs) {
        if (idx == word.size()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (used.count(i * n + j)) return false;

        if (board[i][j] == word[idx]) {
            used.insert(i * n + j);
            // cout << i << " " << j << endl;
            for (const auto& dir : dirs) {
                if (dfs(board, word, idx + 1, i + dir[0], j + dir[1], used, dirs)) 
                return true;
            }
            used.erase(i * n + j);
        }

        return false;
    }
};
