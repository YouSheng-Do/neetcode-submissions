class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // bitmask
        vector<int> col(9, 0), row(9, 0), submatrix(9, 0);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';

                int submatrix_index = i / 3 * 3 + j / 3;
                if (col[i] & (1 << num)) return false;
                if (row[j] & (1 << num)) return false;
                if (submatrix[submatrix_index] & (1 << num)) return false;

                col[i] |= (1 << num);
                row[j] |= (1 << num);
                submatrix[submatrix_index] |= (1 << num);
            }
        }

        return true;
    }
};
