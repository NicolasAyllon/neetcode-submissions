class Solution {
public:
    // Counterintuitively, for this statement of the question
    // we don't actually need to know what task is running.
    // We only need to know: 
    // - how many times left it needs to run
    // - when it can run again

    int leastInterval(vector<char>& tasks, int n) {
        // Save constant (letters in alphabet)
        const int kNumChars = 26;
        // Count tasks of each type A-Z
        std::vector<int> counts(kNumChars, 0);
        for (char task : tasks) {
            counts[task - 'A']++;
        }
        // Max-heap of task counts left.
        // Invariant: all tasks corresponding to these counts are currently RUNNABLE
        std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;
        for (int count : counts) {
            if (count > 0)
                max_heap.push(count);
        }
        
        // Now the greatest-count task in the heap to run.
        int time = 0;
        std::queue<std::pair<int, int>> q; // (count, final_cooldown_time) pairs
        while (!max_heap.empty() || !q.empty()) {
            time += 1;
            // Pick a runnable task if one is in the heap. Run it!
            if (!max_heap.empty())  {
                int count = max_heap.top() - 1; 
                max_heap.pop();
                // Add (count, next_time) to queue.
                if (count > 0) {
                    q.push({count, time + n});
                }
            }
            // Otherwise skip to the last cooldown time of the next runnable task.
            // For example if the front of the queue is (count=5, time=100), skip to time=100
            else {
                time = q.front().second;
            }
            // If time == last_cooldown, then this task will be runnable next iteration,
            // just after the line "time += 1;" executes. Add it to the heap.
            if (!q.empty() && q.front().second == time) {
                max_heap.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
