class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0, right = n-1; 
        int max_amount = 0;

        while(left < right)
        {
            int width = right - left; 
            int area = width * min(heights[left], heights[right]);
            max_amount = max(max_amount, area);

            if (heights[left] < heights[right])
            {
                left++; 
            } 
            else
            {
                right--; 
            }
        }

        return max_amount; 
    }
};
