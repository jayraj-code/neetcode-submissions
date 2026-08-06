class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index; 
        int n = nums.size(); 

        for(int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if(index.count(complement))
            {
                return {index[complement], i};
            }
            else
            {
                index[nums[i]] = i; 
            }
        }
        
    }
};
