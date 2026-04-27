class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // First idea: use a vector of bools for the rows to say whether they should be zeroed.
        // Keep another vector of bools to say whether a column should be zeroed.
        const int m = matrix.size();
        const int n = matrix[0].size();
        std::vector<bool> zero_this_row(m, false);
        std::vector<bool> zero_this_col(n, false);
        // Iterate over the matrix and switch the indexes row[i] if row i should be zeroed.
        // Similarly switch the column-tracking vector to 'true' if col[j] should be zeroed.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    zero_this_row[i] = true;
                    zero_this_col[j] = true;
                }
            }
        }
        // Now zero the rows of the original matrix
        for (int i = 0; i < m; ++i) {
            if (zero_this_row[i]) {
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        // And zero the corresponding columns of the original matrix
        for (int j = 0; j < n; ++j) {
            if (zero_this_col[j]) {
                for (int i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
