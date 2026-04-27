class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Let's maintain a stack of indices for which we don't yet have a warmer day.
        // Note that this stack is nonincreasing, since we would have removed lower temperature days when the warmer day came
        std::stack<int> previousDays;
        std::vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); ++i) {
            // Fill in the result for any previous days that were waiting for a warmer day.
            while (!previousDays.empty() && temperatures[i] > temperatures[previousDays.top()]) {
                // This day (i) is warmer than that previous day, which was waiting for a warmer day.
                // So, fill in the result with the difference (-) in their indices, which is the number of days since the previous
                // For example if i = 10 and previousDays.top() = 7, we waited 10 - 7 = 3 days
                result[previousDays.top()] = i - previousDays.top();
                previousDays.pop();
            }
            // Add this day to the stack of previousDays awaiting a warmer day
            previousDays.push(i);
        }
        // Since we initialized the array to all zeros (0)
        // we don't need to fill in the result (0) for any days for which we never found a warmer day
        return result;
    }
};
