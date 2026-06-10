class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result; 
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++)
        {
            if (n < 4)
            {
                return {};
            }

            if (i > 0 && nums[i] == nums[i-1])
            {
                continue; 
            }

            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
            {
                break; 
            }

            for (int j = i+1; j < n-2; j++)
            {
                if (j > i+1 && nums[j] == nums[j-1])
                {
                    continue; 
                }

                long long right_value = (long long)target - nums[i] - nums[j];
                long long left = j+1;
                long long right = n-1; 

                while (left < right)
                {
                    long long current_sum = nums[left] + nums[right];
                    if (current_sum == right_value)
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--; 

                        while(left < right && nums[left] == nums[left-1])
                        {
                            left++; 
                        }

                        while(left < right && nums[right] == nums[right+1])
                        {
                            right--; 
                        }
                    }

                    else if (current_sum < right_value)
                    {
                        left++;
                    }

                    else 
                    {
                        right--; 
                    }
                }
            }

        }

        return result; 
        
    }
};