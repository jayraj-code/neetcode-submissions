class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        int min_price = prices[0]; 
        int output = 0; 

        for (int i = 1; i < n; i++)
        {
            if (prices[i] < min_price)
            {
                min_price = prices[i];

            }
            int profit = prices[i] - min_price; 
            output = max(output, profit);

        }
        return output;

    }
};
