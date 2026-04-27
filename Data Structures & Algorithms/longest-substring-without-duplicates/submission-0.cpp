class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Let's track the counts of the characters in the window
        std::unordered_map<char, int> counts;
        
        // Start the window at [0, 0]
        int max_len = 0;
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            // Add this character to the counts hashmap
            counts[s[j]] += 1;

            // If is a repeated character, contract the window until
            // the count of this character falls back to 1.
            // (Note this condition will always be satisfied when 
            // our window shrinks to just this character [j, j])
            while (counts[s[j]] > 1) {
                counts[s[i]] -= 1;
                ++i;
            }
            // Now the window [i, j] contains no duplicate characters
            // Record its length and update the max length of a substring without duplicate characters
            max_len = std::max(j - i + 1, max_len);
        }

        return max_len;
    }
};
