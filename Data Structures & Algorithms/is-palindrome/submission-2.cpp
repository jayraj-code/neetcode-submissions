class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned_string = ""; 
        for (char c : s)
        {
            if (isalnum(c))
            {
                cleaned_string.push_back(tolower(c)); 
            }
        }

        int left = 0; 
        int right = cleaned_string.size() - 1;

        while (left <= right)
        {
            if (cleaned_string[left] == cleaned_string[right])
            {
                left++;
                right--; 
            }
            else
            {
                return false; 
            }
        }
        
        return true; 
    }
};
