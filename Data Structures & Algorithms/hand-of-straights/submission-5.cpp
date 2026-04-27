class Solution {
public:
        // Goal: compact as possible.
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        std::unordered_map<int, int> counts; // Hashmap: card number -> count
        for (int num : hand) counts[num]++;

        // Sort hand since we'll want to form straights starting with the smallest cards.
        std::sort(hand.begin(), hand.end());
        for (int start : hand) {
            // No more copies of this card. Move on.
            if (counts[start] == 0) continue;
            // Form a straight, starting from this value, 'start'
            for (int card = start; card < start + groupSize; ++card) {
                // Not enough copies of 'card + i' in the straight
                if (counts[card] == 0)
                    return false;
                // Use up 1 copy of this card to form a straight.
                counts[card]--;
            }
        }
        // No cards left in hand. All used to make straights. Success.
        return true;
    }
};
