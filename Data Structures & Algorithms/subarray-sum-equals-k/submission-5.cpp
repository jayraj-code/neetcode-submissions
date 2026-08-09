class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> freq; 
        int count = 0; 
        int prefix_sum = 0; 
        freq[prefix_sum]++; 

        for(int i = 0; i < nums.size(); i++)
        {
            prefix_sum += nums[i]; 
            int need = prefix_sum - k; 
            if (freq.count(need))
            {
                count += freq[need]; 
            }
            freq[prefix_sum]++; 
        }

        return count; 
        
    }
};