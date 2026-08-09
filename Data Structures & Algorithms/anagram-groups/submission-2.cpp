class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans; 
        int n = strs.size();
        unordered_map<string, vector<string>> freq;  

        for (string s : strs)
        {
            string sorted_string = s;
            sort(sorted_string.begin(), sorted_string.end()); 
            freq[sorted_string].push_back(s); 
        }
        for (auto& entry: freq)
        {
            ans.push_back({entry.second}); 
        }
        return ans; 
        
    }
};
