class Node:
    def __init__(self, key: int, value: int):
        self.key, self.val = key, value
        self.prev = self.next = None
    
class LRUCache:

    def __init__(self, capacity: int):
        # Initialize capacity and hashmap/dictionary
        self.capacity = capacity
        self.cache = {}
        # Initialize doubly linked list (head and tail are sentinels)
        self.head, self.tail = Node(0, 0), Node(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head

    # Helping functions
    # Removes the node from the list
    def list_remove(self, node: Node) -> None:
        node.prev.next = node.next
        node.next.prev = node.prev

    def list_push_front(self, node: Node):
        # Identify the nodes before and after the node when it moves to the front
        prev, next = self.head, self.head.next
        # Link the node to its neighbors. Then, link the neighbors to the node.
        node.prev, node.next = prev, next
        prev.next = next.prev = node

    def get(self, key: int) -> int:
        if key in self.cache:
            self.list_remove(self.cache[key])
            self.list_push_front(self.cache[key])
            return self.cache[key].val
        # Key not found in cache
        return -1

    def put(self, key: int, value: int) -> None:
        # First remove the Node from the list, if present
        if key in self.cache:
            self.list_remove(self.cache[key])
        
        # Always: add key->Node to map, and push to front of list
        self.cache[key] = Node(key, value)
        self.list_push_front(self.cache[key])
        
        # If the cache is over capacity, evict the least recently used item, which is at the end of the list
        if len(self.cache) > self.capacity:
            lru = self.tail.prev
            self.list_remove(lru)
            self.cache.pop(lru.key)

        
