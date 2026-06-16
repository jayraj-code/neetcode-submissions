class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(); 
        unordered_map<char , int> seen; 
        int left = 0; 
        int max_len = 0; 

        for (int i = 0; i < n; i++)
        {
            char current_char = s[i];
            if (seen.find(current_char) != seen.end() && seen[current_char] >= left)
            {
                left = seen[current_char] + 1; 

            }
            seen[current_char] = i; 
            max_len = max(max_len, i - left + 1); 

        }
        return max_len; 
        
    }
};
