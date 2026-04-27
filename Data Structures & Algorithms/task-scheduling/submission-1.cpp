class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Following Hint 1, we'll find the frequency of each task A-Z
        const int kNumChars = 26; // Number of letters in alphabet
        std::vector<int> counts(kNumChars, 0);
        std::vector<int> last_run(kNumChars, -1);
        int total_tasks = 0;
        for (char task : tasks) {
            counts[task - 'A']++;
            total_tasks++;
        }

        // Iterate over letters/tasks
        int time = 0;
        while (total_tasks > 0) {

            // SELECT TASK
            // Brute force linear search for max-count scheduleable task
            int idx_max = -1;
            int count_max = 0;
            for (int i = 0; i < kNumChars; ++i) {
                // If task i has the biggest count seen so far
                if (counts[i] > count_max) {
                    // And we can schedule it (n-step cooldown has passed)
                    if (last_run[i] == -1 || time - last_run[i] > n) {
                        // Update selected task
                        idx_max = i;
                        count_max = counts[i];
                    }
                }
            }
            // SCHEDULE TASK
            // If we found a runnable task (task != -1), decrease its count and update last run time
            if (idx_max >= 0) {
                counts[idx_max]--;
                total_tasks--;
                last_run[idx_max] = time;
            }
            // Update time
            time++;
        }
        return time;
    }
};
