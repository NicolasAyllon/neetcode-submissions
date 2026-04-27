class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // Build graph of words where edge (w1, w2) means w1 and w2 can be transformed
        // into each other by changing 1 character.
        // Use indices instead of a hashmap for simplicity.
        int targetWordIndex = -1;
        std::vector<std::vector<int>> adj(wordList.size());
        for (int i = 0; i < wordList.size(); ++i) {
            if (wordList[i] == endWord)
                targetWordIndex = i;
            for (int j = i + 1; j < wordList.size(); ++j) {
                if (isOneCharacterDifferent(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        // If the target word isn't in the list, we can't find a sequence.
        if (targetWordIndex == -1) return 0;

        // Initialize queue with possible words 1 letter away from start
        std::queue<int> q;
        std::vector<bool> visited(wordList.size(), false);

        for (int i = 0; i < wordList.size(); ++i) {
            if (isOneCharacterDifferent(beginWord, wordList[i])) {
                q.push(i);
                visited[i] = true;
            }
        }

        int seq_length = 2; // {beginWord, nextWord}
        while (!q.empty()) {
            // Process all words at the ends of sequences
            // of the current length 'seq_length'
            int sz = q.size();
            while (sz--) {
                // Get word (index) off queue.
                // If it's the target end word, return the current sequence length.
                int i = q.front(); q.pop();
                if (i == targetWordIndex) {
                    return seq_length;
                }
                // Add each unvisited neighbor to queue.
                for (int j : adj[i]) {
                    if (!visited[j]) {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
            // Now everything in the queue is the last of a sequence
            // with length 'seq_length'
            seq_length++;
        }
        // No sequence was found.
        return 0;
    }

private: 
    bool isOneCharacterDifferent(const std::string& s1, const std::string& s2) {
        // Without loss of generality require s1.size() >= s2.size()
        if (s1.size() < s2.size()) 
            return isOneCharacterDifferent(s2, s1);

        int diffs = s1.size() - s2.size();
        for (int i = 0; i < std::min(s1.size(), s2.size()); ++i) {
            if (s1[i] != s2[i])
                diffs++;
        }
        return diffs == 1;
    }
};
