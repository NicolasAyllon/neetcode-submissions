class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                if (dfs(board, r, c, word, 0))
                    return true;
            }
        }
        return false;
    }

private:
    // We maintain the invariant that we've found word[0, i) (chars from index 0...i-1)
    bool dfs(vector<vector<char>>& board, int r, int c, const string& word, int i) {
        // Base case: We found word[0, word.size()) which is the entire word. Success!
        if (i == word.size()) return true;

        if (r < 0 || r >= board.size() || 
            c < 0 || c >= board[0].size() ||
            board[r][c] == '*' || 
            board[r][c] != word[i]) return false;

        // board[r][c] == word[i]
        board[r][c] = '*';
        bool result = dfs(board, r + 1, c, word, i + 1) || // up
                      dfs(board, r, c + 1, word, i + 1) || // right
                      dfs(board, r - 1, c, word, i + 1) || // down
                      dfs(board, r, c - 1, word, i + 1);   // left
        board[r][c] = word[i];
        return result;
    }
};
