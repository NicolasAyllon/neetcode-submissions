class Solution {
public:
    string minWindow(string s, string t) {
        const int kNumChars = 256;
        // Count frequencies in t
        std::array<int, kNumChars> t_freq = {};
        for (char c : t) {
            t_freq[c]++;
        }
        // Count frequencies in s
        std::array<int, kNumChars> s_freq = {};
        for (char c : s) {
            s_freq[c]++;
        }
        // If no substring of s can contain all characters in t, return empty.
        for (int i = 0; i < kNumChars; ++i) {
            // s doesn't have enough copies of this character in t
            if (s_freq[i] < t_freq[i]) {
                return "";
            }
        }

        // Consider substrings [start, end]
        // That is, from s[start] to s[end]
        // We'll use a sliding window approach
        std::string shortest = s;
        std::array<int, kNumChars> window_freq = {};
        
        int chars_matched = 0;
        int start = 0;
        int end = 0;
        for (; end < s.size(); ++end) {

            // Add current character to window frequency counter
            window_freq[s[end]]++;
            if (window_freq[s[end]] <= t_freq[s[end]]) {
                chars_matched++;
            }

            // s[start,end] contains all chars in t
            while (chars_matched >= t.size() && start <= end) {
                int len = end - start + 1;
                if (len < shortest.size()) {
                    shortest = s.substr(start, len);
                }
                // Contract window from left.
                // If the window's count and t's count matched exactly,
                // now we're deficient in one more character, so decrement chars_matched.
                window_freq[s[start]]--;
                if (window_freq[s[start]] < t_freq[s[start]]) {
                    chars_matched--;
                }
                start++;
            }
            // Either chars_matched < t.size() or start > end
        }
        return shortest;
    }
};
