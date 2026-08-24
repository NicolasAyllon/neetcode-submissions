class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string parens;
        backtrack(parens, 0 /*open*/, 0 /*closed*/, n, res);
        return res;
    }

private:
    // Invariant: that open >= close
    void backtrack(std::string& parens, int open, int close, int n, std::vector<std::string>& res) {
        // Base case:
        // There are as many open parens as close parens and the length of the string is 2*n (n pairs of parens)
        // This is a valid string of n pairs of parens, so put it in the result
        if (open == n && close == n) {
            if (open == close) {
                res.push_back(parens);
            }
            return;
        }

        // Recursive case:
        // parens.size() < 2*n
        // We can add a close paren if open > close (there's an open paren left to pair)
        if (open > close) {
            parens.push_back(')');                      // choose
            backtrack(parens, open, close + 1, n, res); // explore
            parens.pop_back();                          // unchoose
        }
        // We can add an open paren if there is less than n of them so far
        if (open < n) {
            parens.push_back('(');
            backtrack(parens, open + 1, close, n, res);
            parens.pop_back();
        }
    }
};
