class Solution {
public:
    // TODO: Redo with Dynamic Programming
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> partition;

        // Precompute the answer to the question:
        // dp[i][j] = is substring s[i, j] a palindrome?
        const int n = s.size();
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
        // i = start index
        // l = substring length
        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i <= n - l; ++i) {
                dp[i][i + l - 1] = s[i] == s[i + l - 1] &&  // letters at either end match
                                   (i + 1 > i + l - 2 ||    // moving indices inward causes them to overlap
                                   dp[i + 1][i + l - 2]);   // inner substring is a palindrome OR     
            }
        }
        backtrack(s, 0, dp, partition, res);
        return res;
    }

private:
    // Invariant:
    // partitions contains a valid partition of s[0, i)
    // meaning from index 0 up to i exclusive (not including i)
    void backtrack(const std::string& s, int i,
                   const std::vector<std::vector<bool>>& dp,
                   std::vector<std::string>& partition,
                   std::vector<std::vector<std::string>>& res) {
        // Base Case:
        // If i == s.size(), then s[0, s.size()) is partitioned, which is all of s
        if (i == s.size()) {
            res.push_back(partition);
            return;
        }
        // Recursive Case:
        // i < s.size(), so we need to recursively explore all possible partitions
        // we could make by adding palindromic substrings starting at index i
        // (since s[0, i) is already partitioned)
        for (int j = i; j < s.size(); ++j) {
            // Substring s[i, j] is a palindrome, precomputed in the dp table
            if (dp[i][j]) {
                partition.push_back(s.substr(i, j - i + 1));
                // Invariant s[0, j] is partitioned, or s[0, j + 1) is partitioned
                backtrack(s, j + 1, dp, partition, res); 
                partition.pop_back();
            }
        }
    }
};
