class StockSpanner {
private: 
    vector<int> stocks; 

public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        stocks.push_back(price);
        int n = stocks.size(); 
        
        int curr_index = n-1; 
        int current_price = stocks[n-1]; 
        int prev_index = curr_index - 1; 
        int count = 1; 

        while(prev_index >= 0 && stocks[prev_index] <= current_price)
        {
            count++; 
            prev_index--; 
        }

        return count; 
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */