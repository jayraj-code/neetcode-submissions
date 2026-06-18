class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0; 
        int n = nums.size();
        int min_len = INT_MAX;
        int window_sum = 0; 

        for (int right = 0; right < n; right++)
        {
            window_sum += nums[right];

            while (window_sum >= target)
            {
                min_len = min(right - left + 1, min_len);
                window_sum = window_sum - nums[left];
                left++; 
            }   

        } 
        
        return min_len == INT_MAX ? 0 : min_len; 
    }
};