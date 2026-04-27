//
class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) { 
        cache_.reserve(capacity);
    }
    
    int get(int key) {
        // We'll look through the cache at the keys (.first of the pair)
        // and return the corresponding value (.second of the pair)
        for (int i = 0; i < cache_.size(); ++i) {
            if (cache_[i].first == key) {
                auto tmp = cache_[i];
                cache_.erase(cache_.begin() + i);
                cache_.push_back(tmp); // Move MRU key to the back of vector
                return tmp.second;
            }
        }
        // Key not found
        return -1;
    }
    
    void put(int key, int value) {
        // Iterate through the cache again to see if there's a matching key
        // Erase any {k, v} pair if the key already exists in the cache
        for (int i = 0; i < cache_.size(); ++i) {
            if (cache_[i].first == key) {
                cache_.erase(cache_.begin() + i);
            }
        }
        // Add the new {k, v} pair to the back of the vector (MRU element)
        cache_.push_back({key, value});
        // If the cache is over capacity, erase the least recently used element (LRU)
        // By the invariant, it's at the front of the cache vector
        if (cache_.size() > capacity_) {
            cache_.erase(cache_.begin());
        }
    }

private:
    int capacity_;
    // We maintain the invariant that the back of the vector contains the most recently used (MRU) key
    // And the front is the least recently used (LRU) key
    std::vector<std::pair<int, int>> cache_;
};
