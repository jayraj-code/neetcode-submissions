class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0; 
        int j = 0; 
        int i_count = 0;
        int j_count = 0; 
        string output ;
        while (i < word1.size() && j < word2.size())
        {
            output.push_back(word1[i]);
            output.push_back(word2[j]);
            i++;
            i_count = i;
            j++;
            j_count = j; 
        }
        if (i == word1.size())
        {
            for (int j = j_count; j < word2.size(); j++)
            {
                output.push_back(word2[j]);
            }
        }
        
        else if (j == word2.size())
        {
            for (int i = i_count; i < word1.size(); i++)
            {
                output.push_back(word1[i]);
            }
        }

        return output;
    } 
};