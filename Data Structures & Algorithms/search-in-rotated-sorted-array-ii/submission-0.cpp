class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            // Step 1: Found the target
            if (nums[mid] == target)
                return true;

            // Step 2: Duplicates make it impossible
            // to know which half is sorted.
            if (nums[left] == nums[mid] &&
                nums[mid] == nums[right])
            {
                left++;
                right--;
                continue;
            }

            // Step 3: Left half is sorted
            if (nums[left] <= nums[mid])
            {
                // Is the target inside the sorted interval?
                if (nums[left] <= target &&
                    target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            // Step 4: Otherwise the right half is sorted
            else
            {
                // Is the target inside the sorted interval?
                if (nums[mid] < target &&
                    target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};