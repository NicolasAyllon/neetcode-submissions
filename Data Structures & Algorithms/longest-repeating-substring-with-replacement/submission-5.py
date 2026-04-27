class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        # Use the sliding window approach, keep track of the max frequency of
        # letters seen so far, and the counts of all letters in the window
        counts = {}
        left = 0
        right = 0
        maxFreq = 0
        maxLen = 0

        # Count characters in the window s[left, right] (inclusive)
        for right in range(len(s)):
            counts[s[right]] = counts.get(s[right], 0) + 1
            maxFreq = max(counts[s[right]], maxFreq)

            # While the current window requires more than k replacements, shrink it
            while right - left + 1 - maxFreq > k:
                counts[s[left]] -= 1
                left += 1
                # Note do not update maxFreq because decreasing it would only
                # lead to smaller window sizes (since right - left + 1 == k + maxFreq)

            # Now the window [left, right] requires k replacements
            # right - left + 1 == k + maxFreq
            maxLen = max(right - left + 1, maxLen)
    
        return maxLen;

        