class KthLargest {
public:
    // We wan't the k-th largest element, which means 
    // we want to maintain a MIN heap of size k.
    // At all times, the top value will be the smallest of the k greatest values seen so far.
    
    // Uses comparison object std::less (which means )
    const int k; // Value of k to use
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    KthLargest(int k_, vector<int>& nums) : k(k_) {
        for (int num : nums)
            min_heap.push(num);
    }
    
    int add(int val) {
        // Add element to min-heap if bigger or equal to the current min (at top)
        if (min_heap.size() < k || val >= min_heap.top())
            min_heap.push(val);

        while (min_heap.size() > k)
            min_heap.pop();

        return min_heap.top();
    }
};
