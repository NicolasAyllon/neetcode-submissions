class Solution {
public:
    int findMin(vector<int> &nums) {
        // We maintain the invariant that we know the min element is in [left, right] inclusive
        int left = 0;
        int right = nums.size() - 1;
        int result = nums[0];

        // Invariant: the min element is contained in nums[left, right] OR it is in the result
        while (left <= right) {
            // If the current window is already sorted, choose the leftmost value as the minimum and break
            if (nums[left] < nums[right]) {
                result = std::min(nums[left], result);
                break;
            }
            // The current window is not completely sorted
            // Calculate the middle index and update min if needed
            int mid = left + (right - left) / 2;
            result = std::min(nums[mid], result);

            if (nums[mid] >= nums[left]) {
                // nums[left, mid] is sorted, so the min element in nums[left, right] must be in the other half
                // [left, right] -> [mid + 1, right]
                left = mid + 1;
            } else { // nums[mid] < nums[left]
                // nums[left, mid] contains the min element, and we've already captured nums[mid] in our result
                // [left, right] -> [left, mid - 1]
                right = mid - 1;
            }
        }
        // By the invariant, the min element is contained in nums[left, right] OR reusult
        // but left > right, so the interval is empty, and the min value MUST be in the result
        return result;
    }
};
