class Solution {
public:
    // Counterintuitively, for this statement of the question
    // we don't actually need to know what task is running.
    // We only need to know: 
    // - how many times left it needs to run
    // - when it can run again

    int leastInterval(vector<char>& tasks, int n) {
        // Use a max-heap to hold the counts of the remaining tasks
        // so we can get the max count in O(1) time.

        // Get the counts of each task 'A' - 'Z'
        const int kNumChars = 26;
        std::vector<int> counts(kNumChars, 0);
        for (char c : tasks) {
            counts[c - 'A']++;
        }
        // Add all tasks with nonzero count to the max-heap.
        // Note: we only add the counts (number of times left to run). 
        // The identity of the task (e.g. 'A', 'B', ...) is not needed.
        std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;
        for (int count : counts) {
            if (count > 0)
                max_heap.push(count);
        }

        // We maintain the invariants:
        // max_heap: contains the remaining (count) for RUNNABLE tasks
        //           that is, tasks that have never run, or their cooldown has passed
        // queue q: contains a pair (count, cooldown_end_time) COOLING DOWN tasks
        //          can't run again yet because the cooldown is still happening.
        std::queue<std::pair<int, int>> q;
        int time = 0;
        // While there are still tasks RUNNABLE or COOLING DOWN 
        while (!max_heap.empty() || !q.empty()) {

            // Select ONE next runnable task.
            // We'll pick it from either the heap or queue
            if (!max_heap.empty()) {
                // Pick up task and run for 1 unit time.
                int count = max_heap.top() - 1;
                max_heap.pop();
                // If it will run again, place it in the queue.
                if (count > 0) {
                    // (remaining count, time + n)
                    q.push({count, time + n});
                }
            } 
            // Pick cooling-down task from queue and advance time
            else {
                time = q.front().second + 1;
                int count = q.front().first - 1;
                // It will run at time that is 1 after the last time period spent in cooldown
                q.pop();
                if (count > 0) {
                    q.push({count, time + n});
                }
            }

            // Move to next time interval after the selected task has run.
            time += 1;

            // Maintain invariant for queue:
            // Move now runnable tasks to heap.
            while (!q.empty() && q.front().second < time) {
                // Push task count in heap.
                max_heap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
