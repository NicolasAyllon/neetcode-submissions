class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Let 'tank' hold the integral gas[] - cost[] to get from start -> end
        // That is: the cumulative sum (gas[i] - cost[i]) for i in [start, end) == [start, prev(end)]
        
        int start = gas.size() - 1;
        int end = 0;
        // cumulative sum (gas[i] - cost[i]) for i in [start, end) == [start, prev(end)]
        int tank = gas[start] - cost[start];

        while (start > end) {
            if (tank < 0) {
                start--;
                tank += gas[start] - cost[start];
                // Maintain loop invariant: tank = cumulative_sum[start, prev(end)]
            } else {
                tank += gas[end] - cost[end];
                end++;
                // Maintain loop invariant: tank = cumulative_sum[start, prev(end)]
            }
        }
        // start == end
        return tank >= 0 ? start : -1;
    }
};
