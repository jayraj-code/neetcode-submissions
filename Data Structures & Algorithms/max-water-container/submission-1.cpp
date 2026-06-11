class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(); 
        int curr_area = 0; 

        for (int i = 0; i < n-1 ; i ++)
        {
            for (int j = 1; j < n; j++)
            {
                int width = j - i; 
                int area = width * min(heights[i], heights[j]);
                curr_area = max(curr_area, area); 

            }
        }
        return curr_area; 
    }
};
