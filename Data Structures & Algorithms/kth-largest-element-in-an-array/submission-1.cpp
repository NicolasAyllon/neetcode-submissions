class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Let's use a priority queue
        // We want the top K elements, so we'll use a min-heap
        // to continually discard the smallest element as we add each element in the array to the heap
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        // Add all items in nums to the heap always discarding the smallest one when we have more than K
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        // Since the heap is a min-heap and we discarded all smaller elements besides the top K
        // the K-th largest element is at the top of the heap
        return minHeap.top();
    }
};
