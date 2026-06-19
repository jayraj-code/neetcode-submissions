class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> window_count(128, 0);
        vector<int> t_count(128, 0);
        int need = 0; 
        
        int window_size = s.size(); 
        int t_size = t.size();
         
        for (int i = 0; i < t_size; i++)
        {
            t_count[t[i]]++; 
        }

        for (int i = 0; i < t_count.size(); i++)
        {
            if (t_count[i] > 0)
            {
                need++; 

            }
            
        }

        int left = 0; 
        int min_len = INT_MAX; 
        int start = 0;
        int have = 0; 

        for (int right = 0; right < s.size(); right++)
        {
            char ch = s[right]; 
            window_count[ch]++; 

            if (t_count[ch] > 0 && window_count[ch] == t_count[ch])
            {
                have++; 
            }

            while (have == need)
            {
                int current_length = right - left + 1; 
                if (current_length < min_len)
                {
                    min_len = current_length; 
                    start = left; 
                }
                
                char leaving_char = s[left]; 
                window_count[leaving_char]--; 

                if (t_count[leaving_char] > 0 && window_count[leaving_char] < t_count[leaving_char])
                {
                    have--; 
                }

                left++; 
            }


        }

        return min_len == INT_MAX ? "" : s.substr(start, min_len); 

    }
};
