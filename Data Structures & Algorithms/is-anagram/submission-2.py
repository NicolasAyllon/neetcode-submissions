import string

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # Find the count of each character in s
        s_counts = {}
        for letter in s:
            if letter in s_counts:
                s_counts[letter] += 1
            else:
                s_counts[letter] = 1

        # Find count of each character in t
        t_counts = {}
        for letter in t:
            if letter in t_counts:
                t_counts[letter] += 1
            else:
                t_counts[letter] = 1

        # For every possible character, check that s and t have the same count
        return s_counts == t_counts