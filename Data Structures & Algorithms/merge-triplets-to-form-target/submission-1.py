class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        # Record whether we found a valid triplet that contains one of (x, y, z) in the target.
        x, y, z = False, False, False # Whether we found valid triplets that contain (x, y, z) in the target

        for t in triplets:
            if (t[0] > target[0] or t[1] > target[1] or t[2] > target[2]):
                continue
            # This triplet is valid (we can use it and not exceed any values in the target triplet)
            # Keep track whether we encountered each value in the target = (x, y, z)
            x |= t[0] == target[0]
            y |= t[1] == target[1]
            z |= t[2] == target[2]
            # Can achieve all values in the target
            if x and y and z:
                return True

        return False;
        