class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set <char>> box_row(9); 
        vector<unordered_set <char>> box_column(9); 
        vector<unordered_set <char>> box(9); 

        for (int r = 0; r < 9; r++){
            for (int c = 0; c < 9; c++){
                
                char ch = board[r][c]; 
                if (ch == '.') continue;

                int box_index = (r / 3) * 3 + (c / 3); 
                if (box_row[r].count(ch) || box_column[c].count(ch) || box[box_index].count(ch))
                {
                    return false; 
                }

                box_row[r].insert(ch);
                box_column[c].insert(ch);
                box[box_index].insert(ch);
            }
    
        }
        return true;
    }
};
