struct PrefixTreeNode {
    // After traversing the tree to this node, is this the end of a word?
    bool isTerminal;
    // Array of pointers to the next node, where index 0 = 'A' and 25 = 'Z'
    PrefixTreeNode* next[26];

    // Default Constructor makes a nonterminal node
    PrefixTreeNode() {
        isTerminal = false;
        for (int i = 0; i < 26; ++i) {
            next[i] = nullptr;
        }
    }
    // Constructor with isTerminal specified
    PrefixTreeNode(bool terminal) : isTerminal(terminal) {
        for (int i = 0; i < 26; ++i) {
            next[i] = nullptr;
        }
    }

    // Destructor
    ~PrefixTreeNode() {
        for (int i = 0; i < 26; ++i) {
            if (next[i] != nullptr) {
                delete next[i];
            }
        }
    }
};

class PrefixTree {
public:
    PrefixTree() {
        root = new PrefixTreeNode();
    }
    
    void insert(string word) {
        // Traverse the tree following indices depending on each character of 'word'
        PrefixTreeNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            // Go to the next node based on this letter
            char letter = word[i];
            // Create the next node if it doesn't yet exist
            if (node->next[letter - 'a'] == nullptr) {
                node->next[letter - 'a'] = new PrefixTreeNode();
            }
            // Traverse to the next node based on this letter
            node = node->next[letter - 'a'];
        }
        // Mark the last node (after following the characters in 'word') as terminal
        node->isTerminal = true;
    }
    
    bool search(string word) {
        // Try to traverse the trie by following nodes corresponding to each letter in 'word'
        PrefixTreeNode* last = traverse(word);
        // We found the word in the trie, so we are at the node after following the last letter
        // If this was the entire word was previously inserted, then the last node (where we are) is marked terminal
        return last && last->isTerminal == true;
    }
    
    bool startsWith(string prefix) {
        PrefixTreeNode* last = traverse(prefix);
        // We found the word the trie, so we are at the node after following the last letter
        // If this was the entire word was previously inserted, then the last node (where we are) is marked terminal
        return last != nullptr;
    }

private:
    PrefixTreeNode* root;

    // Internal helping method:
    // Returns the last PrefixTreeNode after following the corresponding nodes in 'word'
    // Or returns nullptr if 
    PrefixTreeNode* traverse(string word) {
                // Try to traverse the trie by following nodes corresponding to each letter in 'word'
        PrefixTreeNode* node = root;
        for (int i = 0; i < word.size() && node != nullptr; ++i) {
            char letter = word[i];
            node = node->next[letter - 'a'];
        }
        // Either i == word.size() OR node == nullptr
        // Return the last node (which is nullptr) if we followed pointers to a dead-end
        return node;
    }
};
