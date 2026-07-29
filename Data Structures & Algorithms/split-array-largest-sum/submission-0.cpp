class Solution {
public:
    bool works(vector<int>& nums, int k, int limit)
    {
        int curr_sum = 0;
        int subarrays = 1;

        for (int num : nums)
        {
            if (curr_sum + num <= limit)
            {
                curr_sum += num;
            }
            else
            {
                subarrays++;
                curr_sum = num;
            }
        }

        return subarrays <= k;
    }

    int splitArray(vector<int>& nums, int k) {

        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        int answer = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (works(nums, k, mid))
            {
                answer = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return answer;
    }
};