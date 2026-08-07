class Solution {
public:
    // Given:
    // - tasks = list of tasks 'A'-'Z'
    // - n = cooldown time
    //       where at least n CPU cycles must pass after executing a task
    //       before that task can run again
    // Returns the minimum number of CPU cycles required to run all tasks
    int leastInterval(vector<char>& tasks, int n) {
        // Count the number of tasks of each type 'A'-'Z'
        const int kNumLetters = 26;
        std::vector<int> freqs(kNumLetters, 0);
        for (char task : tasks) {
            freqs[task - 'A']++;
        }
        // Create a priority queue because we want to be able to pick the most frequent task to run first
        // Intuitively we should run the task that appears most often because we'll have to wait for it each cycle
        // (During which time we can run other tasks)
        std::priority_queue<std::pair<int, char>,
                            std::vector<std::pair<int, char>>,
                            std::less<std::pair<int, char>>> maxHeap;
        for (char task = 'A'; task <= 'Z'; ++task) {
            if (freqs[task - 'A'] > 0)
                maxHeap.push({freqs[task - 'A'], task});
        }

        // Make a queue to hold the tasks that are currently cooling down
        // Each item in the queue is a pair: (next_runnable_time, task letter)
        //
        // Note: we add items to the queue with monotonically increasing next_runnable_time,
        // so the items are already sorted by next_runnable_time (from smallest/soonest to largest/latest)
        std::queue<std::pair<int, char>> cooldownQueue;

        // Now we run the simulation where at each timestep
        int t = 0;
        while (!maxHeap.empty() || !cooldownQueue.empty()) {
            // If there are no executable tasks advance time to the next runnable time
            if (maxHeap.empty()) {
                t = cooldownQueue.front().first;
            }
            // Move all tasks that can execute at this timestep into the heap
            while (!cooldownQueue.empty() && cooldownQueue.front().first <= t) {
                const auto [time, task] = cooldownQueue.front();
                cooldownQueue.pop();
                maxHeap.push({freqs[task - 'A'], task});
            }
            // Pick the most frequent task to execute this cycle
            const auto [freq, task] = maxHeap.top();
            maxHeap.pop();
            // The task has run, so decrease its frequency
            freqs[task - 'A']--;
            // If the task still has to be run again (more than 1 remains in the frequency table)
            // Put it in the cooldown queue
            // If this is time t, at least n cooldown cycles must pass, so the next time it can run is: t + n + 1
            if (freqs[task - 'A'] > 0) {
                cooldownQueue.push({t + n + 1, task});
            }
            // One cycle has elapsed, so time increments
            t++;
        }
        // Now both the heap and queue are empty, so we finished executing the tasks
        // We executed the tasks at times T = 0 up to t = t - 1, which is a total of (t - 1) - 0 + 1 = t cycles
        return t;
    }
};
