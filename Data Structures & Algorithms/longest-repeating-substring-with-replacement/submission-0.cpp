class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(); 
        unordered_map<char, int> frequency_map; 
        int max_freq = 0; 
        int max_len = 0; 
        int left = 0; 

        for (int right = 0; right < n; right++)
        {
            char curr = s[right]; 
            frequency_map[curr]++;
            max_freq = max(max_freq, frequency_map[curr]); 

            while ((right - left + 1) - max_freq > k)
            {
                frequency_map[s[left]]--;
                left++; 
            }
            max_len = max(max_len, right - left + 1); 
        }
        return max_len; 
        
    }
};
