class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        sorted_to_group = {}
        for s in strs:
            s_sorted = ''.join(sorted(s))
            if s_sorted not in sorted_to_group:
                sorted_to_group[s_sorted] = [s]
            else:
                sorted_to_group[s_sorted].append(s)
        return list(sorted_to_group.values());
        