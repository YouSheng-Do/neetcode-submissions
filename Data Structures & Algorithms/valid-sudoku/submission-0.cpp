class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row_digits(9);
        vector<unordered_set<int>> column_digits(9);
        vector<unordered_set<int>> submetrice_digits(9);
        
        const int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                int metrices_index = i / 3 * 3 + j / 3;
                if (row_digits[i].count(num)) return false;
                if (column_digits[j].count(num)) return false;
                if (submetrice_digits[metrices_index].count(num)) return false;
                row_digits[i].insert(num);
                column_digits[j].insert(num);
                submetrice_digits[metrices_index].insert(num);
            }
        }

        return true;
    }
};
