// Last approach: use built-in data structures from the standard library
class LRUCache {
private:
    // Maximum number of items that can be in the cache
    int capacity_;
    // Maps keys to pairs of (value, iterator to the key in the list)
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
    // List of keys: front is most recently used; back is least recently used.
    std::list<int> order;
public:
    LRUCache(int capacity) : capacity_(capacity) {
        cache.reserve(capacity_);
    }
    
    int get(int key) {
        // Key not in map
        if (cache.find(key) == cache.end())
            return -1;
        // Key in map
        int val = cache[key].first;
        // Move key to the front of the list (most recently used).
        order.erase(cache[key].second);
        order.push_front(key);
        // Update the corresponding pair's iterator (second element) to be the iterator at the front of the list.
        cache[key].second = order.begin();
        return val;
    }
    
    void put(int key, int value) {
        // If the key is already in the map, first erase it from the list.
        if (cache.find(key) != cache.end()) {
            // Move key to front of list & update value (first) & iterator (second)
            order.erase(cache[key].second);
        }
        // Move key to the front of the list (always)
        order.push_front(key);
        cache[key] = {value, order.begin()};

        // If the number of items in the cache exceeds the capacity, 
        // remove the least recently used item from list and map ("cache")
        if (cache.size() > capacity_) {
            int lru_key = order.back();
            order.pop_back();
            cache.erase(lru_key);
        }
    }
};
