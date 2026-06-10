class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i = 0, j = 0; 
        string output; 

        while (i < n && j < m)
        {
            output.push_back(word1[i++]);
            output.push_back(word2[j++]);
        }

        while(i < n)
        {
            output.push_back(word1[i++]);
        }

        
        while(j < m)
        {
            output.push_back(word2[j++]);
        }

        return output; 
        
    }
};