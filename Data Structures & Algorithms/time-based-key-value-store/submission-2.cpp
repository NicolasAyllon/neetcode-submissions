
using std::string;
using std::unordered_map;
using std::pair;
using std::vector;

class TimeMap {
public:
    TimeMap() {
        key_to_list.reserve(kDefaultCapacity);
    }
    
    void set(string key, string value, int timestamp) {
        key_to_list[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        // Key not found
        if (key_to_list.find(key) == key_to_list.end())
            return "";

        // Binary search in list
        const auto& value_list = key_to_list[key];
        int index = binary_search(value_list, timestamp);
        // Return the associated string (pair's .second member)
        return index == -1 ? "" : value_list[index].second;
    }

private:
    // We need a map: string -> vector<pair<int, string>>
    unordered_map<string, vector<pair<int, string>>> key_to_list;
    size_t kDefaultCapacity = 400;

    // Helper function for binary search.
    // Returns the index i of the last element
    // where v[i].first <= time_stamp
    int binary_search(const vector<pair<int, string>>& v, int target) {
        int lo = 0;
        int hi = v.size() - 1;
        int index = -1;
        // We maintain the invariant that if target is present, it will be in v[low, hi]
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (v[mid].first == target) {
                return mid;
            } else if (v[mid].first < target) {
                // target time lies in v[mid+1, hi]
                // Save this index (its associated time is less than the target)
                index = mid;
                lo = mid + 1;
            } else { // v[mid].first > target
                // target time lies in v[lo, mid-1]
                // Don't save this index (the associated time is >= target)
                hi = mid - 1;
            }
        }
        // lo > hi
        return index;
    }
};
