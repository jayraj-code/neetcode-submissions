class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(); 
        stack<int> stck; 
        vector<int> result(n, 0); 

        for (int i = 0; i < n; i++)
        {
            int curr = temperatures[i];
            while (!stck.empty() && curr > temperatures[stck.top()])
            {
                result[stck.top()] = (i - stck.top());
                stck.pop();

            }
            stck.push(i); 
        }
        return result; 
        
    }
};
