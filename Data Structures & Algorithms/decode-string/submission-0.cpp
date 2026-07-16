class Solution {
public:
    string decodeString(string s) {

        stack<pair<int, string>> st;

        string currentString = "";
        int currentNumber = 0;

        for (char ch : s) {

            if (isdigit(ch)) {
                currentNumber = currentNumber * 10 + (ch - '0');
            }

            else if (ch == '[') {

                // Save current context
                st.push({currentNumber, currentString});

                // Start a fresh context
                currentNumber = 0;
                currentString = "";
            }

            else if (ch == ']') {

                auto [repeat, previousString] = st.top();
                st.pop();

                string repeated = "";

                for (int i = 0; i < repeat; i++) {
                    repeated += currentString;
                }

                currentString = previousString + repeated;
            }

            else {

                currentString += ch;
            }
        }

        return currentString;
    }
};