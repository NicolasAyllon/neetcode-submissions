class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // For 0 or 1 intervals, we do not need to erase any intervals, so return 0.
        if (intervals.size() <= 1) return 0;

        // Sort the intervals by start time.
        // The lambda function used for comparison will return true when first should come before second.
        std::sort(intervals.begin(), intervals.end(), [](const vector<int>& first, const vector<int>& second) {
            return first.front() < second.front();
        });

        int intervals_erased = 0;
        int prev_end = intervals[0].back();
        // Iterate through the now-sorted array.
        for (int i = 1; i < intervals.size(); ++i) {
            int start = intervals[i].front();
            int end = intervals[i].back();
            // If this interval overlaps with the previous one
            if (start < prev_end) {
                // We need to erase one of the two intervals to avoid the conflict.
                // To minimize conflicts with intervals starting later (not yet seen)
                // Erase the one ending later: 
                // prev_end will will be the (earlier = min) end of the interval we're keeping
                intervals_erased++;
                prev_end = std::min(prev_end, end);
            } 
            // Intervals do not overlap, update prev_end to be the end of this interval
            else {
                prev_end = end;
            }
        }
        return intervals_erased;
    }
};
