#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
    std::unordered_map <char, int> St, T; 

        if (s.length() != t.length()) return false;
        for ( char x : s ) St[x]++;
        for ( char x : t) T[x]++;

        for (auto const&[key, value] : St)
        {
            if(value != T[key]) return false;  
        }
        return true; 
    }  
};
