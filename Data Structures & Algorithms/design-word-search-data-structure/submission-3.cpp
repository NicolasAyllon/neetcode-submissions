struct TrieNode {
    bool isTerminal;     // Does this path correspond to a whole word previously inserted?
    TrieNode* next[26];  // Nodes for the next letter ('a' is index 0 ... 'z' is index 25)

    // Default constructor
    TrieNode() : isTerminal(false) {
        for (int i = 0; i < 26; ++i) {
            next[i] = nullptr;
        }
    }

    // Destructor
    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            if (next[i]) {
                delete next[i];
            }
        }
    }
};

class WordDictionary {
   public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        // Traverse the trie starting from the root, following pointers corresponding to each letter in 'word'
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            // If the next node doesn't exist yet, create it at the right index in the 'next' array
            int idx = word[i] - 'a';
            if (node->next[idx] == nullptr) {
                node->next[idx] = new TrieNode();
            }
            // Follow the pointer to the next node corresponding to this letter (word[i])
            node = node->next[idx];
        }
        // Now that we've created/followed nodes for this word, mark the last node as terminal.
        node->isTerminal = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }

    // Recursive helping function:
    // Can we find the word 'word' starting at index 'idx' and this node 'node' ?
    bool dfs(const string& word, int idx, TrieNode* node) {
        // Base Cases:
        // No path ('word[idx, word.size())' is not in the trie)
        if (node == nullptr) return false;
        // We followed all the characters in 'word' and reached a non-null node
        // This word is in the Trie if the node we're at is marked terminal
        if (idx == word.size()) {
            return node->isTerminal;
        }

        // There are still more letters to follow (node != nullptr && idx < word.size())
        // Wildcard
        char letter = word[idx];
        if (letter == '.') {
            for (int i = 0; i < 26; ++i) {
                if (dfs(word, idx + 1, node->next[i]))
                    return true;
            }
            return false;
        } 
        // Specific
        else {
            return dfs(word, idx + 1, node->next[letter - 'a']);
        }
    }

    ~WordDictionary() {
        if (root) {
            delete root;
        }
    }

   private:
    TrieNode* root;
};
