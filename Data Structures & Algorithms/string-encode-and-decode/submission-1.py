class Solution:

    def encode(self, strs: List[str]) -> str:
        # For each string, set the first byte to be its length
        # We can use 1 byte (0-256) since 0 <= strs[i].length < 100
        res = ""
        for s in strs:
            res += str(len(s))
            res += '#'
            res += s
        
        print(res)
        return res

    def decode(self, s: str) -> List[str]:
        print("s = {}".format(s))
        res = []
        i = 0
        while i < len(s):
            j = i
            print("i = {}".format(i))
            print("j = {}".format(j))

            while s[j] != '#':
                j += 1
                print("\tStep j = {}".format(j))

            print("Advanced j = {}".format(j))
            print("s[i:j] = {}".format(s[i:j]))

            length = int(s[i:j]) # the length of the string is represented by s[i]...s[j-1]
            res.append(s[j + 1: j + 1 + length])
            i = j + 1 + length

        return res
        
