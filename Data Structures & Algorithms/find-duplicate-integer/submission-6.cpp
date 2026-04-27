class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // We will use the original array itself as a hash set.
        for (int num : nums) {
            std::cout << "num = " << num << std::endl;
            // We store whether we've seen this value by 
            // whether the sign at the corresponding index is negative.
            int val = std::abs(num);
            int idx = val-1;
            std::cout << "index = " << idx << std::endl;
            // Already seen this value, toggle back to positive, return value.
            bool value_present = nums[idx] < 0;
            if (value_present) {
                nums[idx] *= -1;
                return val;
            } 
            // Otherwise negate the value at this index.
            nums[idx] *= -1;
        }
        // To mark k (in 1...n) as seen, we change the value at index k-1 (in 0...n-1) to negative.
        return -1;
    }
};
