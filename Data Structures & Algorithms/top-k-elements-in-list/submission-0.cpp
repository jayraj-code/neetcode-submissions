class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map; 
        for (int i : nums)
        {
            map[i]++; 
        }

        vector<pair<int,int>> sorted_vector(map.begin(), map.end()); 

        sort(sorted_vector.begin(), sorted_vector.end(), [](const auto& a, const auto& b){
            return a.second > b.second; 
        }); 

        vector<int> result; 
        for (int i = 0 ; i < k; i++)
        {
            result.push_back(sorted_vector[i].first);
        }
        return result; 
    }
};
