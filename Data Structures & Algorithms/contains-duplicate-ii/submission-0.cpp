class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> seen; 
        int n = nums.size(); 
        for (int i = 0; i < n; i ++)
        {
            int current_num = nums[i];
            if (seen.find(current_num) != seen.end())
            {
                int last_occurence = seen[current_num]; 
                if (i - last_occurence <= k)
                {
                    return true;
                }
            }
            
            seen[current_num] = i; 

        }
        return false;
        
    }
};