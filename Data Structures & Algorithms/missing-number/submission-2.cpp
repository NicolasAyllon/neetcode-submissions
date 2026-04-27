class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();
        int result = n;
        for (int i = 0; i < nums.size(); ++i) {
            result += (i - nums[i]);
        }
        return result;
    }
};
