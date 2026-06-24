class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<vector<bool>> rows(9, vector<bool>(10, false));
        vector<vector<bool>> cols(9, vector<bool>(10, false));
        vector<vector<bool>> boxes(9, vector<bool>(10, false));

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {

                if (board[r][c] == '.')
                    continue;

                int digit = board[r][c] - '0';

                int box = (r / 3) * 3 + (c / 3);

                if (rows[r][digit] ||
                    cols[c][digit] ||
                    boxes[box][digit]) {
                    return false;
                }

                rows[r][digit] = true;
                cols[c][digit] = true;
                boxes[box][digit] = true;
            }
        }

        return true;
    }
};