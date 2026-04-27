class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Create a hash table to efficiently look up whether a number is in the array.
        std::unordered_set<int> present;
        for (int num : nums) {
            present.insert(num);
        }
        // It is also possible to construct directly with iterators into the vector ?
        // std::unordered_set<int> present(nums.begin(), nums.end());

        // Now, we'll find the possible starts of consecutive sequences.
        int longest = 0;
        for (int num : present) {
            // A number N is a candidate start for a sequence
            // if the predecessor N-1 is not in the array.
            if (present.find(num - 1) == present.end()) {
                int len = 1;
                int next = num + 1;
                while (present.find(next) != present.end()) {
                    len++;
                    next++;
                }
                longest = std::max(len, longest);
            }
        }
        return longest;
    }
};
