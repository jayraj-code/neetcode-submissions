class NumMatrix {
public:
vector<vector<int>> pref;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size(); 
        pref.resize(rows, vector<int>(cols,0));
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                pref[i][j] = matrix[i][j] 
                + (i > 0 ? pref[i-1][j] : 0 )
                + (j > 0 ? pref[i][j-1] : 0 )
                - (i > 0 && j > 0 ? pref[i-1][j-1] : 0); 

            }
        }
        
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = pref[row2][col2];
        if (row1 > 0) sum -= pref[row1 - 1][col2];
        if (col1 > 0) sum -= pref[row2][col1 - 1];
        if (row1 > 0 && col1 > 0) sum += pref[row1 - 1][col1 - 1];
        return sum;
    }

};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */