class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int rows = board.size();
        const int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, i, j, word, 0 /* index */, visited))
                    return true;
            }
        }
        return false;
    }

private:
    // We maintain the invariant that we've found word[0, k) (chars from index 0...k-1)
    bool dfs(const vector<vector<char>>& board, int i, int j, const string& word, int k, vector<vector<bool>>& visited) {
        // Base case: We found word[0, word.size()) which is the entire word. Success!
        if (k == word.size()) return true;

        if (i < 0 || i >= board.size() || 
            j < 0 || j >= board[0].size() ||
            visited[i][j] || 
            board[i][j] != word[k]) return false;

        // board[i][j] == word[k]
        visited[i][j] = true;
        bool result = dfs(board, i + 1, j,     word, k + 1, visited) || // up
                      dfs(board, i,     j + 1, word, k + 1, visited) || // right
                      dfs(board, i - 1, j,     word, k + 1, visited) || // down
                      dfs(board, i,     j - 1, word, k + 1, visited);   // left
        visited[i][j] = false;
        return result;
    }
};
