import string

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Strings of different length can't be anagrams
        if len(s) != len(t):
            return False

        # Initialize all letter counts to 0
        s_freq, t_freq = {}, {}
        for letter in string.ascii_lowercase:
            s_freq[letter] = t_freq[letter] = 0

        # Count frequencies
        for letter in s:
            s_freq[letter] += 1
        for letter in t:
            t_freq[letter] += 1
        
        # If the frequency of any letter doesn't match, they're not anagrams
        for letter in string.ascii_lowercase:
            if s_freq[letter] != t_freq[letter]:
                return False
        return True
        