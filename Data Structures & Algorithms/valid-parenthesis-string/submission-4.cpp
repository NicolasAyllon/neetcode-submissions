class Solution {
public:
    bool checkValidString(string s) {
        int nest_lower_bound = 0;
        int nest_upper_bound = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                nest_upper_bound += 1;
                nest_lower_bound += 1;
            }
            if (s[i] == ')') {
                nest_upper_bound -= 1;
                nest_lower_bound -= 1;
            }
            if (s[i] == '*') {
                nest_upper_bound += 1;
                nest_lower_bound -= 1;
            }
            if (nest_upper_bound < 0)
                return false;
            if (nest_lower_bound < 0)
                nest_lower_bound = 0;
        }

        return nest_lower_bound == 0;
    }
};
