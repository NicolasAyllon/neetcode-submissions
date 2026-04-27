class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<string> result;
        std::string combination;
        dfs(digits, 0, combination, result);
        return result;
    }

private:

    void dfs(const string& digits, int i, string& combination, vector<string>& result) {
        // Base case 1:
        // No letters for an empty digit string.
        if (digits.empty()) return;

        // Base case 2.
        // We've already processed characters [0, i) which is all the characters.
        // We have a letter combination in the 'combination' parameter, so add it to the result
        if (i >= digits.size())  {
            result.emplace_back(combination);
            std::cout << "added combination " << combination << '\n';
            return;
        }
        
        // Recursive case: (i < s.size())
        // There are still more characters to process.
        // Explore all the possible characters for this digit.
        std::cout << "digit = " << digits[i] << '\n';
        for (char letter : digit_to_chars.at(digits[i])) {
            // Add/push this char to the combination string
            combination.push_back(letter);
            // Recursively choose characters for the remaining digits
            dfs(digits, i + 1, combination, result);
            // Backtrack: remove/pop the character we added to the combination
            combination.pop_back();
        }
    }

    const unordered_map<char, vector<char>> digit_to_chars = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
};
