class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Sort 'intervals' by start time and sort 'queries' by time (smallest to largest)
        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        vector<int> sorted_queries = queries;
        std::sort(sorted_queries.begin(), sorted_queries.end());
        std::unordered_map<int, int> answer;

        // Iterate through queries
        // Make min heap of pair (length, end) with min
        // The predicate 'cmp(child, parent)' shall be true for every child and its parent in the heap.
        // Each entry in the heap will be a vector of size 2 with elements {length, end_time}
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0] || a[0] == b[0] && a[1] > b[1];
        };
        std::priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> min_heap(cmp);

        int i = 0;
        for (int q : sorted_queries) {
            // Add all intervals starting before q to min_heap of (length, end_time) pairs
            while (i < intervals.size() && intervals[i][0] <= q) {
                int start = intervals[i][0];
                int end = intervals[i][1];
                min_heap.push({end - start + 1, end});
                ++i;
            }
            // Now pop all elements from the heap that end before q. (These don't contain q.)
            // They will come out of the heap in order of smallest size first,
            // In the case of ties where 2 intervals have the same size, the heap prioritizes the smaller end time.
            while (!min_heap.empty() && min_heap.top()[1] < q) 
                min_heap.pop();

            // Now the pair (length, end_time) contains q, and it is of the minimum size.
            // Record the answer (the minimum length of an interval containing q) in a hashmap.
            // We'll use the hashmap to lookup the answers to put them for the unsorted queries.
            answer[q] = min_heap.empty() ? -1 : min_heap.top()[0];
        }

        std::vector<int> result;
        for (int q : queries) {
            result.push_back(answer[q]);
        }
        return result;
    }
};
