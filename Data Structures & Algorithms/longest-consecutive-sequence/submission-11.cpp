class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end()); 

        int max_count = 0;

        if (nums.empty())
        {
            return 0; 
        }

        for(int i : nums)
        {
            int current = i; 

            if (!seen.count(current-1))
            {
               int count = 1; 

                while(seen.count(current+1))
                {
                    count++; 
                    current++; 
                }
                max_count = max(count , max_count); 
            }

        } 
        return max_count; 
    }
};
