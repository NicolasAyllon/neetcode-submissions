class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        std::stack<std::pair<int, int>> s;
        int max_area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            // While there are previous (idx, height) pairs at a greater height
            // than this bar's height (heights[i]) terminate them just before this index
            
            // The lowest index of a bar of greater height.
            // We can still start a rectangle here but it will be at a lower height heights[i].

            // The earliest index at which we could start a rectangle of height heights[i].
            int i_start = i;
            while (!s.empty()) {
                const auto& [i_prev, h_prev] = s.top();
                // Terminate rectangle starting at i_prev with height h_prev
                if (h_prev > heights[i]) {
                    s.pop();
                    int area = (i - i_prev) * h_prev;
                    max_area = std::max(area, max_area);
                    i_start = i_prev;
                } else { // h_prev <= heights[i]
                    break;
                }
            }
            s.push({i_start, heights[i]});
        }
        return max_area;
    }
};
