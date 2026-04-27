class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # Let's create a map from sorted strings 
        # to the original unsorted word.
        sorted_to_group = {}

        # If two words are anagrams then when we sort the characters
        # they are the ssame sequence. For example:
        # "listen".sorted() = eilnst and "silent".sorted() = eilnst
        for s in strs:
            s_sorted = ''.join(sorted(s))
            if s_sorted not in sorted_to_group:
                sorted_to_group[s_sorted] = [s]
            else:
                sorted_to_group[s_sorted].append(s)
        
        # Finally create result as a list of lists
        return list(sorted_to_group.values())

        