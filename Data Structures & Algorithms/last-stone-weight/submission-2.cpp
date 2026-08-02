class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Add all the stones to the max-heap
        for (int stone : stones) {
            maxHeap_.push(stone);
        }
        // Run the simulation until only 1 stone remains
        while (maxHeap_.size() > 1) {
            int x = maxHeap_.top(); maxHeap_.pop();
            int y = maxHeap_.top(); maxHeap_.pop();
            if (x != y) {
                // The remaining stone is the absolute value of the difference
                maxHeap_.push(std::abs(y - x));
            }
            // if (x == y) {
                // push no stone back on the heap (both are destroyed)
            // } 
        }
        // Return the weight of the last stone remaining, or 0 if none remain
        return maxHeap_.empty() ? 0 : maxHeap_.top();
    }
private:
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap_;
};
