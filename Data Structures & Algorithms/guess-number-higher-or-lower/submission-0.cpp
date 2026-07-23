
class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        
        while (low <= high) {
            // Prevent potential overflow compared to (low + high) / 2
            int mid = low + (high - low) / 2;
            int res = guess(mid);
            
            if (res == 0) {
                return mid; // Found the picked number
            } else if (res == -1) {
                high = mid - 1; // Guess is too high, narrow to lower half
            } else {
                low = mid + 1; // Guess is too low, narrow to upper half
            }
        }
        
        return -1;
    }
};