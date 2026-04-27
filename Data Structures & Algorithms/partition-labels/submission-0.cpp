class Solution {
public:
    vector<int> partitionLabels(string s) {
        // For every character a-z, it might be useful to track
        // the first and last index at which it appears.
        // For example 'a' might appear at indices 2, 4, 10
        // But since we can't separate these a's , we know that any substring containing 'a'
        // must extend from index 2-10 at least.

        // Record first and last indices for every character
        std::unordered_map<char, int> min_index;
        std::unordered_map<char, int> max_index;
        for (int i = 0; i < s.size(); ++i) {
            // Only add this character once to the min_index, when we first see it.
            if (min_index.count(s[i]) == 0)
                min_index[s[i]] = i;
            // Always update the max_index (by iterating over increasing i, this is always the max index)
            max_index[s[i]] = i;
        }

        // Now, iterate over the string s again, but this time, we'll have the advantage
        // of knowing when there are no more copies of a character in the string (via max_index hashmap)
        std::vector<int> result;
        int prev_end_idx = -1;
        int substr_end_idx = -1;

        for (int i = 0; i < s.size(); ++i) {
            // Update the maximum ending index of any character in the current substring.
            substr_end_idx = std::max(max_index[s[i]], substr_end_idx);
            // When i is last index of any character we've seen so far 
            // (we know no character in the current substring appears at a later index), 
            // we can break off a substring ending at this index.
            if (i == substr_end_idx) {
                int substr_length = substr_end_idx - prev_end_idx;
                result.push_back(substr_length);
                prev_end_idx = i;
            }
        }
        return result;
    }
};
