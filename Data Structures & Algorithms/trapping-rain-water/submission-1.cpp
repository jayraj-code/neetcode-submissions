class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); 
        if (n <= 2)
        {
            return 0; 
        }

        int left = 0, right = n-1;
        int left_max = height[0], right_max = height[n-1]; 
        int water = 0; 

        while (left <= right)
        {
            if (left_max < right_max)
            {
                water += left_max - height[left];
                left++; 
                if (left <= right)
                {
                    left_max = max(left_max , height[left]);
                }
            }

            else 
            {
                water += right_max - height[right];
                right--;
                if (left <= right)
                {
                    right_max = max(right_max, height[right]);

                }
            }
        }
        return water; 
        
    }
};
