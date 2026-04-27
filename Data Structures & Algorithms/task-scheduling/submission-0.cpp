class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Following Hint 1, we'll find the frequency of each task A-Z
        const int k_num_chars = 26; // Number of letters in alphabet
        std::array<int, k_num_chars> task_counts; 
        task_counts.fill(0);
        std::array<int, k_num_chars> last_run;
        last_run.fill(-1);
        int total_tasks = 0;
        for (char task : tasks) {
            task_counts[task - 'A']++;
            total_tasks++;
        }

        // Iterate over letters/tasks
        int time = 0;
        while (total_tasks > 0) {

            // SELECT TASK
            // Brute force linear search to find:
            // Task that can be scheduled and has the greatest count
            int idx_max = -1;
            int count_max = 0;
            for (int i = 0; i < k_num_chars; ++i) {
                // If task i has the biggest count so far
                if (task_counts[i] > count_max) {
                    // And we can schedule it (n-step cooldown has passed)
                    if (last_run[i] == -1 || time - last_run[i] > n) {
                        // Update selected task
                        idx_max = i;
                        count_max = task_counts[i];
                    }
                }
            }
            // SCHEDULE TASK
            // If we found a task to run (task != -1), decrease its count and update last run time
            if (idx_max >= 0) {
                task_counts[idx_max]--;
                total_tasks--;
                last_run[idx_max] = time;
            }
            // Update time
            time++;
        }
        return time;
    }
};
