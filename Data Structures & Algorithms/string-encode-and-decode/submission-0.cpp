class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string; 
        for (string i : strs){
            encoded_string  += to_string(i.length()) + "/" + i ; 
        }

        return encoded_string; 
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs; 
        int i = 0;
        while (i < s.length()){
            int slash_pos = s.find('/', i);
            string encoded_portion = s.substr(i, slash_pos - i); 
            int limit = stoi(encoded_portion); 
            i = slash_pos + 1; 
            string encoded_word = s.substr(i, limit); 
            decoded_strs.push_back(encoded_word); 
            i += limit; 
            }

        return decoded_strs; 
    }
};
