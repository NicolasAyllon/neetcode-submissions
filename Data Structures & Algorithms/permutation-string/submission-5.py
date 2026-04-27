class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # s2 can't contain permutations of s1 if it's shorter than s1
        if len(s2) < len(s1): 
            return False

        # Count characters in s1 and the first substring (same length as s1) in s2
        s1Counts = {}
        for i in range(len(s1)):
            s1Counts[s1[i]] = s1Counts.get(s1[i], 0) + 1

        s2Counts = {}
        left = 0
        for right in range(len(s2)):
            # Add s2[right] to window
            s2Counts[s2[right]] = s2Counts.get(s2[right], 0) + 1

            # Remove s2[left] from window
            if right >= len(s1):
                s2Counts[s2[left]] -= 1;
                left += 1;

            # If frequencies match, this window is a permutation of s1
            if frequenciesMatch(s1Counts, s2Counts):
                return True
        
        return False;

# Returns whether every letter in s1Counts has the same frequency as in s2Counts
def frequenciesMatch(s1Counts, s2Counts):
    for letter, count in s1Counts.items():
        if s2Counts.get(letter, 0) != count:
            return False;
    return True

        
        