class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // If intervals contains 0 or 1 element, we don't need to do anything.
        if (intervals.size() <= 1) 
            return intervals;

        vector<vector<int>> result;
        // There are 2 or more intervals. Sort the intervals by start time.
        std::sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            // a comes before b if a.start < b.start
            return a.front() < b.front();
        });

        int merged_start = intervals[0].front();
        int merged_end = intervals[0].back();
        // For each interval after the first
        for (int i = 1; i < intervals.size(); ++i) {
            int start = intervals[i].front();
            int end = intervals[i].back();
            // If this interval overlaps with the previous, 
            // update the endpoints of the merged interval we will add.
            if (start <= merged_end) {
                // merged_start = std::min(start, merged_start); // Already done, intervals are sorted by start
                merged_end = std::max(end, merged_end);
            }
            // Otherwise, this interval does not overlap, add the merged interval calculated from previous intervals
            // and reset the merged interval to copy this interval's start and end values.
            else {  // start > merged_end
                result.push_back({merged_start, merged_end});
                merged_start = start;
                merged_end = end;
            }
        }
        // Finally, add the last merged interval to the result.
        result.push_back({merged_start, merged_end});
        return result;
    }
};
