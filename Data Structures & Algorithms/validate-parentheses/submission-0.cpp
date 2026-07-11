class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;

        for (char ch : s) 
        {
            if (ch == '(' || ch == '{' || ch == '[' ) 
            {
                stck.push(ch);
            }
            
            else if (ch == ')' || ch == '}' || ch == ']')
            {
                if (stck.empty()) return false;

                char top_bracket = stck.top();
                
                if ( (ch == ')' && top_bracket == '(') ||
                    (ch == '}' && top_bracket == '{') ||
                    (ch == ']' && top_bracket == '[') ) 
                    {
                    stck.pop();
                } 
                
                else 
                {
                    return false;
                }
            }
        }

        return stck.empty();
    }
};
