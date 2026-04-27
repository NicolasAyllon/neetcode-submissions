class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();

        // Ranges include values from start up to, but not including, the end.
        int top = 0, bottom = m; // row index in [top, bottom) 
        int left = 0, right = n; // col index in [left, right)
        vector<int> result; result.reserve(m*n);

        // While the result doesn't have all elements in the original matrix
        // (Consider changing this condition later?)
        while (result.size() != m*n) {
            std::cout << "result.size() = " << result.size();
            // Add elements in top row
            for (int j = left; j < right && top < bottom; ++j) {
                result.emplace_back(matrix[top][j]);
            }
            // "Cross out" top row by incrementing 'top'
            ++top;
            // Add elements in rightmost column from top to bottom.
            // Recall 'right' is out of bounds, so subtract 1 to get the last in-bounds index
            for (int i = top; i < bottom && left < right; ++i) {
                result.emplace_back(matrix[i][right-1]);
            }
            // "Cross out" rightmost column by decrementing column index
            --right;
            // Add elements in the bottom row from right to left.
            for (int j = right-1; j >= left && top < bottom; --j) {
                result.emplace_back(matrix[bottom-1][j]);
            }
            // "Cross out" the bottom row by decrementing the 'bottom' row index
            --bottom;
            // Add elements in the leftmost column from bottom to top.
            for (int i = bottom-1; i >= top && left < right; --i) {
                result.emplace_back(matrix[i][left]);
            }
            // "Cross out" the leftmost column by incrementing the 'left' column index
            ++left;
        }
        return result;
    }
};
