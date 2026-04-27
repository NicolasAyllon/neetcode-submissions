class Solution {
public:
    // Approach 1. Heap
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> result;
        std::priority_queue<std::pair<int, int>, 
                            std::vector<std::pair<int, int>>, 
                            std::less<std::pair<int, int>>> maxHeap;
        // Add first k elements to the heap.
        // Note this is a max heap, first by value (pair.first) then by index (pair.second)
        for (int i = 0; i < k; ++i) {
            maxHeap.push({nums[i], i});
        }
        // Add the first max element the window the result
        result.push_back(maxHeap.top().first);

        // Shift the window from left to right, through all possible positions.
        for (int i = k; i < nums.size(); ++i) {
            // Add this (val, idx) pair to the maxHeap
            maxHeap.push({nums[i], i});
            // Pop any max values that are no longer in the window
            while (maxHeap.top().second <= i - k)
                maxHeap.pop();
            // Now the (val, idx) pair at the top of the heap is in the window,
            // So add it to the result
            result.push_back(maxHeap.top().first);
        }

        return result;
    }
};
