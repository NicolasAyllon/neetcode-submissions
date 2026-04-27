
constexpr int kNumLetters = 26;

struct Node {
public:
    char letter; // May not be necessary, but here for convenience
    bool isTerminal; // There is a word in the dictionary that ends at this letter.
    Node* next[kNumLetters] = {}; // embedded in the struct

    // Used to construct the root node
    Node() {
        this->letter = '\0';
        isTerminal = false;
    }

    // Initializes the letter
    Node(char letter) {
        this->letter = letter;
        isTerminal = false;
    }
};

class WordDictionary {
public:
    WordDictionary() : root(nullptr) {
        root = new Node();
    }
    
    void addWord(string word) {
        addWord(root, 0, word);
    }
    
    bool search(string word) {
        return search(root, 0, word);
    }

private:
    Node* root;

    // Precondition: node (where we are at) is NOT nullptr
    void addWord(Node* node, int i /*index*/, const string& word) {
        // If we've processed every character, then we're done.
        // Mark this node as terminal, and return.
        if (i == word.size()) {
            node->isTerminal = true;
            return;
        }

        // More characters to process:
        // Get next character, and get corresponding index in the pointer table 'next'
        // which tells us where the next Node is.
        char letter = word[i];
        int idx = letter - 'a'; // Index of the next node
        // If that node doesn't exist yet (nullptr) first create it
        if (node->next[idx] == nullptr) {
            node->next[idx] = new Node(letter);
        }
        // Recursively call addWord, passing in the next node and index in 'word'
        addWord(node->next[idx], i + 1, word);
    }

    bool search(Node* node, int i /*index*/, const string& word) {
        std::cout << "i = " << i << ", letter" << '\n';
        std::cout << "node@" << node;
        if (node) {
            std::cout << "[ letter = " << node->letter << ", isTerminal = " << node->isTerminal << '\n';
            std::cout << "next = ";
            for (int i = 0; i < kNumLetters; ++i) 
                std::cout << '\t' << node->next[i] << '\n';
            std::cout << "]\n";
        }
        // We followed the query 'word' to a null node, which means
        // the prefix of the query isn't in the dictionary (the whole query can't be)
        if (node == nullptr) return false;

        // All characters processed and the node is not null.
        // That means word is in the dictionary as a prefix, but we still need to check
        // if the last letter of the query was marked terminal.
        if (i == word.size()) {
            return node->isTerminal;
        }

        // If it's a wildcard, search all the characters
        if (word[i] == '.') {
            for (char letter = 'a'; letter <= 'z'; ++letter) {
                if (search(node->next[letter - 'a'], i + 1, word))
                    return true;
            }
        }

        // Otherwise word[0, i-1] is in the dictionary because we're not at a null node.
        // Now process character i:
        int idx = word[i] - 'a';
        return search(node->next[idx], i + 1, word);
    }
};

