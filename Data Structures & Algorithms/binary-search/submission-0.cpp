class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        // Maintain the invariant that if target is present in nums, 
        // It is at an index between left and right inclusive (left <= index <= right)
        while (left <= right) {
            // Calculate the index halfway between left and right
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                // Too large. If target is in the array, it will be in the interval [left, mid - 1]
                right = mid - 1;
            } else { // nums[mid] < target
                // Too small. If target is in the array, it will be in the interval [mid + 1, right]
                left = mid + 1;
            }
        }
        // Target not found, return -1
        return -1;
    }
};
