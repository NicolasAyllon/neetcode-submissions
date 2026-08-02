class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
            const auto& [x1, y1] = p1;
            const auto& [x2, y2] = p2;
            return x1 * x1 + y1 * y1 < x2 * x2 + y2 * y2;
        };
        std::priority_queue<std::pair<int,int>,
                            std::vector<std::pair<int, int>>,
                            decltype(cmp)> maxHeap(cmp);

        for (auto point : points) {
            maxHeap.push({point[0], point[1]});
            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        // Get the resulting vector<vector<int>> for the K closest points
        std::vector<std::vector<int>> res;
        while (!maxHeap.empty()) {
            const auto& [x, y] = maxHeap.top(); 
            res.push_back({x, y});
            maxHeap.pop();
        }
        return res;
    }
};
