class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set <int> seen; 
        for (int i : nums)
        {
            if (seen.count(i))
            {
                return i; 
            }
            else
            {
                seen.insert(i); 
            }
        }
        return -1; 
        
    }
};
