class Solution {
public:

    bool checkpalindrome(string s, int i , int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true; 
    }

    bool validPalindrome(string s) {
        int n = s.size(); 
        int left = 0; 
        int right = n-1; 

        while (left < right)
        {
            if (s[left] == s[right])
            {
                left++;
                right--;                  
            }

            else
            {
                return checkpalindrome(s, left+1, right)||
                checkpalindrome(s, left, right-1); 
            }
        }

        return true; 
        
    }
};