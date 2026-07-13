#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;               // Equivalent to 'stack = []'
        vector<int> res(n, 0);       // Equivalent to 'res = [0] * n'
        
        for (int i = 0; i < n; i++) {
            // Equivalent to 'while stack and temperatures[i] > temperatures[stack[-1]]:'
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int index = st.top(); // Equivalent to 'index = stack.pop()'
                st.pop();
                res[index] = i - index;
            }
            st.push(i);              // Equivalent to 'stack.append(i)'
        }
        return res;
    }
};
