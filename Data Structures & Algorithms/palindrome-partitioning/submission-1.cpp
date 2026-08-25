class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> partition;
        backtrack(partition, 0 /*index i*/, s, res);
        return res;
    }

private:
    // Invariant: partition contains only palidromes that partition s from index 0 to i (exclusive)
    // In other words: partition contains a partition of s[0, i)
    // The next word we'll to the partition is s[i, j]
    void backtrack(std::vector<std::string>& partition,
                   int i,
                   const std::string& s,
                   std::vector<std::vector<std::string>>& res) {
        // Base Case:
        // partition is a partitions s[0, s.size()) into palindromes, which is all of s.
        // This is a valid partition, so we add a copy of it to the result.
        if (i >= s.size()) {
            res.push_back(partition);
            return;
        }

        // Recursive case:
        // i < s.size()
        // We still need to find palindromes in s for the substring starting at s[i] to the end
        for (int j = i; j < s.size(); ++j) {
            if (isPalindrome(s, i, j)) {
                partition.push_back(s.substr(i, j - i + 1)); // Add palindrome s[i, j] to the partition
                backtrack(partition,
                          j + 1, // Invariant: s is partitioned up to but not including index j + 1
                          s, res);
                partition.pop_back(); // Unchoose/backtrack
            }
        }
    }

    // Is the substring s[i, j] a palindrome from index i to j (inclusive)
    bool isPalindrome(const std::string& s, int i, int j) {
        for(; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};
