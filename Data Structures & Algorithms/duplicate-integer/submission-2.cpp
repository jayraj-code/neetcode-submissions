#include <unordered_set>
#include <vector>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_set <int> check; 
        for (int x: nums)
        {
            if (check.find(x) != check.end()) 
            {
                return true;
            }
            check.insert(x);
        }
        
        return false; 

    }
};
