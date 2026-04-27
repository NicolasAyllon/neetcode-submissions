class Solution {
public:
    int characterReplacement(string s, int k) {
        // Use a sliding window approach. 
        // Let the window go from index left to right inclusive: [left, right]
        // Track the frequency of characters in the window.
        std::unordered_map<char, int> freq;
        int maxFreq = 0;
        int maxLen = 0;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            // Increment frequency/count for s[right], and update maxFreq if needed
            freq[s[right]]++;
            maxFreq = std::max(freq[s[right]], maxFreq);

            // While the current window needs more than k replacements, shrink it
            while (right - left + 1 - maxFreq > k) {
                freq[s[left]]--;
                left++;
                // Do not update maxFreq because decreasing would only produce
                // windows shorter than our current longest window found.
            }
            // Now windowSize == right - left + 1 == k + maxFreq (see above)
            // Update the window size if we found a longer window
            maxLen = std::max(right - left + 1, maxLen);
        }

        return maxLen;
    }
};
