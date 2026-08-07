class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0; 
        int count = 1; 
        int n = chars.size(); 

        for (int read = 0; read < n; read++)
        {
            if(read == n-1 || chars[read] != chars[read + 1])
            {
                chars[write] = chars[read];
                write++; 
                if (count > 1)
                {
                    string curr = to_string(count); 
                    for (char c : curr)
                    {
                        chars[write] = c;
                        write++; 
                    }
                } 
                
                count = 1;
                
            }

            else
                {
                    count++; 
                }
        }

        return write; 
        
    }
};