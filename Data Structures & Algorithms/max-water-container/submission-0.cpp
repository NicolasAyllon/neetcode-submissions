class Solution {
public:
    int maxArea(vector<int>& heights) {
        // Let's use a two-pointers approach, with i and j initially the first and last index
        int i = 0;
        int j = heights.size() - 1;
        // Invariant: we've examined all possible containers 
        // starting at i', ending at j' (where i' < i and j' > j)
        // Initially, this is vacuously true because when i == 0, and j == heights.size() - 1
        // There are no indices i' < i or indices j' > j. The set we've already considered is the empty set.
        int max_area = 0;
        while (i < j) {
            // Notice that a container starting at i, ending at j has:
            // height: min(heights[i], heights[j])
            // width: j - i
            // area = width * height = (j - i) * min(heights[i], heights[j])
            int width = j - i;
            int height = std::min(heights[i], heights[j]);
            int area = width * height;

            // Update max area:
            max_area = std::max(area, max_area);

            // Now, decide which index to advance: increment i or decrement j ?
            // If we want the max area, it's possible that we could increase height by keeping the bigger one
            // That way, if a larger height shows up (at some index i < index < j) we can increase the
            // container's height. If we keep the smaller height, the container height will always be at most
            // what it is now. For that reason, keep the bigger height (keep its index) and advance the other one.

            // Index i has larger height so advance j. Prefer advancing j if their heights are equal.
            if (heights[i] >= heights[j]) {
                j--;
            } else { // heights[i] < heights[j]
                i++;
            }
        }

        return max_area;
    }
};
