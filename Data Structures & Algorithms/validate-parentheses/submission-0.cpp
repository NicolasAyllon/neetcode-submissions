class Solution {
public:
    bool isValid(string s) {
        // Let's keep a stack of opened parentheses, with the most recent at the top
        std::stack<char> opens;
        // Iterate through the string
        for (char c : s) {
            // If its an open paren
            if (c == '(' || c == '{' || c == '[') {
                opens.push(c);
                continue;
            }
            // It is a close paren.
            if (!opens.empty() && 
                (c == ')' && opens.top() == '(' ||
                 c == '}' && opens.top() == '{' ||
                 c == ']' && opens.top() == '[')) { // It is a close paren
                opens.pop();
            } else {
                return false;
            }
        }
        // If all open parens were matched, 
        return opens.empty();
    }
};