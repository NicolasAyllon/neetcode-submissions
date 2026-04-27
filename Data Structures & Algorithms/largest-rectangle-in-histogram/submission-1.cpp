class Solution {
public:
    // Approach:
    // Let's keep track of the largest histogram that can be formed in heights[0, i] (that is, ending at i, inclusive)
    // By keeping track of the max histogram area over all i, we get the max area over the entire histogram
    int largestRectangleArea(vector<int>& heights) {
        // To automatically handle the end of the heights array, we can add 0 as the rightmost height
        heights.push_back(0);

        // (j, heights[j]) pairs for previous indices j whose rectangles do not yet need to terminate. 
        // That is, 0 <= j < i and heights[j] <= heights[i]
        std::stack<std::pair<int, int>> indexAndHeight; 
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            std::cout << "At index " << i << ", height = " << heights[i] << '\n';
            // Find the areas of all rectangles that must be terminated at index i-1 due to heights[i] being lower
            // Also keep track of the index of each bar (decreasing as we pop items) because we could extend this bar (heights[i]) to the LEFT starting at this index
            int startIndex = i;
            while (!indexAndHeight.empty() && indexAndHeight.top().second > heights[i]) {
                startIndex = indexAndHeight.top().first;
                std::cout << "\tRectangle starting at heights[" << indexAndHeight.top().first << "] = " << indexAndHeight.top().second << ", ending at index " << i << '\n';
                int h = indexAndHeight.top().second;
                int w = i - startIndex;
                int area = w * h;
                std::cout << "\tArea = " << h << " * (" << i << " - " << indexAndHeight.top().first << ") = " << area << '\n';
                indexAndHeight.pop();
                maxArea = std::max(area, maxArea);
            }
            // Now indexAndHeight.top().second <= heights[i]
            indexAndHeight.push(std::make_pair(startIndex, heights[i]));
        }
        return maxArea;
    }
};
