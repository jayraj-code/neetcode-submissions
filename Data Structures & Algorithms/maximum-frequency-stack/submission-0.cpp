class FreqStack {
private:
    unordered_map<int, stack<int>> group; 
    unordered_map<int, int> freq; 
    int maxfreq; 

public:
    FreqStack() {
        maxfreq = 0; 
    }
    
    void push(int val) {
        freq[val]++; 

        if(freq[val] > maxfreq)
        {
            maxfreq = freq[val]; 
        }

        group[freq[val]].push(val); 
        
    }

    int pop() {
        int val = group[maxfreq].top();
        group[maxfreq].pop();

        freq[val]--;

        if (group[maxfreq].empty())
            maxfreq--;

        return val;
    }
};

