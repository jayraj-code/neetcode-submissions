class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; 

        for (int i : nums)
        {
            freq[i]++; 
        }
        
        vector<pair<int,int>> sortedVector; 
        for (auto& pair: freq)
        {
            sortedVector.push_back(pair); 
        }
        
        sort(sortedVector.begin(), sortedVector.end(),
        [](const auto& a, const auto& b)
        {
            return a.second > b.second; 
        }); 

        vector<int> answer; 
        for (int i = 0; i < k; i++)
        {
            answer.push_back(sortedVector[i].first); 
        }

        return answer; 
    }
};
