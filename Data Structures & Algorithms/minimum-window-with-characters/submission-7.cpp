class Solution {
public:
    string minWindow(string s, string t) {
        // Handle the case when s is shorter than t, or t is empty
        if (s.size() < t.size() || t.empty()) return "";

        std::unordered_map<char, int> tCounts;
        for (char c : t) {
            tCounts[c]++;
        }
        
        int need = tCounts.size(); // Number of distinct characters in t
        int have = 0; // Number of distinct characters in t with sufficient copies in the window

        int minLen = std::numeric_limits<int>::max();
        std::pair<int, int> result = {-1, -1};

        std::unordered_map<char, int> window;
        int left = 0;
        for (int right = 0; right < s.size(); ++right) {
            // Expand the window on the right
            window[s[right]]++;
            // String t has this character and the window has exactly the same number of copies
            if (tCounts.count(s[right]) && window[s[right]] == tCounts[s[right]]) {
                have++;
            }
            // While the window has sufficient copies of t's characters, shrink the window from the left
            while (have == need) {
                // Update min substring length
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    result = {left, right};
                }
                window[s[left]]--;
                // String t had this character and now the window has insufficient copies
                if (tCounts.count(s[left]) && window[s[left]] < tCounts[s[left]]) {
                    have--;
                }
                left++;
            }
            // Now the window does not contain all t's characters
        }
        return minLen < std::numeric_limits<int>::max() ? s.substr(result.first, minLen) : "";
    }
};
