class LRUCache:
    # Optimal approach with doubly linked list to store the (key, value) nodes in order
    # of most-recently-used (at front) to least-recently-used (at back)
    def __init__(self, capacity: int):
        self.head = Node(0, 0) # placeholder before the first element
        self.tail = Node(0, 0) # placeholder after the last element
        self.head.next = self.tail # connect head and tail
        self.tail.prev = self.head
        self.capacity = capacity
        self.keyToNodeMap = {} # hashmap from keys to nodes in the doubly linked list

    def get(self, key: int) -> int:
        # Use the map to see if the key is in the cache
        node = self.keyToNodeMap.get(key)
        if node:
            # Move this node to the front of the list (MRU)
            self.list_remove(node)
            self.list_push_front(node)
            return node.value

        # Not found
        return -1

    def put(self, key: int, value: int) -> None:
        # Use the map to see if the key is in the cache, and remove it first
        node = self.keyToNodeMap.get(key)
        if node:
            self.list_remove(node)
            node.value = value # key stays the same
        else:
            node = Node(key, value)

        # Put the new (key, node) pair in the map and insert at front of list
        self.keyToNodeMap[key] = node
        self.list_push_front(node)

        # If there are more nodes than we have capacity, remove the least recently used element
        # both from the list and from the map
        if len(self.keyToNodeMap) > self.capacity:
            last = self.tail.prev
            self.keyToNodeMap.pop(last.key)
            self.list_remove(last)
        
    def list_remove(self, node: Node):
        node.prev.next = node.next
        node.next.prev = node.prev

    def list_push_front(self, node: Node):
        first = self.head.next
        # Insert before first
        self.head.next = node
        node.prev = self.head
        node.next = first
        first.prev = node
        
class Node:
    def __init__(self, key: int, value: int):
        self.key, self.value = key, value
        self.prev = self.next = None
