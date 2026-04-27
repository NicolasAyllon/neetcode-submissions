class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        // Iterate over all possible start positions
        for (int start = 0; start < n; ++start) {
            std::cout << "Starting at station " << start << '\n';
            // See if we can go around completely:
            // Fill up tank initially at 'start' station.
            int tank = 0;
            int num_visited = 0;
            // Try to advance all n stations (bringing us back the start)
            for (int i = 0; i < n; ++i) {
                int station = (start + i) % n; // Station index
                std::cout << "\t station i = " << station << ", tank = " << tank << "\n";
                // Fill up
                tank += gas[station];
                std::cout << "\t added gas " << gas[station] << " (tank = " << tank << ") \n";
                // Drive to next station in the circle
                tank -= cost[station];
                std::cout << "\t spend " << cost[station] << " to get to next station (tank = " << tank << "\n";
                if (tank >= 0) {
                    num_visited++;
                } else {
                    std::cout << "ran out of gas, can't reach next station \n";
                    break;
                }
            }
            // Did we make it through all n stations, starting from index 'start'?
            if (num_visited == n)
                return start;
        }
        // We tried all starting positions, and we could never make it around.
        return -1;
    }
};
