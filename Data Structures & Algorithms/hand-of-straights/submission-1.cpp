class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // We can't form straights of size groupSize, 
        // if the number of cards isn't divisible by groupSize
        if (hand.size() % groupSize != 0) return false;

        std::map<int, int> count;
        for (int num : hand)
            count[num]++;

        for (const auto [start_num, start_count] : count) {
            // We already used up all cards of this number.
            if (start_count == 0) continue;
            // Need to form 'start_count' straights of length groupSize starting at 'start_num'
            for (int card = start_num; card < start_num + groupSize; ++card) {
                // We have enough copies of this card to make 'start_count' straights
                if (count[card] >= start_count) {
                    count[card] -= start_count;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
