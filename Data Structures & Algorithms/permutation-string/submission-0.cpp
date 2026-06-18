class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int string_size = s2.size();
        int window_size = s1.size(); 

        if (window_size > string_size)
        {
            return false; 
        }

        vector<int> window_count(26, 0);
        vector<int> string_count(26, 0);

        for(int i = 0; i < window_size; i++ )
        {
            int index = s1[i] - 'a';
            window_count[index]++; 
        }

        for(int i = 0; i < window_size; i++ )
        {
            int index = s2[i] - 'a';
            string_count[index]++; 
        }

        if (window_count == string_count)
        {
            return true; 
        }

        for (int i = window_size; i < string_size; i++)
        {
            int index = s2[i] - 'a';
            string_count[index]++;

            int remove_index = s2[i - window_size] - 'a'; 
            string_count[remove_index]--; 

            if (window_count == string_count)
            {
                return true; 
            }
        }

        return false;
    }
};
