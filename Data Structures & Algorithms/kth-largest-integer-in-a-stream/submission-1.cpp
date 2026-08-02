class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) :
    k_(k)
    {
        for (int num : nums) {
            minHeap_.push(num);
            if (minHeap_.size() > k_)
                minHeap_.pop();
        }
    }
    
    int add(int val) {
        // If it is greater than the current Kth largest, then it's now in the top K
        // And we pop the previous Kth largest
        // if (val > minHeap_.top())
        //     minHeap_.push(val);
        // Keep only k values
        minHeap_.push(val);
        if (minHeap_.size() > k_) {
            minHeap_.pop();
        }
        return minHeap_.top();
    }

private:
    // The K-th largest value is actually the minimum of the top-K  values
    // We'll use a min-heap to get constant-time (O(1)) access to the min element
    // Recall the third template parameter Compare will define the top of the heap:
    // Namely: 
    // top_of_heap <Compare> other_element 
    // is false for all other elements.
    // Since we want a min heap, we want to use Compare = std::greater, since
    // the top of the heap should be NOT greater than any other element
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap_;
    int k_;
};
