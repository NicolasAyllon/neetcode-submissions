class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            res += str(len(s))
            res += '#'
            res += s
        print(res)
        return res
 
    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        while i < len(s):
            # Advance j to the index of '#'
            j = i
            while s[j] != '#':
                j += 1
            # Get the length
            length = int(s[i : j])
            # Get the substring starting after #, going that length
            res.append(s[j + 1 : j + 1 + length]) #j+1...j+length
            # Advance i to the index after the last character in the word
            i = j + 1 + length
        
        return res