
class Solution {
public:
    string simplifyPath(string path) {
        string part; 
        stringstream ss(path); 
        stack<string> st; 
        
        while(getline(ss, part, '/'))
        {
            if (part.empty() || part == ".")
            {
                continue; 
            }

            if (part == "..")
            {
                if (!st.empty())
                {
                    st.pop(); 
                }
            }
            else
            {
                st.push(part); 
            }
            
        }

        vector<string> directories;
        while (!st.empty())
        {
            directories.push_back(st.top());
            st.pop();
        }

        reverse(directories.begin(), directories.end());

        string result;
        for (string& directory : directories)
        {
            result += "/";
            result += directory;
        }

        if (result.empty())
        {
            return "/";
        }

        return result;


    }
};