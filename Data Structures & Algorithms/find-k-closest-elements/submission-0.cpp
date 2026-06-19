class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(); 
        int left = 0; 
        int right = n-1; 

        while (right-left+1 > k)
        {
            int dis_left = abs(arr[left] - x);
            int dis_right = abs(arr[right] - x);

            if (dis_left  >  dis_right)
            {
                left++;
            }
            else
            {
                right--; 
            }
        }
        vector<int> k_closest(arr.begin() + left, arr.begin() + right + 1);
        return k_closest; 
    }
};