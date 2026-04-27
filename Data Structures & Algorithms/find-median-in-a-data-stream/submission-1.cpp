class MedianFinder {
public:
    MedianFinder() : mSize(0) { }
    
    void addNum(int num) {
        // Put the value into the heap where it belongs.
        if (upper_half_min_heap.empty() || num >= upper_half_min_heap.top())
            upper_half_min_heap.push(num);
        else
            lower_half_max_heap.push(num);

        balance();
        mSize++;
    }
    
    double findMedian() {
        // If no values, return 0.0 for now.
        if (mSize == 0)
            return 0.0;
        // If there are an odd number of values, the median 
        // is at the top of the bigger heap.
        if (mSize % 2 == 1)
            return upper_half_min_heap.size() > lower_half_max_heap.size() ?
                upper_half_min_heap.top() : lower_half_max_heap.top();
        // If there's an even number of values,
        // the median is the average of the middle two.
        else
            return (upper_half_min_heap.top() + lower_half_max_heap.top()) / 2.0;
    }

private:
    void balance() {
        // Top half has too many elements. Move smallest (top-of-heap) to the lower half.
        if (upper_half_min_heap.size() > lower_half_max_heap.size() + 1) {
            lower_half_max_heap.push(upper_half_min_heap.top());
            upper_half_min_heap.pop();
        }
        // Bottom half has too many elements. Move greatest (top-of-heap) to the upper half.
        if (lower_half_max_heap.size() > upper_half_min_heap.size() + 1) {
            upper_half_min_heap.push(lower_half_max_heap.top());
            lower_half_max_heap.pop();
        }
    }

    size_t mSize;
    // A min heap will hold values >= median
    std::priority_queue<int, std::vector<int>, std::greater<>> upper_half_min_heap;
    // A max heap will hold values < median
    std::priority_queue<int, std::vector<int>, std::less<>> lower_half_max_heap;
};
