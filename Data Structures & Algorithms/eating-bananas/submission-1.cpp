class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // The maximum possible value of k is the max number of bananas in any pile
        // - If we eat at that rate, we'll finish one pile per hour and will take as many hours as there are piles
        // The minimum possible rate k we'll consider is 1.
        // - If we eat only 1 banana per hour, it'll take us as many hours as there are bananas.
        // 
        // We can use the above min and max considered values of k, and use binary search to hone in
        // on the smallest k that allows us to finish all piles in h hours.

        int minK = std::numeric_limits<int>::max();
        int lo = 1;
        int hi = *std::max_element(piles.begin(), piles.end());

        // Invariant: the values of k we've considered are in the interval [lo, hi] inclusive
        // When this interval is empty, we'll have considered all possible values of k
        while (lo <= hi) {
            int k = lo + (hi - lo) / 2;
            int hours = hoursRequiredToEat(piles, k);
            if (hours <= h) {
                // It's possible to eat all bananas in at most h hours, so save this value of k
                minK = std::min(k, minK);
                // See if we can find a smaller of k, by searching the interval [lo, k-1]
                hi = k - 1;
            } else { // hours > h
                // Too slow, not possible to finish in h hours, so try eating faster
                // Search the interval [k+1, hi]
                lo = k + 1;
            }
        }
        // The unsearched interval is empty [] since lo > hi
        return minK;
    }

private:
    // The number of hours required to eat the piles of bananas at rate k bananas per hour
    int hoursRequiredToEat(const vector<int>& piles, int k) {
        int totalHours = 0;
        for (int bananas : piles) {
            // Shift point (k - 1, 1) on y = x / k to (0, 1) which is achieved by adding k - 1 to the argument.
            int hours = (bananas + k - 1) / k; 
            totalHours += hours;
        }
        return totalHours;
    }
};
