class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // If intervals contains 0 or 1 element, we don't need to do anything.
        if (intervals.size() <= 1) 
            return intervals;

        // There are 2 or more intervals. Sort the intervals by start time.
        std::sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            // a comes before b if a.start < b.start
            return a.front() < b.front();
        });

        vector<vector<int>> result = {intervals[0]};
        // For each interval after the first
        for (int i = 1; i < intervals.size(); ++i) {
            // If this interval overlaps with the previous, 
            // update the endpoints of the merged interval we will add.
            int prev_end = result.back().back();
            int start = intervals[i].front();
            int end = intervals[i].back();
            if (start <= prev_end) {
                // merged_start = std::min(start, merged_start); // Already done, intervals are sorted by start
                result.back().back() = std::max(end, prev_end);
            }
            // Otherwise, this interval does not overlap, add the merged interval calculated from previous intervals
            // and reset the merged interval to copy this interval's start and end values.
            else {  // start > merged_end
                result.push_back({start, end});
            }
        }
        return result;
    }
};
