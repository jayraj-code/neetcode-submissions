class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
        return false;

        sort(hand.begin(), hand.end());

        unordered_map<int, int> freq; 
        for (int i : hand)
        {
            freq[i]++; 
        }

        int count = 0; 
        for (int i : hand)
        {
            if (freq[i] == 0)
            {
                continue; 
            }
            for (int next = i; next < i + groupSize; next++) {

                if (freq[next] == 0)
                    return false;

                freq[next]--;
            }
        }
        return true; 
        
    }
};
