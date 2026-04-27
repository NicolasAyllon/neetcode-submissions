/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // There can't be conflicts for 0 or 1 intervals.
        if (intervals.size() <= 1) return true;

        // More than 1 interval:
        // Order intervals by start time
        std::sort(intervals.begin(), intervals.end(), [](const Interval a, const Interval b) {
                                                            return a.start < b.start;
                                                         });
        // Each interval must start after the previous one ended.
        for (int i = 1; i < intervals.size(); ++i) {
            // Conflict: this interval begins before the previous one ends.
            if (intervals[i].start < intervals[i-1].end) {
                return false;
            }
        }
        return true;
    }
};
