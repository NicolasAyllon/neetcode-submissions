class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // We want to satisfy both left_i <= queries[j] AND queries[j] <= right_i
        
        // Brute force
        vector<int> result;
        result.reserve(queries.size());

        for (int q : queries) {
            result.push_back(calculateMinInterval(intervals, q));
        }
        return result;
    }

private:
    int calculateMinInterval(vector<vector<int>>& intervals, int q) {
        // Create a list of candidate intervals that contain q
        vector<vector<int>> candidates;
        for (const auto& interval : intervals) {
            if (interval[0] <= q && q <= interval[1]) {
                candidates.push_back(interval);
            }
        }
        // Return -1 if no interval contains q
        if (candidates.empty()) return -1;
        // Find the shortest candidate interval.
        int shortest = std::numeric_limits<int>::max();
        for (const auto& interval : candidates) {
            int length = interval[1] - interval[0] + 1;
            shortest = std::min(length, shortest);
        }
        return shortest;
    }
};
