// Helping data structure to put the nodes in a doubly linked list
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    // Constructor
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {};
};


// Internally contains a doubly linked list of nodes to keep track of recency of usage.
// Also contains a map from key (int) -> Node*
class LRUCache {
public:
    // Constructor: 
    // Initialize the doubly linked list of nodes with sentinel nodes 'head_' and 'tail_'
    // 'head_' comes before the first element, and 'tail_' comes after the last element.
    LRUCache(int capacity) : capacity_(capacity){
        head_ = new Node(0, 0);
        tail_ = new Node(0, 0);
        head_->next = tail_;
        tail_->prev = head_;
    }
    
    int get(int key) {
        // Key not found
        if (map.find(key) == map.end()) {
            return -1;
        }
        // Use the map to get the Node for this key.
        Node* node = map[key];
        // Move the node to the head of the list (most recently used).
        list_remove(node);
        list_push_front(node);
        // Return the value
        return node->value;
    }
    
    void put(int key, int value) {
        // If the key is already in the cache, update it and move it to the front (most recently used)
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            node->value = value;
            list_remove(node);
            list_push_front(node);
        } 
        // Key is not in the cache. Create Node and push to front of list.
        else {
            Node* node = new Node(key, value);
            map[key] = node;
            list_push_front(node);
        }
        // If the list is longer than the capacity, remove the least-recently used item (at end of list).
        if (map.size() > capacity_) {
            Node* last = tail_->prev;
            map.erase(last->key);
            list_remove(last);
            delete last;
        }
    }

    // Free the dynamically allocated nodes.
    ~LRUCache() {
        // Delete all interior nodes in the list.
        Node* cur = head_->next;
        while (cur != tail_) {
            Node* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        // Delete the sentinels: head_ and tail_
        delete head_;
        delete tail_;
    }

private:
    const int capacity_;
    Node* head_;
    Node* tail_;
    // Maps key to node in the doubly linked list.
    std::unordered_map<int, Node*> map;

    // Removes NODE from the list, but does not deallocate its memory.
    void list_remove(Node* node) {
        // Rewire the nodes before and after this one to point to each other.
        Node* before = node->prev;
        Node* after = node->next;
        before->next = after;
        after->prev = before;
        // Set this node's prev and next pointers to null.
        node->prev = nullptr;
        node->next = nullptr;
    }

    // Insert NODE at the front of the list.
    void list_push_front(Node* node) {
        // Link the previous first node to this one.
        node->next = head_->next;
        node->next->prev = node;
        // Link head_ and this node.
        node->prev = head_;
        head_->next = node;
    }
};
