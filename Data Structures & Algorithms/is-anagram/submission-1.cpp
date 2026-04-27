class Solution {
public:
    bool isAnagram(string s, string t) {
        // If s and t are different lengths, they can't be anagrams
        if (s.size() != t.size()) return false;
        // Count how many of each character there are in s and t
        // For example s_freq[0] = 3 means there are 3 'a's in s.
        const int kNumChars = 26;
        std::vector<int> s_freq(kNumChars, 0);
        std::vector<int> t_freq(kNumChars, 0);
        
        for (int i = 0; i < s.size(); ++i) {
            s_freq[s[i] - 'a']++;
            t_freq[t[i] - 'a']++;
        }
        // If the character counts differ for any letter
        // then s and t are not anagrams.
        for (char letter = 'a'; letter <= 'z'; ++letter) {
            if (s_freq[letter - 'a'] != t_freq[letter - 'a'])
                return false;
        }
        // Character counts matched for all characters,
        // so s and t are anagrams
        return true;
    }
};
