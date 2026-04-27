class Solution {
public:
    // Approach 2: Use a deque
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // We'll scan our sliding window size k across the array.
        // At all times, we'll keep a deque of items in the window arranged in non-increasing order
        // For example if the window is [5 2 3 4 1] then our (nondecreasing list is: [5, 4, 1])
        // This list/deque keeps track of two things:
        // 1. Pop items off the front the deque until we reach an item in the window
        // 2. If an item falls out the window, then the next item (past the front) is the next greatest

        std::deque<int> q; 
        // Deque of INDICES whose corresponding values in nums are in nonincreasing order
        // front -> (i1' < i2' < i3' < ...) <- back
        // where nums[i1'] >= nums[i2'] >= nums[i3'] >= ...

        // Create a vector for the result and reserve space for all nums.size() - k + 1 window max's
        std::vector<int> result;
        result.reserve(nums.size() - k + 1);

        // Create the deque for the first k elements


        for (int i = 0; i < nums.size(); ++i) {
            // Push the current index onto the back the deque.
            // To maintain the invariant of nonincreasing values, 
            // we need to first pop all values from the back that are less than the current one
            while (!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            // Now either q.empty() or nums[q.back()] >= nums[i] which maintains the nonincreasing invariant
            q.push_back(i);
            // Finally, remove any indices from the front that are outside the window
            while (q.front() <= i - k)
                q.pop_front();

            // Now the deque only contains indices in the window whose values are nonincreasing order,
            // So the greatest element in the window is at the front of the deque.
            if (i >= k - 1)
                result.emplace_back(nums[q.front()]);
        }
        return result;
    }
};
