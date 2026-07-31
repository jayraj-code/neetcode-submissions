
class Solution {
public:
    int findPeak(MountainArray &mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (mountainArr.get(mid) > mountainArr.get(mid + 1))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }

    int binarySearch(MountainArray &mountainArr, int left, int right, int target, bool ascending) {

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int value = mountainArr.get(mid);

            if (value == target)
                return mid;

            if (ascending) {
                if (target < value)
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (target < value)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {

        int peak = findPeak(mountainArr);

        int leftResult = binarySearch(mountainArr, 0, peak, target, true);

        if (leftResult != -1)
            return leftResult;

        return binarySearch(
            mountainArr,
            peak + 1,
            mountainArr.length() - 1,
            target,
            false
        );
    }
};