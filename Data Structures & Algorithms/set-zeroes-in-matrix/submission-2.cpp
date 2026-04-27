class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // First idea: use a vector of bools for the rows to say whether they should be zeroed.
        // Keep another vector of bools to say whether a column should be zeroed.
        const int m = matrix.size();
        const int n = matrix[0].size();
        // Use matrix[i][0] to track if row i should be zeroed.
        // Use matrix[0][j] to track if column j should be zeroed.
        // Since matrix[0][0] can only hold 1 value, let it be for the rows
        // A separate bool 'zero_first_column' will track whether first column should be zeroed.
        bool zero_first_column = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    // Track row
                    matrix[i][0] = 0;
                    // Track Column (using the bool for the first column)
                    if (j == 0) {
                        zero_first_column = true;
                    } else {
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        // Zero rows and columns with indices >=1 of the original matrix
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // Zero first row if needed
        if (matrix[0][0] == 0) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
        // Zero out the first column if needed, based on the bool 'zero_first_column'
        if (zero_first_column) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
