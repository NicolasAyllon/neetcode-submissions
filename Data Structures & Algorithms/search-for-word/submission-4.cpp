class Solution {
public:
    // Precondition every vector in board has the same number of items
    // board[i].size() == board[j].size() for all 0 < i <= j <= n
    bool exist(vector<vector<char>>& board, string word) {
        const int rows = board.size();
        const int cols = board[0].size();
        std::vector<std::vector<bool>> picked(rows, 
                                              std::vector<bool>(cols, false));
        
        // Begin searching from all possible positions on the board
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // Can we find the word starting at board[r][c]?
                if (backtrack(r, c, 0, rows, cols, word, picked, board)) {
                    return true;
                }
            }
        }
        // We couldn't find the word starting at any position on the board
        return false;
    }

private:
    // Invariant:
    // We matched characters in word[0, i) which means from 0 up to but not including i
    // We now need to match the letter at word[i].
    bool backtrack(int r, int c, int i, int rows, int cols,
                   const std::string& word,
                   std::vector<std::vector<bool>>& picked, 
                   const std::vector<std::vector<char>>& board) {
        // Base Cases:
        // We matched the entire word! Return true for found!
        if (i == word.size()) return true;
        // Out of bounds, go back
        if (r < 0 || r >= rows || c < 0 || c >= cols) return false;
        // The desired character isn't here, go back
        if (board[r][c] != word[i]) return false;
        // Already explored here, go back
        if (picked[r][c]) return false;

        // Recursive case:
        // If we make it to this point, then we're in bounds,
        // and the desired letter word[i] is here at board[r][c]!
        //
        // We matched up to and not including index i in word, now we need to match word[i].
        //
        // Mark it as picked!
        picked[r][c] = true;
        // Explore left, right, up, and down.
        bool found = backtrack(r - 1, c, i + 1, rows, cols, word, picked, board) ||
                     backtrack(r + 1, c, i + 1, rows, cols, word, picked, board) ||
                     backtrack(r, c - 1, i + 1, rows, cols, word, picked, board) ||
                     backtrack(r, c + 1, i + 1, rows, cols, word, picked, board);
        // If we didn't find a path, unmark the grid.
        // But if we did, leave the mark
        if (!found) {
            picked[r][c] = false;
        }
        return found;
    }
};
