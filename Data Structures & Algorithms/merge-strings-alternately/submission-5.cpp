class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0; 
        int n = word1.size(), m = word2.size(); 
        string output;
        output.reserve(n+m);

        while (i < n && j < m)
        {
            output.push_back(word1[i++]);
            output.push_back(word2[j++]);
            
        }

        while (i < n)
        {
            output.push_back(word1[i++]);   
        }
        
        while (j < m)
        {
            output.push_back(word2[j++]);
        }

        return output;
    } 
};