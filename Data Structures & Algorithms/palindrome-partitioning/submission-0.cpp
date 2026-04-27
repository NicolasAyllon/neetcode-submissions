class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result = {};
        vector<string> partition = {};
        dfs(s, 0, partition, result);
        return result;
    }

private:
    // s - the string we need to partition
    // i - the index we are currently at, meaning we want to find a palindromic substring s[i, j]
    // partition - the current list of palindromic substrings we've found up to index i
    // resulut - the list of all partitions that we'll eventually return as the result
    void dfs(string& s, int i, vector<string>& current, vector<vector<string>>& result)  {
        // Base case:
        // We've already processed all the characters, so we have a partition.
        // Add this partition to the result.
        if (i >= s.size()){
            result.emplace_back(current);
            return;
        }
        // Recursive case: (i < s.size())
        // We still have characters in s to process.
        // For every palindromic substring s[i, j] (where i <= j)
        for (int j = i; j < s.size(); ++j) {
            if (isPalindromicSubstring(s, i, j)) {
                // Add this substring to the partition
                int count = j - i + 1;
                string palindrome = s.substr(i, count);
                current.emplace_back(palindrome);
                // Recursively partition the rest of the string
                dfs(s, j + 1, current, result);
                // Backtrack, remove this substring from 'partitions'
                current.pop_back();
            }
        }
    }

    // Returns true if s[i, j] is a palindrome
    bool isPalindromicSubstring(string& s, int i, int j) {
        for (; i < j; ++i, --j) {
            if (s[i] != s[j]) 
                return false;
        }
        return true;
    }
};
