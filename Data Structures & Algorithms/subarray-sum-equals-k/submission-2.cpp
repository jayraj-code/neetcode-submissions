class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); 
        unordered_map <int, int> prefix_freq;
        int current_prefix = 0;    
        int count = 0; 
        int j = 0; 
        prefix_freq[0] = 1; 
        

        for (int i = 0; i < n; i++)
        {
            current_prefix += nums[i]; 

            if (prefix_freq.find(current_prefix - k) != prefix_freq.end())
            {
                count += prefix_freq[current_prefix - k]; 
            }
            prefix_freq[current_prefix]++;
        }

        return count; 

    }
};