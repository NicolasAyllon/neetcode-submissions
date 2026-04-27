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
    // Scanline algorithm
    // Track the CHANGE in the number of ongoing meetings at different times.
    int minMeetingRooms(vector<Interval>& intervals) {
        std::map<int, int> time_to_delta;
        for (const auto& interval : intervals) {
            time_to_delta[interval.start]++;
            time_to_delta[interval.end]--;
        }
        // Integrate/Sum deltas to find the ongoing meeting count, tracking the max.
        int count = 0, max_count = 0;
        for (const auto& kv : time_to_delta) {
            int time = kv.first;
            int delta = kv.second;
            count += delta;
            max_count = std::max(count, max_count);
        }
        return max_count;
    }
};
