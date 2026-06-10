#include <iostream> 
#include <vector> 
using namespace std; 

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        int n = nums.size();
        vector <int> ans = nums;  

        for (int x : nums)
        {
            ans.push_back(x); 
        }
        return ans; 
    }
};