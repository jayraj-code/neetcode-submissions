#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canFinish(int k, vector<int>& piles, int h) {
        long long total_hours = 0; 
        for (int pile : piles) {
            total_hours += (pile + k - 1) / k;
        }    
        return total_hours <= h;
    } 

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1; 
        int n = piles.size();
        int max_val = piles[0]; 

        for (int i = 1; i < n; ++i) {
            if (piles[i] > max_val) {
                max_val = piles[i]; 
            }
        }
        
        int right = max_val;

        for (int speed = left; speed <= right; speed++) {
            if (canFinish(speed, piles, h)) {
                return speed; 
            }
        }
        
        return right;
    }
};
