class LRUCache:
    # Brute force
    def __init__(self, capacity: int):
        self.cache = [] # list of (key, value) pairs
        self.capacity = capacity

    def get(self, key: int) -> int:
        # Iterate through the cache and see if we can find
        # an element with the key
        for (k, v) in self.cache:
            if k == key:
                # Move element to front (MRU)
                self.cache.remove((k, v))
                self.cache.insert(0, (k, v))
                return v

        # Not found
        return -1


    def put(self, key: int, value: int) -> None:
        # Iterate through the cache and remove any existing entry for the given key
        for (k, v) in self.cache:
            if k == key:
                self.cache.remove((k, v))
        # Insert at front of list (MRU) with the new value
        self.cache.insert(0, (key, value))
        # If the list has more items than its capacity remove the least recently used item (LRU) at the back of list
        if len(self.cache) > self.capacity:
            self.cache.pop()
        
