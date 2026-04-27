class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Preliminary check: can't form straights of size groupSize 
        // because the number of cards is not a multiple of groupSize
        if (hand.size() % groupSize != 0) return false;

        // Let's use an unordered map (hashmap) to track the count of each card
        std::unordered_map<int, int> counts;
        // Recall that for the item at the top of the heap,
        // predicate returns false for all other elements.
        // So, std::less<int> makes a max_heap, std::greater<int> makes a min_heap.
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

        for (int num : hand) {
            // If this is a new number, put it in the heap.
            if (counts.count(num) == 0)
                min_heap.push(num);
            // Always increment count for this numbered card. 
            // (operator[] adds the key if not present with value 0, which is then incremented)
            counts[num]++;
        }

        // Now, while the heap is not empty (we have a smallest card)
        // We need to form a straight starting with the card at the top of the heap.
        // since there are no smaller cards it could be in a straight with.
        while (!min_heap.empty()) {
            int smallest = min_heap.top();
            int copies = counts[smallest];

            if (copies == 0) {
                min_heap.pop();
                continue;
            }
            // At least one copy of a card with this value.
            // Form the 'copies' straights with cards 
            // (smallest, smallest + 1, ... smallest + groupSize-1)
            for (int card = smallest; card < smallest + groupSize; ++card) {
                // Not enough cards of number 'card' to make 'start_count' straights
                if (counts[card] < copies)
                    return false;
                
                // Otherwise, we form the straights and decrement this card's count
                // by start_count (the number of copies of the starting card)
                counts[card] -= copies;
            }
            // We formed straights with all the copies of this card, so it'll be popped
            // from the min heap next iteration, since count[smallest] is now 0.
        }
        // No more cards in heap, and no problems forming straights, 
        // so we can return true. Success!
        return true;
    }
};
