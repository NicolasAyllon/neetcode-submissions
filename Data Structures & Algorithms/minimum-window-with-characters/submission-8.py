class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # Handle the case where t is empty, or when s is shorter than t
        if not t or len(s) < len(t):
            return "";
        
        # Count characters in t
        tCounts = {}
        for i in range(len(t)):
            tCounts[t[i]] = tCounts.get(t[i], 0) + 1
        
        # Now use a sliding window approach:
        # - Track the counts of characters in the window
        # - If we have at least as many copies of each character in t,
        #   and the window length is the shortest we've seen,
        #   then store the (left, right) indices for the window edges
        #   and update the min window length.
        
        need = len(tCounts) # The number of distinct characters with count 1 or more
        have = 0 # The number of t's characters that we have sufficient copies of in the window
        shortest = ""
        sWindowCounts = {}
        left = 0
        for right in range(len(s)):
            # Add s[right] to the window
            sWindowCounts[s[right]] = sWindowCounts.get(s[right], 0) + 1
            # If this character was in t and we now have sufficient copies, increment 'have' by 1
            if s[right] in tCounts and sWindowCounts[s[right]] == tCounts[s[right]]:
                have += 1;

            # While the window contains all the characters of t, shrink it from the left
            while have == need:
                # Save indices and update minimum substring length
                if shortest == "" or right - left + 1 < len(shortest):
                    shortest = s[left : right+1]
                # Leftmost character falls out of the window
                sWindowCounts[s[left]] -= 1
                # If this character was in t and we no longer have sufficient copies, decrement 'have' by 1
                if s[left] in tCounts and sWindowCounts[s[left]] < tCounts[s[left]]:
                    have -= 1
                left += 1
        
        return shortest;