constexpr int kNumLetters = 26;

struct TrieNode {
    bool isWord;
    TrieNode* next[kNumLetters];

    // The default constructor doesn't mark a nodes as 
    // representing the end of a word (isWord = false)
    TrieNode() : isWord(false) {
        for (int i = 0; i < kNumLetters; ++i) {
            next[i] = nullptr;
        }
    }

    ~TrieNode() {
        for (int i = 0; i < kNumLetters; ++i) {
            if (next[i] != nullptr) {
                delete next[i];
            }
        }
    }
};

class Trie {
public:
    Trie(const std::vector<std::string>& words) {
        root_ = new TrieNode();
        for (const std::string& word : words) {
            insert(word, root_);
        }
    }

    TrieNode* root() {
        return root_;
    }

private:
    TrieNode* root_;

    void insert(const std::string& word, TrieNode* root_) {
        TrieNode* node = root_;
        for (int i = 0; i < word.size(); ++i) {
            // If the next node to follow doesn't exist yet, create it
            int idx = word[i] - 'a';
            if (node->next[idx] == nullptr) {
                node->next[idx] = new TrieNode();
            }
            // Follow the next node corresponding to this letter (word[i])
            node = node->next[idx];
        }
        // After following (and creating) all nodes for the characters of this word
        // Mark the node arrived at after the last character as a whole word
        node->isWord = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // 1. Create a Trie data structure to hold all the strings in 'words'
        Trie trie(words);

        // 2. Iterate through every possible grid space
        std::unordered_set<std::string> foundWords;
        std::string word = "";

        const int rows = board.size();
        const int cols = board[0].size();

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                dfs(board, r, c, trie.root(), word, foundWords);
            }
        }

        // Return a vector of string constructed from the unordered_set
        return std::vector(foundWords.begin(), foundWords.end());
    }

private:
    // Note: visited board spaces are marked with asterisk '*'
    // Invariant: the current string made by our path matches at least one word in the Trie
    void dfs(std::vector<std::vector<char>>& board, int r, int c, TrieNode* node, std::string& word, std::unordered_set<std::string>& foundWords) {
        
        const int rows = board.size();
        const int cols = board[0].size();

        // Base Cases:
        // We arrived at a node that is not null, and it corresponds to a whole word in the trie, 
        // so we found a word in the trie. Put it in the set of found words and return.
        // Note: it's OK if we're out of bounds because we already verified the previous space had the last character of a word in the Trie
        if (node->isWord) {
            foundWords.insert(word);
        }
        // Out of bounds
        if (r < 0 || r >= rows || c < 0 || c >= cols) return;
        // In bounds, but already visited
        if (board[r][c] == '*') return;
        // In bounds, and not yet visited, but this letter does not follow the previous letters for any word in the Trie
        if (node->next[board[r][c] - 'a'] == nullptr) return;

        // Recursive Case:
        // In bounds, not yet visited, and this letter follows the ones on the path (in the current 'word')
        char letter = board[r][c];
        TrieNode* nextNode = node->next[letter - 'a'];
        // choose
        board[r][c] = '*';      
        word.push_back(letter);
        // explore
        dfs(board, r - 1, c, nextNode, word, foundWords);
        dfs(board, r + 1, c, nextNode, word, foundWords);
        dfs(board, r, c - 1, nextNode, word, foundWords);
        dfs(board, r, c + 1, nextNode, word, foundWords);
        // unchoose/restore
        board[r][c] = letter;
        word.pop_back();
    }
};
