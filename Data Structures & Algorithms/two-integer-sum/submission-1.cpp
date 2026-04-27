class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        // Assuming the array is not sorted, we'll iterate through the array
        for (int i = 0; i < nums.size(); ++i) {
            // If the complement (target - nums[i]) is in the map (key)
            // Get the previous index (value) and return the pair of indices as the result.
            if (map.find(target - nums[i]) != map.end())
                return {map[target - nums[i]], i}; // Since map[nums[i]] was already in the map, it occurs at the smaller index.
            // Otherwise add nums[i] -> i to map.
            map[nums[i]] = i;
        }
        // No pair summing to target was found.
        return {};
    }
};
