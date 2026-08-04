class Solution {
public:
    int countSeniors(vector<string>& details) {
        int number_passengers = 0; 

        for (const string& s : details) {
            // Convert char digits to integer value directly
            int age = (s[11] - '0') * 10 + (s[12] - '0');

            if (age > 60) {
                number_passengers++; 
            }
        }

        return number_passengers; 
    }
};
