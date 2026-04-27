class Solution {
public:

    string encode(vector<string>& strs) {
        std::string result = "";
        for (const string& str : strs) {
            result += std::to_string(str.size()) + '#' + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        // If s is empty, then so is the vector of strings.
        if (s.empty()) return {};

        // There is at least one string.
        std::vector<std::string> result = {};

        int i = 0;
        while (i < s.size()) {
            int j = i;
            // Read length
            while (s[j] != '#') {
                ++j;
            }
            // Now s[j] == '#'
            int length = std::stoi(s.substr(i, j - i));
            // Place index i at the start of the string, after '#'
            i = j + 1;
            result.push_back(s.substr(i, length));
            i += length;
        }
        return result;
    }
};
