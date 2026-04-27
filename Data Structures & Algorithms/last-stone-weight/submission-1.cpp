class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Construct max heap from vector
        std::priority_queue<int> max_heap(std::less<int>(), stones);
        // While there are 2 or more stones left
        while (max_heap.size() > 1) {
            // Take the two heaviest stones at the top of the heap.
            int x = max_heap.top();
            max_heap.pop();
            int y = max_heap.top();
            max_heap.pop();

            // Smash the stones!
            // if (x == y) { // Do nothing. }
            // For unequal weights, calculate the surviving stone's weight and add back to heap.
            if (x > y) {
                max_heap.push(x - y);
            }
        }

        // At most 1 stone remains.
        // If there's a stone, return its weight. But if none remain, return 0.
        return max_heap.size() == 1 ? max_heap.top() : 0;
    }
};
