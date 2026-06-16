class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char, int> seen; 
        int n = s.size();

        for (char ch : s)
        {
            seen[ch]++; 
        }

        for (int i = 0; i < n; i++)
        {
            if (seen[s[i]] == 1)
            {
                return i; 
            }
        }
        return -1; 
    }
};