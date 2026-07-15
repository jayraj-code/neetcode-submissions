class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> car;
        int n = position.size(); 
        for (int i = 0; i < n; i++)
        {
            car.emplace_back(position[i], speed[i]); 
        }

        sort(car.rbegin(), car.rend()); 

        stack<double> st; 
        for (auto & car : car)
        {
            double time = (double)(target - car.first) / car.second; 
            if (st.empty() || time > st.top())
            {   
                st.push(time);
            }

            else if (st.top() >= time)
            {
                continue; 
            }
        }
        return st.size(); 
    }
};
