class Solution {
   public:
    vector<string> letterCombinations(string digits) {
        // Handle empty string
        if (digits.size() == 0) {
            return {};
        }

        std::vector<std::string> res;
        std::string combination;
        std::unordered_map<int, std::vector<char>> digitToLetterMap = {{0, {}},
                                                                       {1, {}},
                                                                       {2, {'a', 'b', 'c'}},
                                                                       {3, {'d', 'e', 'f'}},
                                                                       {4, {'g', 'h', 'i'}},
                                                                       {5, {'j', 'k', 'l'}},
                                                                       {6, {'m', 'n', 'o'}},
                                                                       {7, {'p', 'q', 'r', 's'}},
                                                                       {8, {'t', 'u', 'v'}},
                                                                       {9, {'w', 'x', 'y', 'z'}}};

        dfs(digits, 0 /*index*/, digitToLetterMap, combination, res);
        return res;
    }

   private:
    // Invariant: combination contains a possible letter sequence for digits[0, i)
    // The notation digits[0, i) means the characters in digits from index 0 up to
    // but not including i.
    void dfs(const std::string& digits, int i,
             const std::unordered_map<int, std::vector<char>>& digitToLetterMap,
             std::string& combination, std::vector<std::string>& res) {

        // Base Case:
        // i is one-past-the-end of digits, so by the invariant, 
        // combination contains a letter sequence for digits[0, digits.size())
        // which is the whole string, digits
        if (i >= digits.size()) {
            res.push_back(combination);
            return;
        }

        // Recursive Case:
        // i < digits.size() so we need to explore all combinations for letters
        // corresponding to digits[i]. combination has a sequence for digits[0, i)
        int digit = digits[i] - '0';
        for (char letter : digitToLetterMap.at(digit)) {
            combination.push_back(letter);
            dfs(digits, i + 1, digitToLetterMap, combination, res);
            combination.pop_back();
        }
    }
};
