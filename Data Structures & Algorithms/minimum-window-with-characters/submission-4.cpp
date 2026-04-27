class Solution {
public:
    string minWindow(string s, string t) {
        // s can't contain all the characters in t (including duplicates) if it's shorter than t
        if (s.size() < t.size()) return "";

        // First, find the frequency of the characters in t
        std::unordered_map<char, int> tCounts;
        for (char c : t) {
            tCounts[c]++;
        }

        // Use a sliding window, considering substrings [left, right] inclusive
        std::string shortest = "";
        int minLen = std::numeric_limits<int>::max();

        std::unordered_map<char, int> sCounts;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            // Add s[right] to the window
            sCounts[s[right]]++;
            std::cout << "window expanded to " << s.substr(left, right - left + 1) << '\n';

            // While the window contains all the characters in t (including duplicates) record its length, then shrink the window
            // If this window contains at least the characters in t, record its length
            while (containsAllCharacters(sCounts, tCounts)) {
                std::cout << "window = " << s.substr(left, right - left + 1) << " contains all characters" << '\n';
                if (right - left + 1 < minLen) {
                    std::cout << "New shortest window found" << '\n';
                    shortest = s.substr(left /*pos*/, right - left + 1 /*count*/);
                    minLen = right - left + 1;
                    std::cout << "shortest = " << shortest << ", minLen = " << minLen << '\n';
                }
                // s[left] falls out of the window as we shrink it
                sCounts[s[left]]--;
                left++;
                std::cout << "shrunk window to " << s.substr(left, right - left + 1) << '\n';
            }
        }
        return shortest;
    }

private:
    // Returns whether sCounts has at least as many copies of each character in tCounts
    bool containsAllCharacters(std::unordered_map<char, int>& sCounts, std::unordered_map<char, int>& tCounts) {
        for (const auto& [letter, tCount] : tCounts) {
            if (sCounts[letter] < tCount) {
                return false;
            }
        }
        return true;
    }
};
