class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # Let's create a map from sorted strings 
        # to the original unsorted word.
        groups = {}

        # If two words are anagrams then when we sort the characters
        # they are the ssame sequence. For example:
        # "listen".sorted() = eilnst and "silent".sorted() = eilnst
        for word in strs:
            sorted_word = ''.join(sorted(word))
            if sorted_word in groups:
                groups[sorted_word].append(word)
            else:
                groups[sorted_word] = [ word ]
        
        # Finally create result as a list of lists
        result = []
        for group in groups.values():
            result.append(group)

        return result

        