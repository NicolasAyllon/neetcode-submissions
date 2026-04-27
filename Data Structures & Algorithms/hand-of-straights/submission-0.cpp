class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // Let's make a map from card_number -> card_count
        std::map<int, int> count_map;
        for (int num : hand) {
            count_map[num]++;
        }

        // Now we'll iterate over the keys in ascending order.
        for (const auto [start_num, start_count] : count_map) {
            printMap(count_map);
            std::cout << std::endl;
            // Draw the rest of the owl...
            std::cout << "card " << start_num << ", count " << start_count << '\n';

            // We used up all copies of this card as parts of another straight (starting at a lower value)
            if (start_count == 0) {
                std::cout << "Card " << start_num << " has 0 cards, skipping...\n";
                continue;
            }

            // Form as many straights (of length groupSize) as there are copies of this starting number.
            // of card values (num, num+1, num+2, ..., num+(groupSize-1))
            std::cout << "Try to form straight starting at " << start_num << '\n';
            for (int i = 0; i < groupSize; ++i) {
                // The card is in the hand, and there are sufficient copies (>= start_count)
                if (count_map.find(start_num + i) != count_map.end() &&
                    count_map[start_num + i] >= start_count) {

                    std::cout << "\tFound " << start_num + i << " with sufficient copies, " << count_map[start_num + i] << '\n';
                    count_map[start_num + i] -= start_count;
                    std::cout << "\tAfter forming straights, count[" << start_num + i << "] = " << count_map[start_num + i] << '\n';
                } else {
                    // Can't form all the required straights (of length groupSize) starting from start_num
                    std::cout << "\tCouldn't find card " << start_num + i << " or there were not enough copies (" << count_map[start_num+i] << ")\n";
                    return false;
                }
            }

        }
        // We were able to form straights with all the cards, success!
        return true;
    }

    void printMap(const std::map<int, int>& m) {
        std::cout << "[\n";
        for (const auto& [k, v] : m)
            std::cout << k << " -> " << v << '\n';
        std::cout << "]\n";
    }
};
