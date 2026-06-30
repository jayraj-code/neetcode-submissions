class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> seen;
        int n = strs.size(); 

        for(string s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            seen[key].push_back(s);    
        }

        vector<vector<string>> result; 
        for (auto& pair : seen)
        {
            result.push_back(pair.second); 
        }
        return result; 
    }
};
