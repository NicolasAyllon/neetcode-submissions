// Approach 2: Doubly linked list
// - use a hashmap to lookup: key -> node in doubly linked list
// - always move the accessed node to the front of the linked list
//   (So we maintain the invariant that front = MRU, and back = LRU)
struct Node {
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key_in = 0, int value_in = 0, Node* prev_in = nullptr, Node* next_in = nullptr) 
        : key(key_in), value(value_in), prev(prev_in), next(next_in) {}

    std::string toString() {
        // return std::format("Node[key={}, value={}, prev={}, next={}]", key, value, prev, next);
        std::stringstream ss;
        ss << "Node[" << "key=" << key << ", value=" << value << ", prev=" << prev << ", next=" << next << "]";
        return ss.str(); 
    }
};

class LRUCache {
public:
    LRUCache(int capacity) : size_(0), capacity_(capacity) {
        head_ = new Node(); // head.prev = nullptr
        tail_ = new Node(); // tail.next = nullptr
        head_->next = tail_;
        tail_->prev = head_;
    }

    ~LRUCache() {
        // Free all the nodes in the list
        Node* cur = head_;
        while (cur != nullptr) {
            Node* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }
    
    int get(int key) {
        std::cout << "get(" << key << ")\n";
        // If the key is in the map, get the corresponding node
        Node* node = nullptr;
        auto it = key_to_node_.find(key);
        if (it != key_to_node_.end()) {
            node = it->second;
            // Remove from middle of list
            node->prev->next = node->next;
            node->next->prev = node->prev;
            // Insert at the head (MRU)
            Node* first = head_->next;
            first->prev = node;
            node->next = first;
            head_->next = node;
            node->prev = head_;
        }
        printCache();
        return node ? node->value : -1;
    }
    
    void put(int key, int value) {
        std::cout << "put(" << key << ", " << value << ")\n";
        // If the key is in the map, get the corresponding node
        Node* node = nullptr;
        auto it = key_to_node_.find(key);
        if (it != key_to_node_.end()) {
            // Remove from middle of list
            node = it->second;
            node->prev->next = node->next;
            node->next->prev = node->prev;
        } else {
            // If not in the map, create new node, put in map, and update the size of the cache
            node = new Node();
            key_to_node_[key] = node;
            size_++;
        }

        // Update node
        node->key = key;
        node->value = value;

        // Insert at head of list
        Node* first = head_->next;
        first->prev = node;
        node->next = first;
        head_->next = node;
        node->prev = head_;

        // If the number of nodes is bigger than the capacity
        // remove the least recently used node (LRU at the tail) from list and map
        if (size_ > capacity_) {
            Node* last = tail_->prev;
            // Remove from map
            key_to_node_.erase(last->key);
            // Remove from list
            last->prev->next = last->next;
            last->next->prev = last->prev;
            delete last;
            size_--;
        }
        printCache();
    }

    void printCache() {
        std::cout << "cache:\n";
        for (const auto& [key, node] : key_to_node_) {
            std::cout << key << " -> " << node << "[" << node->toString() << "]\n";
        }
        std::cout << "list:\n";
        std::cout << "HEAD";
        for (Node* cur = head_->next; cur != tail_; cur = cur->next) {
            std::cout << " <-> " << cur->value;
        }
        std::cout << " <-> TAIL\n";
    }



private:
    int capacity_;
    int size_;
    // To make the implementation easier, we'll use placeholder nodes for the head and tail.
    // The placeholder head comes before the first item in the list, and the placeholder tail
    // comes after the last item in the list.
    Node* head_;
    Node* tail_;
    // Hashmap to get the node in the doubly linked list with the corresponding key
    std::unordered_map<int, Node*> key_to_node_;
};
