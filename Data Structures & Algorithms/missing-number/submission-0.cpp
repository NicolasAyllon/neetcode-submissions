class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();
        int all = n * (n + 1) / 2;
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        return all - sum;
    }
};
