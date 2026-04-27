class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Let's count all the characters in s1
        std::unordered_map<char, int> freq1;
        for (char c : s1) {
            freq1[c]++;
        }

        // Now iterate over characters in s2 using a window of length s1.size()
        // That is, a window whose size matches the length of s1.
        // Only a window of this size could be a permutation of s1.
        std::unordered_map<char, int> windowFreq;
        int left = 0;
        for (int right = 0; right < s2.size(); ++right) {
            // Add s2[right] to the window
            windowFreq[s2[right]]++;
            // If window is size > s1.size(), shrink the window from the left
            if (right - left + 1 > s1.size()) {
                windowFreq[s2[left]]--;
                left++;
            }
            
            // Compare window character frequencies to s1's character frequencies
            // If they match, then this window is a permutation of s1
            if (frequenciesMatch(windowFreq, freq1)) return true;
        }
        // We scanned through substrings of s2 of size s1.size() and didn't find
        // any permutation of s1.
        return false;
    }

private:
    // Returns whether the character counts in window match the counts in freq
    bool frequenciesMatch(std::unordered_map<char, int>& windowFreq,
                          std::unordered_map<char, int>& freq) {
        for (const auto& [letter, count] : freq) {
            if (windowFreq[letter] != count)
                return false;
        }
        return true;
    }
};
