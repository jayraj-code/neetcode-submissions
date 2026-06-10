class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        // Initialize with fixed size to avoid repeated resizing overhead
        vector<int> ans(2 * n); 
        
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];       // Fill first half
            ans[i + n] = nums[i];   // Fill second half simultaneously
        }
        return ans;
    }
};
