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
        // Sort intervals by start time.
        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a.start < b.start;
        });

        // Use a min-heap to hold END TIMES of previous intervals that overlap with the current interval.
        // (The element at the top will have the smallest END TIME, i.e. the earliest)
        std::priority_queue<int, vector<int>, std::greater<int>> min_heap;
        // Use Compare = std::greater since we want Compare(child, parent) -> true 
        // for all pairs in the heap. That is, child > parent, so root is the min element.

        size_t max_overlap_count = 0;
        for (const auto& interval : intervals) {
            // Remove any non-overlapping intervals from the min-heap of overlapping intervals.
            // Note: If a previous interval ends at the same time another interval starts, 
            // they are not considered to overlap.equal intervals (e.g. (2, 4) and (4, 7) do not overlap)
            while (!min_heap.empty() && min_heap.top() <= interval.start) {
                min_heap.pop();
            }
            // Now the heap only contains end times for intervals that overlap with the current one.
            min_heap.push(interval.end);
            max_overlap_count = std::max(min_heap.size(), max_overlap_count);
        }
        return max_overlap_count;
    }
};
