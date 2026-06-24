class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen; 
        int n = nums.size(); 
        int max_len = 0; 

        for (int i : nums)
        {
            seen.insert(i); 
        }
        
        for (int i = 0; i < n; i++)
        {
            int current = nums[i]; 
            if (seen.find(current-1) == seen.end())
            {
                int count = 1; 
                while (seen.find(current+1) != seen.end())
                {
                    count ++; 
                    current++; 
                }
                
                max_len = std::max(max_len , count); 
                
            }
            

        }

        return max_len; 
    }
};
