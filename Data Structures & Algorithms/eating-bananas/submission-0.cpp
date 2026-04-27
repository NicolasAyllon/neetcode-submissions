class Solution {
public:
    // Approach:
    // The number of hours h, is fixed.
    // Suppose we pick eating rate k.
    // Then, to eat pile[i], which has, say b, bananas
    //
    // The number of hours it takes is:
    //   ROUNDUP(n, k) = (n + k - 1) / k
    //                 = (b + k - 1) / k
    //
    // If m is the max value in pile[], 
    // then the fastest rate we should consider is m.
    // The slowest rate we can consider is 1.
    // 
    // If we do binary search to in the interval [1, m]
    // then calculate the number of hours we actually took to eat
    // all the bananas, we can find the required minimum rate
    // in O(n * log(m)), since there are log(m) iterations of binary search
    // and each iteration loops over the array of n elements.
    int minEatingSpeed(vector<int>& piles, int h) {
        // Get max element in piles.
        int m = *std::max_element(piles.begin(), piles.end());

        // Binary search
        int lo = 1;
        int hi = m;
        int k = hi; // Smallest eating rate seen so far.
        while (lo <= hi) {
            // Pick a per-hour eating rate in the middle of [lo, hi]
            int mid = lo + (hi - lo) / 2;
            // This eating rate will consume all bananas in h hours.
            // Update min_eating_rate if this one is smaller.
            if (totalHoursTaken(piles, mid) <= h) {
                // Record this eating rate.
                k = mid;
                // See if we can find a smaller eating rate.
                hi = k - 1;
            } 
            // This eating rate isn't fast enough. Try faster in [mid + 1, hi]
            else {
                lo = mid + 1;
            }
        }
        return k;
    }

private:
// Returns the number of hours needed to eat all bananas in piles[] 
// if the eating rate is k bananas per hour.
    int totalHoursTaken(const vector<int>& piles, const int k) {
        int hours = 0;
        for (int bananas : piles) {
            hours += (bananas + k - 1) / k; // == ROUNDUP(bananas, k)
        }
        return hours;
    }
};
