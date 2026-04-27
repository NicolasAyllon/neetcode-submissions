class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {
        map.reserve(capacity);
        // 'accessed_list' is initialized to an empty list by default.
    }
    
    int get(int key) {
        // Key not found
        if (map.find(key) == map.end())
            return -1;
        // Key is present in the map. It MUST be in the list.
        // Move to front of accessed_list.
        auto it_list = std::find(accessed_list.begin(), accessed_list.end(), key);
        accessed_list.erase(it_list);
        accessed_list.push_front(key);

        // Otherwise return the value for this key.
        return map[key];
    }
    
    void put(int key, int value) {
        // If the key is already in the map, update it.
        // Or if it's not in the map, add the key->val mapping.
        map[key] = value;

        // If this key is already in the list, erase it.
        // Add it to the front of the list, always.
        auto it_map = map.find(key);

        auto it_list = std::find(accessed_list.begin(), accessed_list.end(), key);
        if (it_list != accessed_list.end()) {
            accessed_list.erase(it_list);
        }
        accessed_list.push_front(key);

        // If the cache is above capacity, remove the least-recently-used element from the map & list.
        if (map.size() > capacity_) {
            int lru_key = accessed_list.back();
            accessed_list.pop_back();
            map.erase(lru_key);
        }
    }
private:
    const int capacity_;
    // map int (key) -> int (value)
    std::unordered_map<int, int> map;

    // List of keys by order of access:
    // Head is most-recently used; tail is least-recently used.
    // On any access, move the key to the head of the list.
    std::list<int> accessed_list;
};
