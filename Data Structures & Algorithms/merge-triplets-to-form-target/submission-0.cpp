class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        vector<vector<int>> valid_triplets;
        for (const auto& triplet : triplets) {
            // Only add triplets where all 3 values are at most the target. 
            // Otherwise they can't be used in an operation.
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2])
                valid_triplets.emplace_back(triplet);
        }
        // Now check if, among the valid triplets, the 3 values in the target exist.
        bool contains_first = false, contains_second = false, contains_third = false;
        for (const auto& triplet : valid_triplets) {
            if (triplet[0] == target[0])
                contains_first = true;
            if (triplet[1] == target[1])
                contains_second = true;
            if (triplet[2] == target[2])
                contains_third = true;
        }
        return contains_first &&
               contains_second &&
               contains_third;
    }
};
