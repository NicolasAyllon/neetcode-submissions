class Solution {
public:
    bool checkValidString(string s) {
        // Brute force recursive search
        return dfs (0, 0, s);
    }

private:
    // Recursive exploration at index i with 'open' left parens '(' seen.
    bool dfs(int i, int open, const string& s) {
        // We've advanced to the end of the string
        // Valid if there are no outstanding open parens.
        if (i == s.size()) 
            return open == 0;

        // We have seen more close parens ')' than opens '('. String can't be valid.
        if (open < 0)
            return false;
        
        // Process this character at index i
        if (s[i] == '(') {
            return dfs(i + 1, open + 1, s);
        } else if (s[i] == ')') {
            return dfs(i + 1, open - 1, s);
        } else { // s[i] == '*'
            return dfs(i + 1, open + 1, s) || dfs(i + 1, open, s) || dfs (i + 1, open - 1, s);
        }
    }
};
