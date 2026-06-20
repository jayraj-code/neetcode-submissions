class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(); 
        unordered_map <int, int> seen;

        for (int i = 0; i < n; i ++)
        {
            int element = target - nums[i]; 
            if(seen.find(element) != seen.end())
            {
                return {seen[element], i};
            }
            else
            {
                seen[nums[i]] = i; 
            }
        }
        return {}; 
        
    }
};
