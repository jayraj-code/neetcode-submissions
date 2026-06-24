class Solution {
public:

    static bool compare(pair<int,int>& a, pair<int,int>& b)
        {
            return a.second > b.second; 
        }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> freq; 

        for (int num : nums)
        {
            freq[num]++; 
        }

        vector<pair<int, int>> vec; 

        for (auto & pair: freq)
        {
            vec.push_back({pair.first, pair.second});
        }

        sort(vec.begin(), vec.end(), compare); 

        vector<int> result; 
        for (int i = 0; i < k; i++)
        {
            result.push_back(vec[i].first); 
        }

        return result; 
    }
};
