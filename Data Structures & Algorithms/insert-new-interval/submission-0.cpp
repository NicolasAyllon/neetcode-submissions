class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        for (auto it = intervals.begin(); it != intervals.end(); ++it) {
            const auto& interval = *it;
            if (newInterval.back() < interval.front()) {
                result.push_back(newInterval);
                result.insert(result.end(), it, intervals.end());
                return result;
            }
            else if (newInterval.front() > interval.back()) {
                result.push_back(interval);
            } 
            else {
                newInterval.front() = std::min(interval.front(), newInterval.front());
                newInterval.back() = std::max(interval.back(), newInterval.back());
            }
        }
        // No interval was found that started after the end of newInterval.
        // (Recall that newInterval may be 2 or more merged intervals.)
        result.push_back(newInterval);
        return result;
    }
};
