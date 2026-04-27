class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // We maintain the invariant that 
        // nums[i'] + nums[j'] != target for any i' < i or any j' > j
        // Initially the invariant holds with i = 0, and j = numbers.size() - 1
        // because there are no i' < i or j' > j
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                return {i + 1, j + 1}; // 1-based indices
            } else if (numbers[i] + numbers[j] < target) {
                i++; // Maintain invariant: no solution for i' < i + 1 and j' > j
            } else { // numbers[i] + numbers[j] > target
                // Maintain invariant: no solution for i' < i and j' > j - 1
                j--;
            }
        }
        return {};
    }
};
