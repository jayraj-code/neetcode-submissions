class Solution {
public:
    int countSeniors(vector<string>& details) {
        int number_passengers = 0; 
        string curr_string = ""; 
        int age = 0; 

        for (string s : details)
        {
            curr_string = s.substr(11, 2);
            age = stoi(curr_string); 

            if(age > 60)
            {
                number_passengers++; 
            }
        }

        return number_passengers; 
        
    }
};