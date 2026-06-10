class Solution {
public:
    bool check_palindrome(const string& s, int i, int j){
        while (i < j)
        {
            if(s[i] != s[j])
            {
                return false; 
            }
            i++;
            j--; 

        }

        return true;
    }

    bool validPalindrome(string s){
        int n = s.size();
        int left = 0;
        int right = n-1; 
        
        while(left < right)
        {
            if (s[left] == s[right])
            {
                left++;
                right--;
            }
            else
            {
                return check_palindrome(s, left+1, right)||
                check_palindrome(s, left, right-1); 
            }
        }
        return true; 
    }
};