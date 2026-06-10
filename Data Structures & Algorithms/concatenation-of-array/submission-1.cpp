#include <iostream> 
#include <vector> 
using namespace std; 

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        int n = nums.size();
        vector <int> ans = nums;  
        ans.insert(ans.end(), nums.begin(), nums.end()); 
        return ans; 
    }
};