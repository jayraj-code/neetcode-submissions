class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int greatest_element = -1; // The last element always becomes -1

        // Scan the array from right to left
        for (int i = n - 1; i >= 0; i--) {
            int current_val = arr[i];      // Save the current value
            arr[i] = greatest_element;     // Replace current element with the max to its right
            greatest_element = max(greatest_element, current_val); // Update the max for next iterations
        }
        
        return arr;
    }
};
