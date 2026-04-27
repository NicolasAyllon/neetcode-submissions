class Solution {
public:
    bool checkValidString(string s) {
        // Define the "nest_level" to indicate the number of preceding
        // open parens that are not yet matched by close parens. 
        // Then: the characters '(', ')', and '*' do the following:
        // '(' : nest_level += 1;
        // ')' : nest_level -= 1;
        // '*' : nest_level could increase by 1, stay the same, or decrease by 1.
        // We'll track the range of possible nest values after each character.
        // If, at the end, the nest range contains 0, then there is a matching
        // of open to close parens, and the string is valid.

        std::stack<int> left_parens; // Indices of left parens '('
        std::stack<int> stars;       // Indices of stars '*'

        // Iterate through the string from left to right
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                left_parens.push(i);
            } else if (s[i] == '*') {
                stars.push(i);
            } else {
            // s[i] == ')'
            // Match this right paren with a left paren if available:
                if (!left_parens.empty())
                    left_parens.pop();
                else if (!stars.empty())
                    stars.pop();
                else // We don't have anything to match this right paren.
                    return false;
            }
        }
        // After iterating, the stacks might be nonempty
        // We can use stars to balance any left parens left.
        while (!left_parens.empty() && !stars.empty()) {
            if (left_parens.top() < stars.top()) {
                left_parens.pop();
                stars.pop();
            }
            else
                break;
        }
        return left_parens.empty();
    }
};
