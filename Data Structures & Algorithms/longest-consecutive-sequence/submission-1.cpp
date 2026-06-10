class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        int maxlen = 0; 
     
        for (int num : seen)
        {
            if (seen.find(num - 1) == seen.end())
            {
                int current = num;
                int streak = 1;  
                while (seen.find(current + 1) != seen.end())
                {
                    streak++; 
                    current++;
                }
                maxlen = max(maxlen, streak);
            }
        }

    return maxlen;


    }
};
