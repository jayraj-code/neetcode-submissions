class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; 

        sort(strs.begin(), strs.end()); 

        string first = strs.front();
        string end = strs.back(); 

        int i = 0; 

        while (i < first.length() && i < end.length() && first[i] == end[i])
        {
            i++;
        }

        string prefix = strs[0].substr(0, i);
        return prefix; 


        
    }
};