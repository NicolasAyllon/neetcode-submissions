class Solution {
   public:
    // TODO: Redo with mathematical interpretation of columns and diagonals
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> res;
        // Vector of length n, each is a string of n periods "..."
        std::vector<std::string> board(n, std::string(n, '.'));

        // Values taken by each queen
        std::unordered_set<int> setCols;       // spaces with same (col) are attacked
        std::unordered_set<int> setDiagsDown;  // spaces with same (row - col) are attacked
        std::unordered_set<int> setDiagsUp;    // spaces with same (row + col) are attacked

        dfs(board, 0 /*row index*/, n, setCols, setDiagsDown, setDiagsUp, res);
        return res;
    }

   private:
    // Invariants:
    // board contains non-attacking queens for rows[0, row) meaning we've placed queens in rows
    // 0...row
    void dfs(std::vector<std::string>& board, int row, int n, std::unordered_set<int>& setCols,
             std::unordered_set<int>& setDiagsDown, std::unordered_set<int>& setDiagsUp,
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
            if (isValidPosition(row, col, setCols, setDiagsDown, setDiagsUp)) {
                addPositionToSets(row, col, setCols, setDiagsDown, setDiagsUp);
                board[row][col] = 'Q';
                dfs(board, row + 1, n, setCols, setDiagsDown, setDiagsUp, res);
                board[row][col] = '.';
                removePositionFromSets(row, col, setCols, setDiagsDown, setDiagsUp);
            }
        }
    }

    bool isValidPosition(int row, int col, const std::unordered_set<int>& setCols,
                         const std::unordered_set<int>& setDiagsDown,
                         const std::unordered_set<int>& setDiagsUp) {
        return not (setCols.contains(col) || setDiagsDown.contains(row - col) ||
               setDiagsUp.contains(row + col));
    }

    void addPositionToSets(int row, int col, std::unordered_set<int>& setCols,
                           std::unordered_set<int>& setDiagsDown,
                           std::unordered_set<int>& setDiagsUp) {
        setCols.insert(col);
        setDiagsDown.insert(row - col);
        setDiagsUp.insert(row + col);
    }

    void removePositionFromSets(int row, int col, std::unordered_set<int>& setCols,
                                std::unordered_set<int>& setDiagsDown,
                                std::unordered_set<int>& setDiagsUp) {
        setCols.erase(col);
        setDiagsDown.erase(row - col);
        setDiagsUp.erase(row + col);
    }
};
