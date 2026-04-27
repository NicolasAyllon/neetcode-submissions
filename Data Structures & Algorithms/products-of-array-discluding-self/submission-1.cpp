class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Alternate Method: Prefix and Suffix Products
        // prefixes[i] = product of nums entries from index 0, to i - 1 (inclusive)
        std::vector prefixes(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            prefixes[i] = prefixes[i - 1] * nums[i - 1];
        }
        // suffixes[i] = product of nums entries from index i + 1 to nums.size()-1 (inclusive)
        std::vector suffixes(nums.size(), 1);
        for (int i = nums.size() - 2; i >= 0; --i) {
            suffixes[i] = suffixes[i + 1] * nums[i + 1];
        }

        // The product-except-self is the product of the prefixes and suffixes of corresponding elems
        // ( nums[0]*...*nums[i-1] )( nums[i+1]*...*nums[nums.size()-1] )
        // = prefixes[i] * suffixes[i]
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = prefixes[i] * suffixes[i];
        }
        return nums;
    }


    // TODO: parallel
    vector<int> productExceptSelfParallel(vector<int> nums /* and more... */) { return {}; };
};
