import string

class Solution:
    def isPalindrome(self, s: str) -> bool:
        # Create a string with only the alphanumeric characters of s
        s = alphanumericOnly(s)

        # Check whether that string is a palindrome
        i = 0
        j = len(s) - 1
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True

# Remove all spaces and non-alphanumeric characters
# Any capital letters are made lowercase.
def alphanumericOnly(s: str) -> str:
    res = ""
    for c in s.lower():
        if c in string.ascii_lowercase or c in string.digits:
            res += c
    return res