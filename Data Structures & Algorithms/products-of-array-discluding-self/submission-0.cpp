class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count_zeros = 0;
        int product_of_nonzeros = 1;
        int zero_idx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                count_zeros++;
                if (zero_idx == -1) {
                    zero_idx = i;
                }
            } else { // nums[i] != 0
                product_of_nonzeros *= nums[i];
            }
        }

        // If there are 2 or more zeros, all products are zero
        std::vector result(nums.size(), 0);
        if (count_zeros > 1)    
            return result;
        
        // If there is only 1 zero, only that index has a nonzero product
        if (count_zeros == 1) {
            result[zero_idx] = product_of_nonzeros;
            return result;
        }

        // There is no zero. Compute the product-without-self by dividing the product by each nums[i]
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = product_of_nonzeros / nums[i];
        }
        return nums;
    }


    // TODO: parallel
    vector<int> productExceptSelfParallel(vector<int> nums /* and more... */) { return {}; };
};
