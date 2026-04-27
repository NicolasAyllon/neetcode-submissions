class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        // If we encounter a close paren ')' with nesting level 0,
        // the string is invalid because there was no matching open paren '('
        int nest_level = 0; // <- unmatched open parens. Ex: "(()()..." has nest_level 1.
        int matched_pairs = 0;
        std::string candidate = "";
        // This recursive function will do the actual work.
        doGenerateParenthesis(n, candidate, result, matched_pairs, nest_level);
        return result;
    }

private:
    void doGenerateParenthesis(int n, std::string& candidate, std::vector<string>& result, int matched_pairs, int nest_level) {
        // Base cases:
        if (nest_level < 0) return; // close paren '(' encountered without matching open paren.
        if (nest_level > n) return; // too many open parens to match
        // We found a candidate with n pairs of matched parens! Add to result.
        if (matched_pairs == n) {
            if (nest_level == 0) {
                result.push_back(candidate);
            }
            return;
        }

        // Recursive case (candidate.size() < n)
        // Choose the next paren to add.
        // 1. We can always add an open paren. Matched pairs unchanged. Nest level increased.
        candidate.push_back('(');
        doGenerateParenthesis(n, candidate, result, matched_pairs, nest_level + 1);
        candidate.pop_back();
        // Backtrack/Undo

        // 2. If the nest level > 0, we can add a close paren.
        // We assume this matches a previous open paren, increasing the match count.
        // This decreases the nest level, since ')' matches a previous open '('
        candidate.push_back(')');
        doGenerateParenthesis(n, candidate, result, matched_pairs + 1, nest_level - 1);
        candidate.pop_back();
        // Backtrack/Undo
    }
};
