#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix; 
        prefix[0] = 1; 
        
        int total = 0; 
        int count = 0; 
        
        for (int num : nums)
        {
            total += num; 
            int need = total - k; 
            
            if (prefix.count(need))
            {
                count += prefix[need];
            }
            
            prefix[total]++; 
        }
        
        return count; 
    }
};
