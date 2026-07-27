class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        // Smallest possible capacity = heaviest package
        int left = *max_element(weights.begin(), weights.end());

        // Largest possible capacity = ship everything in one day
        int right = 0;
        for (int weight : weights) {
            right += weight;
        }

        while (left <= right) {

            int mid = left + (right - left) / 2;

            // Check how many days we need with capacity = mid
            int daysUsed = 1;
            int load = 0;

            for (int weight : weights) {

                if (load + weight <= mid) {
                    load += weight;
                }
                else {
                    // Start a new day
                    daysUsed++;
                    load = weight;
                }
            }

            // mid works → try a smaller capacity
            if (daysUsed <= days) {
                right = mid - 1;
            }
            // mid is too small → increase capacity
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};