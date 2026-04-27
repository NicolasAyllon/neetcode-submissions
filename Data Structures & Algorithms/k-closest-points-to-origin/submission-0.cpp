class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Use to make a max_heap where each child is **less** than its parent
        auto less_Euclidean_distance = [this](const std::vector<int>& p1, const std::vector<int>& p2) {
            return distance_to_origin_squared(p1) < distance_to_origin_squared(p2);
        };

        std::priority_queue<std::vector<int>, 
                            std::vector<std::vector<int>>, 
                            decltype(less_Euclidean_distance)> 
                                max_heap(less_Euclidean_distance);
        
        for (const auto& point : points) {
            if (max_heap.size() < k || 
                distance_to_origin_squared(point) < distance_to_origin_squared(max_heap.top())) {
                max_heap.push(point);
            }
            if (max_heap.size() > k) {
                max_heap.pop();
            } 
        }

        std::vector<std::vector<int>> result;
        while (!max_heap.empty()) {
            result.push_back(max_heap.top());
            max_heap.pop();
        }
        return result;
    }
    
private:
    int distance_to_origin_squared(const std::vector<int>& p) {
        return p[0] * p[0] + p[1] * p[1];
    }
};
