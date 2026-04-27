class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Use a min_heap to hold the k largest values seen so far.
        // Min heap has child > parent, so use compare function std::greater
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
        // Iterate through the vector.
        // INVARIANT: min_heap contains the greatest k values seen so far.
        for (int i = 0; i < nums.size(); ++i) {
            // Add the first k elements to the heap.
            if (min_heap.size() < k) {
                min_heap.push(nums[i]);
                continue;
            }
            // If this number is greater than the min element in the heap (at top)
            // Remove the top element (pop) and add this greater one to the heap.
            if (nums[i] > min_heap.top()) {
                min_heap.pop();
                min_heap.push(nums[i]);
            }
        }
        // By the loop invariant, min_heap contains the greatest k values in the nums array.
        // And since it's a min heap, the smallest element is at the top. This is the kth largest element.
        return min_heap.top();
    }
};
