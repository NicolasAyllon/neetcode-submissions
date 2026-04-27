class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyToList[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        // Get list of (value, timestamp) pairs where timestamps are in ascending order
        const auto& valueTimes = keyToList[key];

        // If there were no values for this key, or the first (value, time) pair is after the timestamp, return empty string
        if (valueTimes.empty() || timestamp < valueTimes.front().second)
            return "";

        // Use binary search to find the time T that is closest to timestamp satisfying T <= timestamp
        int left = 0;
        int right = valueTimes.size() - 1;
        string result = "";
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // Midpoint is a candidate for the key at the request timestamp
            if (valueTimes[mid].second <= timestamp) {
                result = valueTimes[mid].first;
                // Seek later times in [mid + 1, right] for time closer to timestamp
                left = mid + 1;
            }
            // Midpoint is too late (valueTimes[mid].second > timestamp)
            // Search indices [left, mid - 1]
            else {
                right = mid - 1;
            }
        }
        return result;
    }

private:
    std::unordered_map<string, vector<pair<string, int>>> keyToList;
};
