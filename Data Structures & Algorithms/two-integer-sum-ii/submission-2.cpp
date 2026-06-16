class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map <int, int> seen;

        for(int i = 0; i < n; i++)
        {
            int complement = target - numbers[i]; 
            if (seen.find(complement) != seen.end())
            {
                return {seen[complement] + 1, i+1};
            }
            else
            {
                seen[numbers[i]] = i; 
            }
            
        }
        return{}; 
    }
};
