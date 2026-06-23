
class Solution {
private:
    int partition(std::vector<int>& nums, int low, int high) {
        int randomPivotIdx = low + rand() % (high - low + 1);
        std::swap(nums[randomPivotIdx], nums[high]);
        
        int pivot = nums[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (nums[j] < pivot) {
                i++;
                std::swap(nums[i], nums[j]);
            }
        }
        std::swap(nums[i + 1], nums[high]);
        return i + 1;
    }

    void quickSort(std::vector<int>& nums, int low, int high) {
        if (low < high) {
            int pi = partition(nums, low, high);
            quickSort(nums, low, pi - 1);
            quickSort(nums, pi + 1, high);
        }
    }

public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        srand(time(nullptr));
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
