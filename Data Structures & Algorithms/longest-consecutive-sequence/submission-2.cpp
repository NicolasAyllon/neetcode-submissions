class Solution {
public:
    int longestConsecutiveAlternate(vector<int>& nums) {
        // Create a hash table to efficiently look up whether a number is in the array.
        // std::unordered_set<int> present;
        // for (int num : nums) {
        //     present.insert(num);
        // }
        // It is also possible to construct directly with iterators into the vector ?
        std::unordered_set<int> present(nums.begin(), nums.end());

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

    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        // Array is not empty.
        std::sort(nums.begin(), nums.end());

        int longest = 1;
        int sequence_length = 1;

        for (int i = 1; i < nums.size(); ++i) {
            // By sorting we already know nums[i-1] <= nums[i]
            // (Left bound of inequality nums[i-1] <= nums[i] <= nums[i-1]+1)
            if (nums[i] == nums[i-1]) {
                continue;
            } 
            else if (nums[i] == nums[i-1] + 1) {
                sequence_length++;
                longest = std::max(sequence_length, longest);
            } 
            // nums[i] > nums[i-1] + 1
            // This number doesn't continue the current sequence, 
            // so it must be the start of a new sequence
            else {
                sequence_length = 1;
            }
        }
        return longest;
    }
};
