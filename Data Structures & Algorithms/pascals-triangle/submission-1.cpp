class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // 1. Start with an empty 2D vector (0 rows allocated initially)
        vector<vector<int>> answer; 

        for(int i = 0; i < numRows; i++)
        {
            // 2. Create a row that has exactly (i + 1) elements, all starting at 1
            // This automatically handles your 'j == 0' and 'j == i' boundary conditions!
            vector<int> row(i + 1, 1);

            // 3. Only loop through the INNER elements (skipping index 0 and the last index)
            for (int j = 1; j < i; j++)
            {
                // The current value is the sum of the two numbers directly above it
                row[j] = answer[i - 1][j - 1] + answer[i - 1][j];
            }
            
            // 4. Push this freshly built row into your 2D answer vector
            answer.push_back(row);
        }
        return answer; 
    }
};
