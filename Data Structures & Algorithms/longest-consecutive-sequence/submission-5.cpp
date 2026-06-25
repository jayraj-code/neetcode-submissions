class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; 

        int n = nums.size(); 
        unordered_set<int> seen;

        for (int num : nums)
        {
            seen.insert(num); 

        }

        int max_len = 0; 
        for (int num : seen)
        {
            int current = num;
            if (seen.find(current-1) == seen.end())
            {
                int count = 1; 
                while (seen.find(current + 1) != seen.end())
                {
                    count++;
                    current++; 
                }
                max_len = max(max_len, count);  

            }
        } 

        return max_len; 

        
    }
};
