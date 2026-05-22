class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[left] <= nums[mid]) {
                // Check if target is strictly within the sorted left half
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Narrow search to left half
                } else {
                    left = mid + 1;  // Narrow search to right half
                }
            } 
            // Otherwise, the right half must be sorted
            else {
                // Check if target is strictly within the sorted right half
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // Narrow search to right half
                } else {
                    right = mid - 1; // Narrow search to left half
                }
            }
        }

        return -1; // Target not found
    }
};