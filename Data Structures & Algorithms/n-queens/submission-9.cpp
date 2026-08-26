class Solution {
   public:
    // TODO: Redo with mathematical interpretation of columns and diagonals
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> res;
        // Vector of length n, each is a string of n periods "..."
        std::vector<std::string> board(n, std::string(n, '.'));

        // Values taken by each queen
        // values of (col) in [0, n-1]
        std::vector<bool> takenCols(n, false);

        // values of (row - col) in [-(n-1), (n-1)]
        //           (row - col + n) in [1, 2n - 1], note index 0 is unused
        std::vector<bool> takenDiagsDown(2 * n, false);

        // values of (row + col) in [0, 2*(n - 1)], note index 2n-1 is unused
        std::vector<bool> takenDiagsUp(2 * n, false);

        dfs(board, 0 /*row index*/, n, takenCols, takenDiagsDown, takenDiagsUp, res);
        return res;
    }

   private:
    // Invariants:
    // board contains non-attacking queens for rows[0, row) meaning we've placed queens in rows
    // 0...row
    void dfs(std::vector<std::string>& board, int row, int n, std::vector<bool>& takenCols,
             std::vector<bool>& takenDiagsDown, std::vector<bool>& takenDiagsUp,
             std::vector<std::vector<std::string>>& res) {
        // Base case: row == n
        // We've placed queens in rows[0, n) but this is the whole board,
        // so we have a solution of n non-attacking queens. Put a copy of this board in the result
        // and return from this frame
        if (row == n) {
            res.push_back(board);
            return;
        }

        // Recursive case: row < n
        // We've placed queens in all the previous rows and still need to place a queen in this row
        // indexed 'row' Consider all possible columns where the queen could go in this row
        for (int col = 0; col < n; ++col) {
            if (!(takenCols[col] || takenDiagsDown[row - col + n] || takenDiagsUp[row + col])) {
                takenCols[col] = true;
                takenDiagsDown[row - col + n] = true;
                takenDiagsUp[row + col] = true;
                board[row][col] = 'Q';

                dfs(board, row + 1, n, takenCols, takenDiagsDown, takenDiagsUp, res);

                takenCols[col] = false;
                takenDiagsDown[row - col + n] = false;
                takenDiagsUp[row + col] = false;
                board[row][col] = '.';
            }
        }
    }
};
