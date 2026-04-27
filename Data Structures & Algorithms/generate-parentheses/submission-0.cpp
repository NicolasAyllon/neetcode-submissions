class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        // If we encounter a close paren ')' with nesting level 0,
        // the string is invalid because there was no matching open paren '('
        int nest_level = 0; // <- unmatched open parens. Ex: "(()()..." has nest_level 1.
        std::string candidate = "";
        // This recursive function will do the actual work.
        // The 
        doGenerateParenthesis(2*n, candidate, result, nest_level);
        return result;
    }

private:
    void doGenerateParenthesis(int n, std::string& candidate, std::vector<string>& result, int nest_level) {
        // Base cases:
        // - A close paren was encountered without matching open paren.
        if (nest_level < 0) return;
        // - If the length of the candidate is n and nest level is 0, it's a valid string.
        if (candidate.size() == n) {
            if (nest_level == 0) {
                result.push_back(candidate);
            }
            return;
        }

        // Recursive case (candidate.size() < n)
        // Choose the next paren to add.
        // 1. We can always add an open paren. This increases the nest level.
        candidate.push_back('(');
        doGenerateParenthesis(n, candidate, result, nest_level + 1);
        candidate.pop_back();
        // Backtrack/Undo

        // 2. If the nest level > 0, we can add a close paren.
        // This decreases the nest level, since ')' matches a previous open '('
        candidate.push_back(')');
        doGenerateParenthesis(n, candidate, result, nest_level - 1);
        candidate.pop_back();
        // Backtrack/Undo
    }
};
