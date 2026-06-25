class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> seen;

        for (char ch : s)
        {
            seen[ch]++;
        }

        for (char ch : t)
        {
            seen[ch]--; 
        }

        for (auto pair : seen)
        {
            if (seen[pair.first] != 0)
            {
                return false; 
            }
        }

        return true; 
        
    }
};
