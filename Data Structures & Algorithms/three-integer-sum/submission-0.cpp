class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(); 
        vector<vector<int>> result; 
        sort(nums.begin(), nums.end()); 

        for (int i = 0; i < n-2; i++)
        {
            if (i > 0 && nums[i] == nums[i-1])
            {
                continue; 
            }

            if (nums[i] + nums[i+1] + nums[i+2] > 0)
            {
                break; 
            }

            long long target = - nums[i];
            int left = i+1; 
            int right = n-1; 

            while (left < right)
            {
                long long current_sum = nums[left] + nums[right]; 
                if ( current_sum == target)
                {
                    result.push_back({nums[i], nums[left], nums[right]});
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

                else if (current_sum < target)
                {
                    left++;
                }
                
                else
                {
                    right--; 
                }

                
            }
        }
        return result; 
    }
};
