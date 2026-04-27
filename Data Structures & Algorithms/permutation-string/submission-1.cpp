class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // If s2 is smaller than s1, no substring of s2 is a permutation of s1
        if (s2.size() < s1.size()) return false;

        // Get counts for characters in s1 and the first substring of s2 with the same length as s1
        constexpr int kNumLetters = 26;
        std::vector<int> s1_freq(kNumLetters, 0);
        std::vector<int> s2_window_freq(kNumLetters, 0);
        for (int i = 0; i < s1.size(); ++i) {
            s1_freq[s1[i] - 'a']++;
            s2_window_freq[s2[i] - 'a']++;
        }
        // Count matches for a...z
        int matches = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (s1_freq[c - 'a'] == s2_window_freq[c - 'a'])
                matches++;
        }
        if (matches == kNumLetters) return true;

        // First window doesn't match, scan the window from left to right
        // and update the number of matches for each. If all 26 character counts match,
        // then the current window is a permutation of s1
        int left = 0;
        for (int right = s1.size(); right < s2.size(); ++right) {
            // s2[right] comes into the window.
            s2_window_freq[s2[right] - 'a']++;
            // After the increment they match
            if (s2_window_freq[s2[right] - 'a'] == s1_freq[s2[right] - 'a'])
                matches++;
            // After the increment they no longer match
            if (s2_window_freq[s2[right] - 'a'] == s1_freq[s2[right] - 'a'] + 1)
                matches--;

            // s2[left] falls out of the window
            s2_window_freq[s2[left] - 'a']--;
            // After the decrement they match
            if (s2_window_freq[s2[left] - 'a'] == s1_freq[s2[left] - 'a'])
                matches++;
            // After the decrement they no longer match
            if (s2_window_freq[s2[left] - 'a'] == s1_freq[s2[left] - 'a'] - 1)
                matches--;
            left++;

            // If all 26 character counts match, the window is a permutation of s1
            if (matches == kNumLetters) return true;
        }
        // No substring in s2 is a permutation of s1
        return false;
    }
};
