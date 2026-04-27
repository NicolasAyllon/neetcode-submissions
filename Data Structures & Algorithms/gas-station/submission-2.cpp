class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // If the total amount of gas is less than the total cost,
        // We can't make it around
        if (std::accumulate(gas.begin(),  gas.end(), 0) <
            std::accumulate(cost.begin(), cost.end(), 0))
            return -1;
        
        // Otherwise, we'll start at station i = 0,
        // and see if we run out of gas
        int tank = 0;
        int start_idx = 0;

        for (int i = 0; i < gas.size(); ++i) {
            tank += gas[i];
            tank -= cost[i];
            // Since the integral gas[] - cost[] 
            // on the interval [start_idx, i]
            // is positive (by loop invariant)
            // where (gas[i] - cost[i]) >= 0
            // ...
            if (tank < 0) {
                tank = 0;
                start_idx = i + 1;
            }
        }
        return start_idx;
    }
};
