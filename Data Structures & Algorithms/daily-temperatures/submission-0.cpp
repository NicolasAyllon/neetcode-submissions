class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Let's have a stack that contains indices for days that
        // haven't seen a warmer temperature yet.
        std::vector<int> result(temperatures.size(), 0);
        // Stack s stores previous temperatures (decreasing order)
        std::stack<int> s;

        for (int i = 0; i < temperatures.size(); ++i) {
            // If this temperature is greater than previous index's temps in the stack,
            // then calculate the time ahead (days-before-a-warmer-temp) and save the result.
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                // Temp on day i is warmer than on day 's.top()'
                int days_ahead = i - s.top();
                result[s.top()] = days_ahead;
                // This index is no longer waiting for a warmer temp, so remove from stack.
                // Since temp[s.top()] < temp[i], we know those left in the stack have temp[s.top()] >= temp[i]
                // Therefore the stack is in decreasing order of temps.
                s.pop();
            }
            // The current index hasn't seen any future temps so it still needs a value. Push onto stack.
            s.push(i);
        }
        return result;
    }
};
