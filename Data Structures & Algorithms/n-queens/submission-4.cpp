// Time Complexity: 
// Space Complexity: O(n^2 * num_solutions)
class Solution {
   public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> res;
        // A board of n rows of empty spaces (a string with n periods '.')
        std::vector<std::string> board(n, std::string(n, '.'));
        dfs(board, 0 /* new row index we need to place a queen */, n, res);
        return res;
    }

   private:
    // Invariant:
    // We have successfully placed nonattacking queens in rows [0, r)
    // which means row 0 up to but not including r
    void dfs(std::vector<std::string>& board, int row, int n,
             std::vector<std::vector<std::string>>& res) {
        // Base Case: we've placed queens in rows [0, n) which is all the rows
        // So, the board has a valid solution. Put a copy of the board into the result and return
        if (row == n) {
            res.push_back(board);
            return;
        }

        // Recursive Case:
        // i < n, so we still need place a queen in row i. Explore all possible columns
        for (int col = 0; col < n; ++col) {
            if (isValidPosition(row, col, board)) {
                board[row][col] = 'Q';        // choose
                dfs(board, row + 1, n, res);  // explore
                board[row][col] = '.';        // unchoose / backtrack
            }
        }
    }

    // Is the position at row index r, col index c on this board safe from attacking queens?
    bool isValidPosition(int row, int col, const std::vector<std::string>& board) {
        static const vector<std::pair<int, int>> directions = {
            {1, 0},   // down
            {-1, 0},  // up
            {0, 1},   // right
            {0, -1},  // left
            {1, 1},   // down + right
            {1, -1},  // down + left
            {-1, 1},  // up + right
            {-1, -1}  // up + left
        };
        for (const auto [dr, dc] : directions) {
            for (int r = row, c = col; r >= 0 && r < board.size() && c >= 0 && c < board.size(); r += dr, c += dc) {
                // This space lies in the path of a queen, so it's not valid
                if (board[r][c] == 'Q') {
                    return false;
                }
            }
        }
        // We checked all directions and we never encountered a queen, so this space is safe/valid
        return true;
    }
};
