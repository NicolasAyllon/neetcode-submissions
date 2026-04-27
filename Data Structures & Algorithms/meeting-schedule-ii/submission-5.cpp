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
    int minMeetingRooms(vector<Interval>& intervals) {
        // We'd like to iterate through each time when either:
        // - a meeting starts
        // - a meeting ends
        vector<int> starts;
        vector<int> ends;
        for (const auto& interval : intervals) {
            starts.emplace_back(interval.start);
            ends.emplace_back(interval.end);
        }
        // To do this sequentially, we'll have two vectors of times:
        // one for starts, one for ends. Both will be sorted.
        std::sort(starts.begin(), starts.end()); // use std::less as the comparison
        std::sort(ends.begin(), ends.end());
        // Now iterate through both arrays, always picking the smaller time.
        // If there's a tie (e.g. a meeting starts at t = 5, another ends at t = 5)
        // choose to process the end first, so the count decreases first and then increases.
        // (This prevents considering the meetings simultaneous, since they're not considered to overlap.)

        int s = 0; // index in 'starts'
        int e = 0; // index in 'ends'
        int count = 0; // The current number of ongoing meetings
        int result = 0; // Track the maximum value of 'count'
        while (s < starts.size()) {
            // At the next timestep, a meeting starts
            if (starts[s] < ends[e]) {
                ++count;
                ++s;
            }
            // At the next timestep, a meeting ends.
            // starts[s] >= ends[e]
            // It's possible a meeting may also be starting, 
            // but we choose to process endings (decrease count) first.
            else {
                --count;
                ++e;
            }
            // Update maximum count
            result = std::max(count, result);
        }
        return result;
    }
};
