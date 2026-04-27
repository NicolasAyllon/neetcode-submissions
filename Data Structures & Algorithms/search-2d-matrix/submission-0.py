class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # Let's imagine flattening the matrix into a single list, and using a single index into that list
        # Flattened indices
        numRows, numCols = len(matrix), len(matrix[0])
        left = 0
        right = numRows * numCols - 1

        # Invariant: if present, target lies in the interval of flattened indices [left, right] (inclusive)
        while left <= right:
            mid = left + (right - left) // 2
            row = mid // numCols
            col = mid % numCols
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                # target must lie in flattened index [left, mid - 1]
                right = mid - 1
            else: # matrix[row][col] < target:
                # target must lie in flattened index interval [mid + 1, right]
                left = mid + 1
        
        # Target not found (it lies in an empty interval of nums)
        return False

