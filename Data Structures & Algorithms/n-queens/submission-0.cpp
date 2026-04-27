class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> solutions = {};
        // Fill in the solutions vector, and return it
        dfs(n, 0 /*row*/, board, solutions);
        return solutions;
    }

private:
    // Invariant: 'row' = the row in which we wish to place a nonattacking queen
    void dfs(int n, int row, vector<string>& board, vector<vector<string>>& solutions) {
        // If we found a valid placement for all queens (we're at row n, and rows 0...n-1 have queens) then this a solution
        if (row == n) {
            solutions.emplace_back(board);
            return;
        }
        // Otherwise, we need to try to place a queen in row i.
        // Try all the columns
        for (int col = 0; col < n; ++col) {
            if (isSafePosition(n, board, row, col)) {
                // Choose: add this row to the solution we're building
                board[row][col] = 'Q';
                // Recursively find the rest of the rows
                dfs(n, row + 1, board, solutions);
                // Unchoose: remove this row from the solution, and mark space empty.
                board[row][col] = '.';
            }
        }
    }

    // Returns whether the position is in danger of attack from previous queens
    bool isSafePosition(int n, const vector<string>& board, int row, int col) {
        // If the position is already filled, or out of bounds, it's not valid (return false for now)
        if (board[row][col] == true) return false;
        if (row < 0 || row >= n || col < 0 || col >= n) return false;

        // Start from the position, and try all 8 directions from which a queen could attack
        static vector<pair<int, int>> dirs = {
            {-1,  0}, // N
            {-1,  1}, // NE
            { 0,  1}, // E
            { 1,  1}, // SE
            { 1,  0}, // S
            { 1, -1}, // SW
            { 0, -1}, // W
            {-1, -1}  // NW
        };

        for (const auto& dir : dirs) {
            int r = row;
            int c = col;
            while (true) {
                // Advance along this direction to the next space
                r += dir.first;
                c += dir.second;
                // If out of bounds, we're done exploring this direction
                if (r < 0 || r >= n) break;
                if (c < 0 || c >= n) break;
                // This position is in bounds. 
                // If we ever find a queen, position (row, col) is not safe.
                if (board[r][c] == 'Q')
                    return false;
            }
        }
        // We never found a queen along any direction of attack, so this space is safe.
        return true;
    }
};
