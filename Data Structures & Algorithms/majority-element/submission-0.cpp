class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> seen;
        int count = 0;
        int max_value = INT_MIN; 
        int max_key = INT_MIN; 

        for (int i = 0; i < nums.size(); i++)
        {
          seen[nums[i]]++; 
        }
        
        for (auto& pair : seen)
        {
            if (pair.second > max_value)
            {
                max_value = pair.second; 
                max_key = pair.first; 
            }
        }

        return max_key; 
    }
};