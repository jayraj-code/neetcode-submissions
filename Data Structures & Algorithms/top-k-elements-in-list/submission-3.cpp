class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> pairMap; 
        
        for (int i : nums)
        {
            pairMap[i]++; 
        }

        vector<pair<int, int>> sorted_vector; 

        for (const auto& pair: pairMap)
        {
            sorted_vector.push_back(pair); 
        }

        sort(sorted_vector.begin(), sorted_vector.end(), 
        [](const auto& a, const auto& b)
        {
            return a.second > b.second; 
        }); 

        vector<int> answer;
        answer.reserve(k); 

        for (int i = 0; i < k; i++)
        {
            answer.push_back(sorted_vector[i].first); 
        }
        return answer; 
        
    }
};
