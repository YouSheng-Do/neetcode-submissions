class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row_digits(9);
        vector<unordered_set<int>> column_digits(9);
        vector<unordered_set<int>> submatrix_digits(9);
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                int matrix_index = i / 3 * 3 + j / 3;
                if (row_digits[i].count(num)) return false;
                if (column_digits[j].count(num)) return false;
                if (submatrix_digits[matrix_index].count(num)) return false;
                row_digits[i].insert(num);
                column_digits[j].insert(num);
                submatrix_digits[matrix_index].insert(num);
            }
        }

        return true;
    }
};
