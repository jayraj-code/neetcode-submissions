class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size(); 
        stack <int> stck;
        int result = 0;

        for (const string& ch : operations)
        {
            if (ch == "D")
            {
                int value = 0; 
                value = stck.top() * 2; 
                stck.push(value); 
            }

            else if (ch == "C")
            {
                stck.pop(); 
            }


            else if (ch == "+")
            {
                int first_value = stck.top();
                stck.pop(); 
                int second_value = stck.top(); 
                stck.push(first_value); 
                stck.push(first_value + second_value); 
            }

            else 
            {
                stck.push(stoi(ch));
            }
            
        } 

        while (!stck.empty())
        {
            result += stck.top(); 
            stck.pop(); 
        }

        return result; 
        

    }
};