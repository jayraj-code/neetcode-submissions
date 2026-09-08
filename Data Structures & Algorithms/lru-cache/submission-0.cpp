class LRUCache {
private: 
    struct Node{
        int key; 
        int val; 
        Node* prev; 
        Node* next; 

        Node(int key , int val)
        {
            this->key = key; 
            this->val = val; 
            prev = nullptr; 
            next = nullptr; 
        }
    };

    int capacity; 
    unordered_map<int , Node*> map; 
    Node* dummyhead; 
    Node* dummytail; 

    void removeNode(Node* node)
    {
        node->prev->next = node->next; 
        node->next->prev = node->prev; 
    }

    void addToFront(Node* node)
    {
        node->next = dummyhead->next; 
        dummyhead->next->prev = node; 
        node->prev = dummyhead; 
        dummyhead->next = node; 
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity; 
        dummyhead = new Node(0, 0); 
        dummytail = new Node(0, 0); 
        dummyhead->next = dummytail; 
        dummytail->prev = dummyhead; 
    }
    
    int get(int key) {
        if (!map.count(key))
        {
            return -1; 
        }

        Node* node = map[key]; 
        removeNode(node); 
        addToFront(node); 

        return node->val; 
    
    }
    
    void put(int key, int value) {
        if (map.count(key))
        {
            Node* node = map[key]; 
            removeNode(node);
            addToFront(node); 

            node->val = value; 
            return; 
        }

        if (map.size() == capacity)
        {
            Node* lru = dummytail->prev; 
            int key = lru->key; 
            map.erase(key); 
            removeNode(lru); 
            delete lru; 
        }

        Node* newNode = new Node(key, value); 
        addToFront(newNode); 
        map[key] = newNode; 
        
    }
};
