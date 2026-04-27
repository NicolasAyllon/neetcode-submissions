
using std::string;
using std::unordered_map;
using std::map;

class TimeMap {
public:
    // Map each string to a (sorted) map from time -> values
    unordered_map<string, map<int, string>> string_to_map;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        // Obtain the map for KEY and add (TIMESTAMP, VALUE) to the map.
        string_to_map[key].insert(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        // upper_bound returns an iterator to othe first element GREATER than the key.
        // Since a map sorts by the key (timestamp) this will return the first element
        // with timestamp > TIMESTAMP (parameter). We'll return the previous element
        // if there is one (since it is the one with greatest timestamp <= TIMESTAMP)
        auto it = string_to_map[key].upper_bound(timestamp);
        return it == string_to_map[key].begin() ? "" : std::prev(it)->second; 
    }
};
