class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(); 
        vector<int> result; 

        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = i + 1; j < n; j++) {
                if (temperatures[j] > temperatures[i]) {
                    result.push_back(j - i); 
                    found = true;
                    break; 
                }
            }
            if (!found) {
                result.push_back(0);             }
        }
        return result; 
    }
};
