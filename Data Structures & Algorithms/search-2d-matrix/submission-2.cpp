class Solution {
public:
    // Time Complexity: O(log(m * n)) where matrix has m rows and n cols
    // Since m * n / 2^iterations == 1, or 2^i == m * n, or i == log(m * n)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int numRows = matrix.size();
        const int numCols = matrix[0].size();
        int left = 0;
        int right = numRows * numCols - 1;
        // Invariant: if present, target is in the interval of flattened indices
        // [left, right] (inclusive)
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / numCols;
            int col = mid % numCols;
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                // target must lie in flattened index interval [mid + 1, right]
                left = mid + 1;
            } else {  // matrix[row][col] > target
                // target must lie in flattened index interval [left, mid - 1]
                right = mid - 1;
            }
        }
        // Target lies in the empty interval [left, right] so it is not present
        return false;
    }
};
