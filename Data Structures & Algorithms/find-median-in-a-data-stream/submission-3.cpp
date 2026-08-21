class MedianFinder {
public:
    MedianFinder() {};
    
    // Invariant: maxHeap and minHeap differ in size by at most 1
    void addNum(int num) {

        // num is less than or equal to the max of the lower half
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        }
        // num is greater than the max of the lower half, so it can go in the upper half
        else {
            minHeap.push(num);
        }

        // Restore the invariant if it was violated:
        // "maxHeap and minHeap differ in size by at most 1"
        // Lower half has 2 more items than the upper half, so move one from the lower to upper
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            return;
        }
        // Upper half has 2 more items than the lower half, so move one from the upper half to the lower
        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            return;
        }
    }
    
    double findMedian() {
        // To be safe, we return 0 if there are no values;
        if (maxHeap.empty() && minHeap.empty()) return 0.0;

        // If the two heaps have the same size, then the median is the average of the
        // max of the lower half and the min of the upper half.
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        // Otherwise, one heap has one more element than the other, so the middle value is
        // top of the bigger heap (the max of the upper half, or the min of the lower half)
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        else { // minHeap.size() > maxHeap.size()
            return minHeap.top();
        }
    }

private:
    // We'll need to keep track of the middle-valued elements we've seen so far.
    // - 2 heaps:
    // - 1 max heap which holds the bottom elements (the half of the elements with smaller values)
    // - This gives us constant time O(1) access to the max of the lower elements
    std::priority_queue<int,
                        std::vector<int>,
                        std::less<int>> maxHeap;
    // - 1 min heap which holds the top elements (the half of the elements with larger values)
    // - This heap gives us constant time O(1) access to the min of the upper elements
    std::priority_queue<int,
                        std::vector<int>,
                        std::greater<int>> minHeap;

};
